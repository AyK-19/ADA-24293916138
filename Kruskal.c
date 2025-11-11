#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 21

typedef struct Edge {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_NODES];
int edge_count = 0;

int find_set(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find_set(parent[i]);
}

void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) parent[root_i] = root_j;
}

int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal() {
    int i, cost = 0, mst_edges = 0;
    qsort(edges, edge_count, sizeof(Edge), compare_edges);
    for (i = 0; i < MAX_NODES; i++) parent[i] = i;

    printf("Kruskal's MST Edges:\n");
    for (i = 0; i < edge_count; i++) {
        if (find_set(edges[i].u) != find_set(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
            cost += edges[i].weight;
            mst_edges++;
            printf("(%d, %d) Weight: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            if (mst_edges == MAX_NODES - 1) break;
        }
    }
    printf("Total Kruskal's MST Cost: %d\n", cost);
}

void add_edge(int u, int v, int w) {
    edges[edge_count++] = (Edge){u, v, w};
}

int main() {
    add_edge(0, 1, 4); add_edge(0, 7, 8);
    add_edge(1, 2, 8); add_edge(1, 7, 11);
    add_edge(2, 3, 7); add_edge(2, 8, 2); add_edge(2, 5, 4);
    add_edge(3, 4, 9); add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1); add_edge(6, 8, 6);
    add_edge(7, 8, 7);
    kruskal();
    return 0;
}