#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

void AdjacencyMatrix::addEdge(int src, int dest) {
    this->adjMat[this->n * src + dest] = true;
}

void AdjacencyMatrix::removeEdge(int src, int dest) {
    this->adjMat[this->n * src + dest] = false;
}

int AdjacencyMatrix::getEdge(int src, int dest) {
    return this->adjMat[this->n * src + dest];
}

AdjacencyList AdjacencyMatrix::toAdjacencyList() {
    AdjacencyList adjList(this->n);
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (this->getEdge(i, j)) {
                adjList.addEdge(i, j);
            }
        }
    }
    return adjList;
}