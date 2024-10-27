#include "WeightedAdjacencyList.h"
#include "WeightedAdjacencyMatrix.h"

void WeightedAdjacencyList::addEdge(int src, int dest, int weight)
{
    adjList[src].push_back({ dest, weight });
}

void WeightedAdjacencyList::removeEdge(int src, int dest)
{
    auto it = std::find_if(adjList[src].begin(),
                           adjList[src].end(),
                           [dest](const std::pair<int, int>& element) {
                               return element.first == dest;
                           });
    if (it != adjList[src].end()) {
        adjList[src].erase(it);
    }
}

int WeightedAdjacencyList::getEdge(int src, int dest)
{
    auto it = std::find_if(adjList[src].begin(),
                           adjList[src].end(),
                           [dest](const std::pair<int, int>& element) {
                               return element.first == dest;
                           });
    if (it != adjList[src].end()) {
        auto idxWeight= *it;
        return idxWeight.second;
    }
    return -1;
}

WeightedAdjacencyMatrix WeightedAdjacencyList::toWeightedAdjacencyMatrix()
{
    WeightedAdjacencyMatrix adjMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight = getEdge(i, j);
            if (getEdge(i, j)) {
                adjMatrix.addEdge(i, j, weight);
            }
        }
    }
    return adjMatrix;
}