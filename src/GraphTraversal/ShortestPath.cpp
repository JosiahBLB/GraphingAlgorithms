#include "ShortestPath.h"

void ShortestPath::bfs(int start) {
    // time complexity:
    // - all nodes: O(|V| + |E|)
    // - one node: O(|E|)

    // init vectors
    distances.assign(distances.size(), UNKNOWN);
    parents.assign(parents.size(), UNKNOWN);
    distances[start] = 0;
    parents[start] = start;

    // init queue
    std::queue<int> unexplored;
    unexplored.push(start);

    // bfs loop
    while (!unexplored.empty()) {
        int currentNode = unexplored.front();
        unexplored.pop();
        for (int adjNode : adjList.getNode(currentNode)) {
            if (parents[adjNode] == UNKNOWN) {
                parents[adjNode] = currentNode;
                distances[adjNode] = distances[currentNode] + 1;
                unexplored.push(adjNode);
            }
        }
    }
}

std::vector<int> ShortestPath::computeShortestPath(int start, int end) {
    bfs(start);

    // end was not discovered -> no path
    if (parents[end] == UNKNOWN) {
        throw NoPathExistsException();
    }

    std::vector<int> path;
    path.push_back(end);
    int current = end;

    // go back along parents to build the path
    while (current != start) {
        current = parents[current];
        path.push_back(current);
    }

    // path was assembled in reverse order
    std::reverse(path.begin(), path.end());
    return path;
}