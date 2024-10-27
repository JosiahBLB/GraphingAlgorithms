#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include <gtest/gtest.h>

class AdjacencyMatrixTestFixture : public testing::Test {
protected:
    int n;
    AdjacencyMatrix adjMat;
    std::vector<std::pair<int, int>> edges{ { 0, 1 }, { 1, 0 }, { 1, 2 },
                                            { 1, 3 }, { 2, 0 }, { 2, 3 } };

    void SetUp() override {
        n = 4;
        adjMat = AdjacencyMatrix(n);
    }
    void TearDown() override{};
    void populateAdjacencyMatrix() {
        for (auto [u, v] : edges) {
            adjMat.addEdge(u, v);
        }
    }
};

TEST_F(AdjacencyMatrixTestFixture, TestSize) {
    EXPECT_EQ(adjMat.size(), n);
}

TEST_F(AdjacencyMatrixTestFixture, TestAddGetRemove) {
    populateAdjacencyMatrix();
    const int EXISTS = 1, NEXISTS = 0;

    // test known edges
    EXPECT_EQ(adjMat.getEdge(1, 2), EXISTS);
    EXPECT_EQ(adjMat.getEdge(2, 1), NEXISTS);

    // test edge removal
    adjMat.removeEdge(1, 2);
    EXPECT_EQ(adjMat.getEdge(1, 2), NEXISTS);
}

TEST_F(AdjacencyMatrixTestFixture, TestToAdjacencyList) {
    populateAdjacencyMatrix();
    AdjacencyList adjList = adjMat.toAdjacencyList();
    for (auto [u, v] : edges) {
        EXPECT_EQ(adjMat.getEdge(u, v), adjList.getEdge(u, v));
    }
}