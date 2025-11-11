#include <stdio.h>
#include <limits.h>

#define V 9 // Number of vertices

int graph[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
};

int min_key(int key[], int mst_set[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prim() {
    int parent[V];
    int key[V];
    int mst_set[V];
    int i, count, u, v;

    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < V - 1; count++) {
        u = min_key(key, mst_set);
        mst_set[u] = 1;

        for (v = 0; v < V; v++) {
            if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    int cost = 0;
    printf("Prim's MST Edges:\n");
    for (i = 1; i < V; i++) {
        printf("(%d, %d) Weight: %d\n", parent[i], i, graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Total Prim's MST Cost: %d\n", cost);
}

int main() {
    prim();
    return 0;
}
