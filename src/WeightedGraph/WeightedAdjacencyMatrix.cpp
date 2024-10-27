#include "WeightedAdjacencyMatrix.h"
#include "WeightedAdjacencyList.h"

void WeightedAdjacencyMatrix::addEdge(int src, int dest, int weight)
{
    adjMat[n * src + dest] = weight;
}

void WeightedAdjacencyMatrix::removeEdge(int src, int dest)
{
    adjMat[n * src + dest] = -1;
}

int WeightedAdjacencyMatrix::getEdge(int src, int dest)
{
    return adjMat[n * src + dest];
}

WeightedAdjacencyList WeightedAdjacencyMatrix::toWeightedAdjacencyList() {
    WeightedAdjacencyList adjList(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight = getEdge(i, j);
            if(getEdge(i, j) >= 0) {
                adjList.addEdge(i, j, weight);
            }
        }
    }
    return adjList;
}