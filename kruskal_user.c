#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort, to sort edges by weight
int comparator(const void *p1, const void *p2)
{
    // Cast the void pointers to the appropriate type
    const int(*edge1)[3] = p1;
    const int(*edge2)[3] = p2;
    // Return the difference between the weights of the edges
    return (*edge1)[2] - (*edge2)[2];
}

// Function to initialize the parent and rank arrays
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // Each node is its own parent
        rank[i] = 0;   // Initialize rank as 0
    }
}

// Function to find the parent of a node with path compression
int findParent(int parent[], int node)
{
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]); // Path compression
    return parent[node];
}

// Function to union two sets by rank
void unionSets(int u, int v, int parent[], int rank[], int n)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    // Union by rank
    if (rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalAlgorithm(int numEdges, int edges[][3], int numVertices)
{
    // Sort edges by weight
    qsort(edges, numEdges, sizeof(edges[0]), comparator);
    // Arrays to store the parent and rank of each node
    int parent[numVertices];
    int rank[numVertices];
    // Initialize the parent and rank arrays
    makeSet(parent, rank, numVertices);
    int minCost = 0; // Variable to store the total weight of the MST
    printf("Edges in the Minimum Spanning Tree:\n");

    // Iterate through the sorted edges
    for (int i = 0; i < numEdges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);
        // If u and v are in different sets, include this edge in the MST
        if (rootU != rootV)
        {
            unionSets(rootU, rootV, parent, rank, numVertices);
            minCost += weight;
            printf("%d ----- %d == %d\n", u, v, weight);
        }
    }
    // Print the total weight of the MST
    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

// Main function for User Input at Runtime
int main()
{
    // user input at compile time
    int numVertices, numEdges;
    // Get the number of vertices and edges from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    // Array to store the edges
    int edges[numEdges][3];
    // Get the edges from the user
    printf("Enter the edges (u v weight) one by one:\n");
    for (int i = 0; i < numEdges; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    kruskalAlgorithm(numEdges, edges, numVertices);
    return 0;
}

/*
// Main function for Compile time
int main()
{
    int edges[5][3] = {{0, 1, 8}, {0, 2, 11}, {0, 3, 4}, {1, 3, 10}, {2, 3, 2}};
    int numVertices = 4;
    int numEdges = 5;
    // Run Kruskal's algorithm
    kruskalAlgorithm(numEdges, edges, numVertices);
    return 0;
}
*/
