#ifndef SHORTEST_PATH
#define SHORTEST_PATH

#include "../Graph/AdjacencyList.h"

#include <queue>
#include <vector>

class ShortestPathTestFixture;

class ShortestPath {
private:
    AdjacencyList& adjList;
    std::vector<int> distances;
    std::vector<int> parents;
    static constexpr int UNKNOWN = -1;

public:
    ShortestPath(AdjacencyList& _adjList)
      : adjList{ _adjList }
      , distances{ std::vector<int>(_adjList.size(), UNKNOWN) }
      , parents{ std::vector<int>(_adjList.size(), UNKNOWN) } {}

    void bfs(int start);
    std::vector<int> computeShortestPath(int start, int end);
};

class NoPathExistsException : public std::runtime_error {
public:
    NoPathExistsException()
      : std::runtime_error("No path exists") {}
};

#endif /* SHORTEST_PATH */
