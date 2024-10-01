#ifndef ADDEDGE_H
#define ADDEDGE_H

void addEdge(int **graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}


void DFS(int **graph, int V, int *visited, int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, V, visited, i);
        }
    }
}


#endif