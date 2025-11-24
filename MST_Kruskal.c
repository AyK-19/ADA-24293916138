#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

int parent[10]; // Array for Union-Find

// Find set of vertex i
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    // Example Graph: 5 vertices (0 to 4)
    // Edge list: {u, v, weight}
    struct Edge edges[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };
    int n_edges = 7;
    int n_vertices = 5;

    // Initialize parent array
    for (int i = 0; i < n_vertices; i++) parent[i] = i;

    // Step 1: Sort edges by weight
    qsort(edges, n_edges, sizeof(edges[0]), compare);

    printf("Edges in MST (Kruskal's):\n");
    int mst_weight = 0;

    for (int i = 0; i < n_edges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Step 2: Check if adding edge creates a cycle
        if (find(u) != find(v)) {
            printf("%d - %d: %d\n", u, v, edges[i].weight);
            mst_weight += edges[i].weight;
            unionSets(u, v);
        }
    }
    printf("Total Cost: %d\n", mst_weight);
    return 0;
}