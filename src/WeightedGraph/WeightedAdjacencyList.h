#ifndef WEIGHTED_ADJACENCY_LIST
#define WEIGHTED_ADJACENCY_LIST

// std library
#include <iostream>
#include <map>
#include <string>
#include <vector>

class WeightedAdjacencyMatrix;

class WeightedAdjacencyList {
  private:
    std::vector<std::vector<std::pair<int, int>>> adjList;
    int n;

  public:
    WeightedAdjacencyList() = default;
    ~WeightedAdjacencyList() = default;
    WeightedAdjacencyList(int _n)
      : n{ _n }
      , adjList{ std::vector<std::vector<std::pair<int, int>>>(_n) } {}
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);
    int getEdge(int src, int dest);
    int size() { return n; };
    WeightedAdjacencyMatrix toWeightedAdjacencyMatrix();
};

#endif /* WEIGHTED_ADJACENCY_LIST */
