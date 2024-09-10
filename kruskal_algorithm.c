//Kruskal using Runtime input 
#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort edges by their weight (ascending order)
int comparator(const void *p1, const void *p2){
    const int(*edge1)[3] = p1;
    const int(*edge2)[3] = p2;
    // Compare the third element (weight) of the edges
    return (*edge1)[2] - (*edge2)[2];
}

// Function to initialize parent and rank arrays for each node
void makeSet(int parent[], int rank[], int n){
    for (int i = 0; i < n; i++){
        parent[i] = i;  // Initially, each node is its own parent
        rank[i] = 0;    // Initial rank of each node is 0
    }
}

// Function to find the parent of a node using path compression
int findParent(int parent[], int node){
    // Recursively find the root parent, and apply path compression
    if (parent[node] != node){
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

// Function to unite two sets by rank
void unionSets(int u, int v, int parent[], int rank[], int n){
    // Find root of both nodes
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    // Attach smaller rank tree under the root of the higher rank tree
    if (rank[rootU] < rank[rootV]){
        parent[rootU] = rootV;  // Attach rootU's tree to rootV
    }
    else if (rank[rootU] > rank[rootV]){
        parent[rootV] = rootU;  // Attach rootV's tree to rootU
    }
    else{
        // If ranks are the same, attach and increase rank of the new root
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalAlgorithm(int numEdges, int edges[][3], int numVertices){
    // Sort the edges by their weight using qsort
    qsort(edges, numEdges, sizeof(edges[0]), comparator);
    int parent[numVertices];  // Array to store the parent of each node
    int rank[numVertices];    // Array to store rank of each node
    makeSet(parent, rank, numVertices);  // Initialize parent and rank arrays
    int minCost = 0;  // Variable to store the total cost of the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    // Process each edge in increasing order of weight
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];      // Node 1 of the edge
        int v = edges[i][1];      // Node 2 of the edge
        int weight = edges[i][2]; // Weight of the edge
        // Find the root parent of both nodes u and v
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);
        // If u and v belong to different sets, include this edge in the MST
        if (rootU != rootV) {
            unionSets(rootU, rootV, parent, rank, numVertices);
            minCost += weight;
            printf("%d ---- %d == %d\n", u, v, weight); 
        }
    }
    // Print the total minimum cost of the spanning tree
    printf("Minimum Cost of Spanning Tree is : %d\n", minCost);
}

int main(){
    // Example input: 5 edges, 4 vertices
    int edges[5][3] = {
        {0, 1, 8},  // Edge from vertex 0 to 1 with weight 8
        {0, 2, 11}, // Edge from vertex 0 to 2 with weight 11
        {0, 3, 4},  // Edge from vertex 0 to 3 with weight 4
        {1, 3, 10}, // Edge from vertex 1 to 3 with weight 10
        {2, 3, 2}   // Edge from vertex 2 to 3 with weight 2
    };
    int numVertices = 4; 
    int numEdges = 5;
    kruskalAlgorithm(numEdges, edges, numVertices);
    return 0;
}
