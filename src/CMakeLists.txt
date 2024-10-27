set(SOURCES
    Graph/AdjacencyMatrix.cpp
    Graph/AdjacencyList.cpp
    WeightedGraph/WeightedAdjacencyMatrix.cpp
    WeightedGraph/WeightedAdjacencyList.cpp
    GraphTraversal/CycleDetector.cpp
    GraphTraversal/ShortestPath.cpp
)

set(HEADERS
    Graph/AdjacencyMatrix.h
    Graph/AdjacencyList.h
    WeightedGraph/WeightedAdjacencyList.h
    WeightedGraph/WeightedAdjacencyMatrix.h
    GraphTraversal/CycleDetector.h
    GraphTraversal/ShortestPath.h
)

set(TESTS
    Graph/AdjacencyMatrix.test.cpp
    Graph/AdjacencyList.test.cpp
    WeightedGraph/WeightedAdjacencyMatrix.test.cpp
    WeightedGraph/WeightedAdjacencyList.test.cpp
    GraphTraversal/CycleDetector.test.cpp
    GraphTraversal/ShortestPath.test.cpp
)

add_executable(GraphAlgorithms main.cpp ${SOURCES})
add_executable(GraphAlgorithms_Test ${SOURCES} ${TESTS})

target_include_directories(GraphAlgorithms PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/GraphRepresentation
    ${CMAKE_CURRENT_LIST_DIR}/GraphTraversal
)

target_include_directories(GraphAlgorithms_Test PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/GraphRepresentation
    ${CMAKE_CURRENT_LIST_DIR}/GraphTraversal
)

target_link_libraries(GraphAlgorithms_Test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GraphAlgorithms_Test)