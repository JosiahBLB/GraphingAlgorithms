#ifndef TOPOLOGICAL_SORT
#define TOPOLOGICAL_SORT

#include <vector>

#include "../Graph/AdjacencyList.h"

enum class NodeState { UNVISITED, IN_PROGRESS, FINISHED };

class TopoLogicalSort {
private:
    AdjacencyList& adjList;
    std::vector<NodeState> nodeStates;
    std::vector<int> finishOrder;

public:
    ~TopoLogicalSort() = default;
    explicit TopoLogicalSort(AdjacencyList& _adjList)
      : adjList{ _adjList }
      , nodeStates{ std::vector<NodeState>(_adjList.size(),
                                           NodeState::UNVISITED) } {}

    void dfs(int u);
    std::vector<int> computeTopologicalSort();
};

class GraphIsCyclicException : public std::runtime_error {
public:
    GraphIsCyclicException()
      : std::runtime_error("The graph contains a cycle.") {}
};

#endif /* TOPOLOGICAL_SORT */
