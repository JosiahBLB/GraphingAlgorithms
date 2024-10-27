#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <gtest/gtest.h>

class AdjacencyListTestFixture : public testing::Test {
protected:
    int n;
    AdjacencyList adjList;
    std::vector<std::pair<int, int>> edges{ { 0, 1 }, { 1, 0 }, { 1, 2 },
                                            { 1, 3 }, { 2, 0 }, { 2, 3 } };

    void SetUp() override {
        n = 4;
        adjList = AdjacencyList(n);
    }
    void TearDown() override{};
    void PopulateAdjacencyList() {
        for (auto [u, v] : edges) {
            adjList.addEdge(u, v);
        }
    }
};

TEST_F(AdjacencyListTestFixture, TestSize) {
    EXPECT_EQ(adjList.size(), n);
}

TEST_F(AdjacencyListTestFixture, TestAddGetRemove) {
    PopulateAdjacencyList();

    // test known edges
    EXPECT_TRUE(adjList.getEdge(1, 2));
    EXPECT_FALSE(adjList.getEdge(2, 1));

    // test edge removal
    adjList.removeEdge(1, 2);
    EXPECT_FALSE(adjList.getEdge(1, 2));
}

TEST_F(AdjacencyListTestFixture, TestGetNode) {
    PopulateAdjacencyList();
    auto node = adjList.getNode(1);
    EXPECT_EQ(node[0], 0);
    EXPECT_EQ(node[1], 2);
    EXPECT_EQ(node[2], 3);
}

TEST_F(AdjacencyListTestFixture, TestToAdjacencyMatrix) {
    PopulateAdjacencyList();
    AdjacencyMatrix adjMat = adjList.toAdjacencyMatrix();
    for (auto [u, v] : edges) {
        EXPECT_EQ(adjMat.getEdge(u, v), adjList.getEdge(u, v));
    }
}