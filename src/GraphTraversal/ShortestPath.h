#ifndef SHORTEST_PATH
#define SHORTEST_PATH

#include <vector>

#include "AdjacencyList.h"

class ShortestPath {
  private:
    AdjacencyList adjList;
    std::vector<int> distances;
    std::vector<int> parents;
    static constexpr int UNKNOWN = -1;

  public:
    ShortestPath(AdjacencyList& _adjList)
      : adjList{ _adjList }
      , distances{ std::vector<int>(_adjList.size(), UNKNOWN) }
      , parents{ std::vector<int>(_adjList.size(), UNKNOWN) } {}
};

#endif /* SHORTEST_PATH */
