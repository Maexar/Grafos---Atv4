#include "reseacher.h"

void printGraph(int **graph, int V) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}




int main() {
    int V, numEdges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)calloc(V, sizeof(int));
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge %d (format u v): ", i + 1);
        scanf("%d %d", &u, &v);

        if (u >= V || v >= V || u < 0 || v < 0) {
            printf("Error: vertices must be between 0 and %d.\n", V - 1);
            i--;
        } else {
            addEdge(graph, u, v);
        }
    }

    printGraph(graph, V);

    colorGraph(graph, V);

    if (isConnected(graph, V)) {
        printf("The graph is connected\n");
    } else {
        printf("The graph is not connected\n");
    }

     if (isBipartite(graph, V)) {
        printf("The graph is Bipartite\n");
        maxBipartiteMatching(graph, V);
    } else {
        printf("The graph is not Bipartite, so matching is not applicable.\n");
    }


    if (isEulerian(graph, V)) {
        printf("The graph is Eulerian\n");
    } else {
        printf("The graph is not Eulerian\n");
    }

    if (isHamiltonian(graph, V)) {
        printf("The graph is Hamiltonian\n");
    } else {
        printf("The graph is not Hamiltonian\n");
    }

   
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}