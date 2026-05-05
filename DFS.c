#include <stdio.h>
#include <stdlib.h>

#define MAX 10   // maximum number of vertices

// ----------- STRUCTURE FOR LINKED LIST NODE -----------
struct Node {
    int vertex;            // stores the connected vertex
    struct Node* next;     // pointer to next node in list
};

// ----------- GRAPH REPRESENTATION -----------
struct Node* adjList[MAX];   // array of linked lists (adjacency list)
int visited[MAX];            // array to track visited nodes

// ----------- CREATE NEW NODE -----------
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;   // store vertex number
    newNode->next = NULL;       // next is NULL initially
    return newNode;
}

// ----------- ADD EDGE FUNCTION -----------
void addEdge(int source, int destination) {
    // Add edge from source → destination

    struct Node* newNode = createNode(destination);
    newNode->next = adjList[source];   // insert at beginning
    adjList[source] = newNode;

    // Since graph is undirected, also add destination → source
    newNode = createNode(source);
    newNode->next = adjList[destination];
    adjList[destination] = newNode;
}

// ----------- DFS FUNCTION -----------
void DFS(int vertex) {
    // Step 1: mark current node as visited
    visited[vertex] = 1;

    // Step 2: print the current vertex
    printf("%d ", vertex);

    // Step 3: go through all neighbours of this vertex
    struct Node* temp = adjList[vertex];

    while (temp != NULL) {
        int adjacentVertex = temp->vertex;

        // Step 4: if neighbour is not visited, go deeper
        if (!visited[adjacentVertex]) {
            DFS(adjacentVertex);   // recursive call (go deep)
        }

        temp = temp->next;  // move to next neighbour
    }

    // Step 5: when no neighbours left → automatically backtrack
}

// ----------- MAIN FUNCTION -----------
int main() {
    int i;

    // Step 0: initialize graph
    for (i = 0; i < MAX; i++) {
        adjList[i] = NULL;   // no edges initially
        visited[i] = 0;      // no node is visited
    }

    // Create graph (example)
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    // Run DFS starting from node 0
    printf("DFS Traversal: ");
    DFS(0);

    return 0;
}