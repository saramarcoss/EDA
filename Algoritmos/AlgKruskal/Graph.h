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
        Graph<N> mst_kruskal() const;
    private:
        std::array<std::array<std::shared_ptr<int>, N>, N> adj;
};

struct Edge {
    int origin, target;
    int weigth;

    bool operator<(const Edge& other) const {
        return weigth > other.weigth;
    }
};

template <int N>
Graph<N> Graph<N>::mst_kruskal() const {
    std::priority_queue<Edge> queue;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            if (adj[i][j] != nullptr) {
                queue.push(Edge{i, j, *adj[i][j]});
            }
        }
    }

    // The forest
    std::array<int, N> forest_tree;
    for (int i=0; i<N; i++) {
        forest_tree[i] = i; // node -> tree identificator
    }

    // Create the MST with the information
    Graph<N> ret;

    while (!queue.empty()) {
        // Next edge according to priority (less weigth)
        auto edge = queue.top(); queue.pop();

        // If this edge connects two different trees
        if (forest_tree[edge.origin] != forest_tree[edge.target]) {
            ret.add_edge(edge.origin, edge.target, edge.weigth);
            int origin_tree = forest_tree[edge.origin];
            int target_tree = forest_tree[edge.target];
            for (int i=0; i<N; i++) {
                // Update forest mapping, now these two trees are the same
                if (forest_tree[i] == target_tree) {
                    forest_tree[i] = origin_tree;
                }
            }
        }
    }
    return ret;
}
#endif // GRAPH_H
