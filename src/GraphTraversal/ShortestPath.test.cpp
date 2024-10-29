#include "ShortestPath.h"
#include <gtest/gtest.h>

class ShortestPathTestFixture : public testing::Test {
protected:
    AdjacencyList adjList;
    ShortestPath shortestPath;

    ShortestPathTestFixture()
      : adjList(6)
      , shortestPath(adjList) {}

    void SetUp() override {
        std::vector<std::pair<int, int>> edges{ { 0, 1 }, { 0, 2 }, { 1, 3 },
                                                { 2, 4 }, { 3, 0 }, { 3, 4 },
                                                { 4, 3 }, { 4, 5 } };
        for (auto [u, v] : edges) {
            adjList.addEdge(u, v);
        }
    }
    void TearDown() override {};
};

TEST_F(ShortestPathTestFixture, TestShortestPath) {
    // test happy case
    EXPECT_EQ(shortestPath.computeShortestPath(0, 4),
              (std::vector<int>{ 0, 2, 4 }));

    // test unhappy case
    EXPECT_THROW(shortestPath.computeShortestPath(5, 0),
                 NoPathExistsException);
}