#ifndef ISBIPARTITE_H
#define ISBIPARTITE_H

#include "reseacher.h"

bool isBipartiteUtil(int **graph, int V, int *color, int v, int currColor) {
    color[v] = currColor;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(graph, V, color, i, 1 - currColor)) {
                    return false;
                }
            } else if (color[i] == currColor) {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int **graph, int V)
 {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = -1; // Inicialmente, nenhum vértice está colorido
    }

    bool result = true;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartiteUtil(graph, V, color, i, 0)) {
                result = false;
                break;
            }
        }
    }

    free(color);
    return result;
}

#endif