#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Adjacency List Node
struct Node {
    int vertex;
    struct Node* next;
};

// Global variables to simplify function calls
struct Node* adjList[MAX];
int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n; // Number of vertices

// Function to create a new list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to both Matrix and List
void addEdge(int s, int d) {
    // 1. Update Adjacency Matrix
    adjMatrix[s][d] = 1;
    adjMatrix[d][s] = 1; // Remove this line for directed graph

    // 2. Update Adjacency List
    struct Node* newNode = createNode(d);
    newNode->next = adjList[s];
    adjList[s] = newNode;

    // Remove below block for directed graph
    newNode = createNode(s);
    newNode->next = adjList[d];
    adjList[d] = newNode;
}

// BFS Implementation
void bfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited
    
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;
    
    printf("\nBFS Traversal: ");
    
    while (front <= rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        
        // Check all adjacent vertices using Matrix for simplicity
        for (int i = 0; i < n; i++) {
            if (adjMatrix[curr][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Recursive Function
void dfsRecursive(int u) {
    printf("%d ", u);
    visited[u] = 1;
    
    for (int i = 0; i < n; i++) {
        if (adjMatrix[u][i] == 1 && !visited[i]) {
            dfsRecursive(i);
        }
    }
}

void dfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited
    printf("DFS Traversal: ");
    dfsRecursive(start);
    printf("\n");
}

void printRepresentations() {
    printf("\n--- Adjacency Matrix ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Adjacency List ---\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d:", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int edges, u, v, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    // Initialize structures
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < n; j++) adjMatrix[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printRepresentations();

    printf("\nEnter starting node for traversals: ");
    scanf("%d", &start);

    bfs(start);
    dfs(start);

    return 0;
}