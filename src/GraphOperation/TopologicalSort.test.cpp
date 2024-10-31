#include "TopologicalSort.h"

#include <gtest/gtest.h>

class TopologicalSortFixture : public testing::Test {
protected:
    AdjacencyList adjList;
    TopoLogicalSort topologicalSort;

    TopologicalSortFixture()
      : adjList(5)
      , topologicalSort(adjList) {}

    void SetUp() override {
        std::vector<std::pair<int, int>> edges{ { 0, 1 }, { 0, 4 }, { 2, 4 },
                                                { 2, 1 }, { 3, 0 }, { 4, 1 } };
        for (auto [u, v] : edges) {
            adjList.addEdge(u, v);
        }
    }
    void TearDown() override {};
};

TEST_F(TopologicalSortFixture, TestTopologicalSort) {
    // test happy case
    EXPECT_EQ(topologicalSort.computeTopologicalSort(),
              (std::vector<int>{ 3, 2, 0, 4, 1 }));
        
    // test unhappy case
    adjList.addEdge(2,3);
    adjList.addEdge(4,2);
    EXPECT_THROW(topologicalSort.computeTopologicalSort(),
              GraphIsCyclicException);
}