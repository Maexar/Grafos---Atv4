#ifndef GRAPHMATCH_H
#define GRAPHMATCH_H

#include "reseacher.h"

// Encontra o emparelhamento máximo em um grafo bipartido
int maxBipartiteMatching(int **graph, int V) {
    int *matchR = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        matchR[i] = -1;
    }

    int result = 0;
    for (int u = 0; u < V; u++) {
        bool *seen = (bool *)calloc(V, sizeof(bool));
        if (bpm(graph, u, seen, matchR, V)) {
            result++;
        }
        free(seen);
    }

    printf("Maximum Bipartite Matching: %d\n", result);
    free(matchR);
    return result;
}

// DFS para verificar se o emparelhamento é possível
bool bpm(int **bpGraph, int u, bool seen[], int matchR[], int V) {
    for (int v = 0; v < V; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR, V)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

#endif