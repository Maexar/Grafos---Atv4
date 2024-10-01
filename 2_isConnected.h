#ifndef ISCONNECTED_H
#define ISCONNECTED_H

#include "reseacher.h"


bool isConnected(int **graph, int V) {
    int *visited = (int *)calloc(V, sizeof(int));
    int startVertex = -1;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                startVertex = i;
                break;
            }
        }
        if (startVertex != -1) break;
    }

    if (startVertex == -1) {
        free(visited);
        return false;
    }

    DFS(graph, V, visited, startVertex);

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

#endif