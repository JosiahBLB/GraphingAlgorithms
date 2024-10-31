#include "TopologicalSort.h"

std::vector<int> TopoLogicalSort::computeTopologicalSort() {
    nodeStates.assign(nodeStates.size(), NodeState::UNVISITED);
    finishOrder.clear();
    for (int u = 0; u < adjList.size(); ++u) {
        if (nodeStates[u] == NodeState::FINISHED) {
            continue;
        }
        dfs(u);
    }
    reverse(finishOrder.begin(), finishOrder.end());
    return finishOrder;
}

void TopoLogicalSort::dfs(int u) {
    // O(|V| + |E|)
    nodeStates[u] = NodeState::IN_PROGRESS;

    for (int v : adjList.getNode(u)) {
        switch (nodeStates[v]) {
            case NodeState::UNVISITED:
                dfs(v);
                break;
            case NodeState::IN_PROGRESS:
                throw GraphIsCyclicException();
                break;
            case NodeState::FINISHED:
                break;
        }
    }

    nodeStates[u] = NodeState::FINISHED;
    finishOrder.push_back(u);
}