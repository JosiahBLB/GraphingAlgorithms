#include "CycleDetector.h"

bool CycleDetector::containsCycle() {
    // for every starting vertex in the graph
    // time complexity: O(|E|)
    // explanation: could explore every edge

    // init
    cycleFound = false;
    nodeStates.assign(adjList.size(), NodeState::UNVISITED);

    // explore unvisited nodes
    for (int u = 0; u < adjList.size(); ++u) {
        if (nodeStates[u] == NodeState::FINISHED) {
            continue; // skip discovered node
        }
        dfs(u);
    }
    return cycleFound;
}

void CycleDetector::dfs(int u, int parent) {
    nodeStates[u] = NodeState::IN_PROGRESS;
    for (auto v : adjList.getNode(u)) {
        if (v == parent)
            continue; // skip edge back to parent
        switch (nodeStates[v]) {
            case NodeState::UNVISITED:
                dfs(v, u); // discovery edge: explore
                break;
            case NodeState::IN_PROGRESS:
                cycleFound = true;
                break;
            case NodeState::FINISHED:
                break; // redundant edge: skip
        }
    }
    nodeStates[u] = NodeState::FINISHED;
}