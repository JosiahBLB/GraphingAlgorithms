#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

// std library
#include <iostream>
#include <map>
#include <string>
#include <vector>

class AdjacencyList;

class AdjacencyMatrix
{
  private:
    std::vector<bool> adjMat;
    int n;

  public:
    AdjacencyMatrix() = default;
    ~AdjacencyMatrix() = default;
    AdjacencyMatrix(int _n)
      : n{ _n }
      , adjMat{ std::vector<bool>(_n * _n, 0) }
    {
    }
    void addEdge(int src, int dest);
    void removeEdge(int src, int dest);
    int getEdge(int src, int dest);
    int size() { return n; };
    AdjacencyList toAdjacencyList();
};

#endif /* ADJACENCY_MATRIX */
