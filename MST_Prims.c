#include <stdio.h>
#include <limits.h> // For INT_MAX

#define V 5 // Number of vertices

int main() {
    // Adjacency Matrix representing the graph
    // 0 means no edge exists
    int G[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0}; // Track visited nodes
    int no_edge = 0;      // Number of edges in MST

    selected[0] = 1;      // Start with first node
    int total_weight = 0;

    printf("Edges in MST (Prim's):\n");

    // Loop until we have V-1 edges
    while (no_edge < V - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;

        // Check every visited node (i) against every unvisited node (j)
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { // If edge exists and j not visited
                        if (G[i][j] < min) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        total_weight += min;
        selected[y] = 1; // Mark node y as visited
        no_edge++;
    }

    printf("Total Cost: %d\n", total_weight);
    return 0;
}