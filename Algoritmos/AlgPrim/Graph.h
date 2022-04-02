#ifndef GRAPH_H
#define GRAPH_H
#include<array>
#include<iostream>
#include<memory>
#include<vector>
template <int N>
class Graph {
    public:
        Graph();
        /* ... other methods... */
        void add_edge(int origin, int target, int weigth);
        std::vector<int> adjacents(int node) const;
        Graph mst_prim() const;
    private:
        std::array<std::array<std::shared_ptr<int>, N>, N> edges;
};
template <int N>
Graph<N> Graph<N>::mst_prim() const {
    // Distance from the MST already computed to the node indicated by the index
    std::array<int, N> distances;
    // Node inside the MST that is closer to node-at-index
    std::array<int, N> origins;
    std::array<bool, N> added;
    // Initialize
    for (int i = 0; i < N; i++) {
        distances[i] = std::numeric_limits<int>::max();
        origins[i] = -1;
        added[i] = false;
    }

    distances[0] = 0; // We will start with this node (index 0)
    // Algorithm runs until all nodes has been added
    while(!std::all_of(added.begin(), added.end(), [](bool item){return item;})) {
        // Search the node that is closer to the ones already in the graph
        auto result = std::min_element(distances.begin(), distances.end());
        auto idx = std::distance(distances.begin(), result);
        added[idx] = true;
        distances[idx] = std::numeric_limits<int>::max(); // Prevent it from being selected again

        // Update distances for those that are not in the graph already
        for (int i = 0; i < N; i++) {
            if (!added[i] && edges[idx][i]!=nullptr) {
                if (distances[i] > *edges[idx][i]) {
                    distances[i] = *edges[idx][i];
                    origins[i] = idx;
                }
            }
        }
    }

    // Create the MST with the information
    Graph<N> ret;
    for (int i = 1; i < N; i++) {
        auto origin = origins[i];
        std::cout << origin << " -> " << i << std::endl;
        ret.add_edge(origin, i, *edges[origin][i]);
    }
    return ret;
}
#endif // GRAPH_H
