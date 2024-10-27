#ifndef DEPTH_FIRST_SEARCH
#define DEPTH_FIRST_SEARCH

#include <vector>

#include "../Graph/AdjacencyList.h"

enum class NodeState
{
    UNVISITED,
    IN_PROGRESS,
    FINISHED
};

class CycleDetector
{
  private:
    AdjacencyList &adjList;
    std::vector<NodeState> nodeStates;
    bool cycleFound = false;

  public:
    ~CycleDetector() = default;
    explicit CycleDetector(AdjacencyList& _adjList)
      : adjList{ _adjList }
      , nodeStates{ std::vector<NodeState>(_adjList.size(),
                                           NodeState::UNVISITED) }
    {
    }

    void dfs(int u, int parent = 1);
    bool containsCycle();
};

#endif /* DEPTH_FIRST_SEARCH */
