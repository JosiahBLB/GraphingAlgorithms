#include "WeightedAdjacencyList.h"
#include "WeightedAdjacencyMatrix.h"
#include <gtest/gtest.h>

class WeightedAdjacencyListTestFixture : public testing::Test {
protected:
    int n;
    WeightedAdjacencyList adjList;
    std::vector<std::tuple<int, int, int>> edges{ { 0, 1, 1 }, { 1, 0, 3 },
                                                  { 1, 2, 5 }, { 1, 3, 3 },
                                                  { 2, 0, 2 }, { 2, 3, 5 } };

    void SetUp() override {
        n = 4;
        adjList = WeightedAdjacencyList(n);
    }
    void TearDown() override{};
    void PopulateWeightedAdjacencyList() {
        for (auto [u, v, w] : edges) {
            adjList.addEdge(u, v, w);
        }
    }
};

TEST_F(WeightedAdjacencyListTestFixture, TestSize) {
    EXPECT_EQ(adjList.size(), n);
}

TEST_F(WeightedAdjacencyListTestFixture, TestAddGetRemove) {
    PopulateWeightedAdjacencyList();
    const int EXPECTED_WEIGHT = 5, NEXISTS = -1;

    // test known edges
    EXPECT_EQ(adjList.getEdge(1, 2), EXPECTED_WEIGHT);
    EXPECT_EQ(adjList.getEdge(2, 1), NEXISTS);

    // test edge removal
    adjList.removeEdge(1, 2);
    EXPECT_EQ(adjList.getEdge(1, 2), NEXISTS);
}

TEST_F(WeightedAdjacencyListTestFixture, TestToWeightedAdjacencyMatrix) {
    PopulateWeightedAdjacencyList();
    WeightedAdjacencyMatrix adjMat = adjList.toWeightedAdjacencyMatrix();
    for (auto [u, v, w] : edges) {
        EXPECT_EQ(adjMat.getEdge(u, v), adjList.getEdge(u, v));
    }
}