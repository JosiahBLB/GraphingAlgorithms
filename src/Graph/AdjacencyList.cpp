#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

void AdjacencyList::removeEdge(int src, int dest) {
    auto it = std::find(adjList[src].begin(), adjList[src].end(), dest);
    if (it != adjList[src].end()) {
        adjList[src].erase(it);
    }
}

void AdjacencyList::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

int AdjacencyList::getEdge(int src, int dest) {
    auto it = std::find(adjList[src].begin(), adjList[src].end(), dest);
    if (it != adjList[src].end()) {
        return 1;
    }
    return 0;
}

std::vector<int> AdjacencyList::getNode(int src) {
    if (src < size()) {
        return adjList[src];
    }
    return {};
}

AdjacencyMatrix AdjacencyList::toAdjacencyMatrix() {
    AdjacencyMatrix adjMat(this->n);
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < adjList[i].size(); ++j) {
            adjMat.addEdge(i, adjList[i][j]);
        }
    }
    return adjMat;
}