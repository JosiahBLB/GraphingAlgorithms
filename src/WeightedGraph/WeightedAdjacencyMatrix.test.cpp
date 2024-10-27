#include "WeightedAdjacencyMatrix.h"
#include "WeightedAdjacencyList.h"
#include <gtest/gtest.h>

class WeightedAdjacencyMatrixTestFixture : public testing::Test {
  protected:
    int n;
    WeightedAdjacencyMatrix adjMat;
    std::vector<std::tuple<int, int, int>> edges{ { 0, 1, 1 }, { 1, 0, 3 },
                                                  { 1, 2, 5 }, { 1, 3, 3 },
                                                  { 2, 0, 2 }, { 2, 3, 5 } };

    void SetUp() override {
        n = 4;
        adjMat = WeightedAdjacencyMatrix(n);
    }
    void TearDown() override{};
    void populateWeightedAdjacencyMatrix() {
        for (auto [u, v, w] : edges) {
            adjMat.addEdge(u, v, w);
        }
    }
};

TEST_F(WeightedAdjacencyMatrixTestFixture, TestSize) {
    EXPECT_EQ(adjMat.size(), n);
}

TEST_F(WeightedAdjacencyMatrixTestFixture, TestAddGetRemove) {
    populateWeightedAdjacencyMatrix();
    const int EXPECTED_WEIGHT = 5, NEXISTS = -1;

    // test known edges
    EXPECT_EQ(adjMat.getEdge(1, 2), EXPECTED_WEIGHT);
    EXPECT_EQ(adjMat.getEdge(2, 1), NEXISTS);

    // test edge removal
    adjMat.removeEdge(1, 2);
    EXPECT_EQ(adjMat.getEdge(1, 2), NEXISTS);
}

TEST_F(WeightedAdjacencyMatrixTestFixture, TestToWeightedAdjacencyList) {
    populateWeightedAdjacencyMatrix();
    WeightedAdjacencyList adjList = adjMat.toWeightedAdjacencyList();
    for (auto [u, v, w] : edges) {
        EXPECT_EQ(adjMat.getEdge(u, v), adjList.getEdge(u, v));
    }
}