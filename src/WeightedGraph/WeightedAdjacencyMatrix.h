#ifndef WEIGHTED_ADJACENCY_MATRIX
#define WEIGHTED_ADJACENCY_MATRIX

// std library
#include <iostream>
#include <map>
#include <string>
#include <vector>

class WeightedAdjacencyList;

class WeightedAdjacencyMatrix {
private:
    std::vector<int> adjMat;
    int n;

public:
    WeightedAdjacencyMatrix() = default;
    ~WeightedAdjacencyMatrix() = default;
    WeightedAdjacencyMatrix(int _n)
      : n{ _n }
      , adjMat{ std::vector<int>(_n * _n, -1) } {}
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);
    int getEdge(int src, int dest);
    int size() { return n; };
    WeightedAdjacencyList toWeightedAdjacencyList();
};

#endif /* WEIGHTED_ADJACENCY_MATRIX */
