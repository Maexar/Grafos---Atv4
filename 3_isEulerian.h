#ifndef ISEULERIAN_H
#define ISEULERIAN_H

#include "reseacher.h"

bool isEulerian(int **graph, int V) {
    int oddDegree = 0;

    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) degree++;
        }
        if (degree % 2 != 0) oddDegree++;
    }

    return (oddDegree == 0 || oddDegree == 2) && isConnected(graph, V);
}


#endif