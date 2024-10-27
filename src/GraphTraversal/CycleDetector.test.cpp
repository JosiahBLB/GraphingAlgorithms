#include "CycleDetector.h"
#include <gtest/gtest.h>

class CycleDetectorTestFixture : public testing::Test {
protected:
    AdjacencyList adjList;
    CycleDetector cycleDetector;

    CycleDetectorTestFixture()
      : adjList(5)
      , cycleDetector(adjList) {}

    void SetUp() override {
        std::vector<std::pair<int, int>> edges{ { 0, 1 }, { 0, 2 }, { 1, 3 },
                                                { 2, 1 }, { 3, 0 }, { 4, 1 } };
        for (auto [u, v] : edges) {
            adjList.addEdge(u, v);
        }
    }
    void TearDown() override{};
};

TEST_F(CycleDetectorTestFixture, TestCycleDetection) {
    EXPECT_TRUE(cycleDetector.containsCycle());
    adjList.removeEdge(1, 3);
    EXPECT_FALSE(cycleDetector.containsCycle());
}
