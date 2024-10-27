#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

// std library
#include <vector>

void adjListVec();

class AdjacencyMatrix;

class AdjacencyList {
private:
    std::vector<std::vector<int>> adjList;
    int n;

public:
    AdjacencyList() = default;
    ~AdjacencyList() = default;
    AdjacencyList(int _n)
      : n{ _n }
      , adjList{ std::vector<std::vector<int>>(_n) } {}
    void removeEdge(int src, int dest);
    void addEdge(int src, int dest);
    int getEdge(int src, int dest);
    int size() { return n; };
    std::vector<int> getNode(int src);
    AdjacencyMatrix toAdjacencyMatrix();
};

#endif /* ADJACENCY_LIST */
