#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Create a queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an element
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Structure for an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure for an adjacency list
typedef struct AdjList {
    struct AdjListNode* head;
} AdjList;

// Structure for a graph
typedef struct Graph {
    int V;
    struct AdjList* array;
} Graph;

// Create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Breadth-first search traversal of the graph
void BFS(Graph* graph, int startVertex) {
    // Mark all vertices as not visited
    int* visited = (int*)calloc(graph->V, sizeof(int));

    // Create a queue for BFS
    Queue* queue = createQueue(graph->V);

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it
        // as visited and enqueue it
        AdjListNode* adjNode = graph->array[currentVertex].head;
        while (adjNode != NULL) {
            int adjVertex = adjNode->dest;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            adjNode = adjNode->next;
        }
    }

    free(visited);
}

int main() {
    int V, E, i;
    int src, dest;

    // Read the number of vertices and edges from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Create a graph
    Graph* graph = createGraph(V);

    // Read edges from the user and add them to the graph
    printf("Enter the edges (source destination):\n");
    for (i = 0; i < E; ++i) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Read the starting vertex for BFS from the user
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Search Traversal (starting from vertex %d): ", startVertex);
    BFS(graph, startVertex);
    printf("\n");

    return 0;
}
