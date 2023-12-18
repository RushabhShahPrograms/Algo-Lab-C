/* 
    Name: Shah Rushabh Rupambhai
    Roll number: 202363006
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int n; // Number of vertices
int graph[MAX][MAX];  // Graph matrix
int dist[MAX];  // Distance array
int visited[MAX];

void dijkstra(int src) {
  // Initialize arrays for distances and visited nodes
    int visited_dijkstra[MAX] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = -1;
    }
    // Set the source node distance to 0
    dist[src] = 0;
    // Repeat this block until all nodes are visited
    for (int i = 0; i < n - 1; i++) {
      // Find the next unvisited node with the smallest distance
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited_dijkstra[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        // Mark the node as visited
        visited_dijkstra[u] = 1;
        // Iterate through all neighboring nodes of the current node
        for (int v = 0; v < n; v++) {
            // If the edge exists and the neighboring node is unvisited
            if (graph[u][v] != INT_MAX && !visited_dijkstra[v] && dist[u] + graph[u][v] < dist[v]) {
                // Update the neighboring node distance and set the current node as its predecessor

                dist[v] = dist[u] + graph[u][v];
                visited[v] = u;
            }
        }
    }
}

void printPath(int j, int src) {
  // If current node is source
    if (visited[j] == -1) {
        printf("%d", src);
        return;
    }
    // Recursively call printPath to get path to the parent of current node
    printPath(visited[j], src);
    // Print the current node to form the path
    printf(" -> %d", j);
}

void prim() {
    int parent[n];
    int key[n];
    int visited_prim[MAX] = {0};
    // Set all keys to infinity and parent of each node to -1
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    // Repeat until all nodes are included in the MST
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        // Find node with minimum key that is not included in the MST
        for (int j = 0; j < n; j++) {
            if (!visited_prim[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }
        // Add node to the MST
        visited_prim[u] = 1;
        // Update key values of the adjacent nodes
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX && !visited_prim[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print edges of the MST
    for (int i = 1; i < n; i++) {
        printf("%d -> %d\n", parent[i], i);
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'N') {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = c - '0';
            }
        }
    }
    printf("Enter the source vertex: ");
    int src;
    scanf("%d", &src);
    dijkstra(src);
    printf("Distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\nShortest paths from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (i == src) {
            continue;
        }
        printf("%d -> %d: ", src, i);
        if (dist[i] == INT_MAX) {
            printf("No path\n");
        } else {
            printPath(i, src);
            printf("\n");
        }
    }
    printf("Maximum spanning tree:\n");
    prim();
    return 0;
}


/*
Input 1:
Enter the number of vertices: 7
Enter the adjacency matrix:
N 5 N 7 N N N
5 N 7 N 3 N N
N 7 N 4 N N N
7 N 4 N N 6 1
N 3 N N N 2 N
N N N 6 2 N 8
N N N 1 N 8 N
Enter the source vertex: 0

Output 1:
Distances from vertex 0:
0 5 11 7 8 10 8
Shortest paths from vertex 0:
0 -> 1: 0 -> 1
0 -> 2: 0 -> 3 -> 2
0 -> 3: 0 -> 3
0 -> 4: 0 -> 1 -> 4
0 -> 5: 0 -> 1 -> 4 -> 5
0 -> 6: 0 -> 3 -> 6
Maximum spanning tree:
0 -> 1
3 -> 2
5 -> 3
1 -> 4
4 -> 5
3 -> 6
*/

/*
Input 2:
Enter the number of vertices: 5
Enter the adjacency matrix:
N 2 N 6 N
2 N 3 N N
N 3 N 4 N
6 N 4 N 1
N N N 1 N
Enter the source vertex: 0

Output 2:
Distances from vertex 0:
0 2 5 6 7
Shortest paths from vertex 0:
0 -> 1: 0 -> 1
0 -> 2: 0 -> 1 -> 2
0 -> 3: 0 -> 3
0 -> 4: 0 -> 3 -> 4
Maximum spanning tree:
0 -> 1
1 -> 2
2 -> 3
3 -> 4
*/

/*
Input 3:
Enter the number of vertices: 4
Enter the adjacency matrix:
N 1 3 N
1 N N 2
3 N N 4
N 2 4 N
Enter the source vertex: 0

Output 3:
Distances from vertex 0:
0 1 3 3
Shortest paths from vertex 0:
0 -> 1: 0 -> 1
0 -> 2: 0 -> 2
0 -> 3: 0 -> 1 -> 3
Maximum spanning tree:
0 -> 1
0 -> 2
1 -> 3
*/
