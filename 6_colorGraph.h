#ifndef COLORGRAPH_H
#define COLORGRAPH_H

#include "reseacher.h"

// Algoritmo guloso para colorir o grafo
void colorGraph(int **graph, int V) {
    int *result = (int *)malloc(V * sizeof(int));
    bool *availableColors = (bool *)malloc(V * sizeof(bool));

    // Inicializa todas as cores como não atribuídas (-1)
    for (int i = 0; i < V; i++) {
        result[i] = -1;
    }

    // Atribui a primeira cor ao primeiro vértice
    result[0] = 0;

    for (int u = 1; u < V; u++) {
        // Marca todas as cores como disponíveis
        for (int i = 0; i < V; i++) {
            availableColors[i] = true;
        }

        // Marca como indisponíveis as cores dos vértices adjacentes
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && result[i] != -1) {
                availableColors[result[i]] = false;
            }
        }

        // Encontra a primeira cor disponível
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (availableColors[cr]) {
                break;
            }
        }

        result[u] = cr;
    }

    // Exibe as cores atribuídas
    printf("Vertex Coloring:\n");
    for (int u = 0; u < V; u++) {
        printf("Vertex %d ---> Color %d\n", u, result[u]);
    }

    free(result);
    free(availableColors);
}

#endif