#ifndef ISHAMILTONIAN_H
#define ISHAMILTONIAN_H

#include "reseacher.h"

bool isHamiltonianUtil(int **graph, int V, int path[], int pos) {
    if (pos == V) {
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    for (int v = 1; v < V; v++) {
        bool alreadyInPath = false;
        for (int i = 0; i < pos; i++) {
            if (path[i] == v) {
                alreadyInPath = true;
                break;
            }
        }
        if (alreadyInPath || graph[path[pos - 1]][v] == 0) {
            continue;
        }

        path[pos] = v;
        if (isHamiltonianUtil(graph, V, path, pos + 1)) {
            return true;
        }
        path[pos] = -1;
    }
    return false;
}

bool isHamiltonian(int **graph, int V) {
    int *path = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;
    bool result = isHamiltonianUtil(graph, V, path, 1);
    free(path);
    return result;
}

#endif
