#include<array>
#include<vector>
#include<algorithm>
#include<memory>
#include<iostream>
#include<functional>
using namespace std;


struct ShortestPathEdge {
  int origin;
  int distance;
};


template <typename TipoNode, typename TipoEdge, int N>
class Graph {
public:

    Graph() {
        // Nodes
        for (int i=0; i<N; i++) {
            nodes[i] = nullptr;
        }

        // Edges
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                edges[i][j] = nullptr;
            }
        }
    }

    void add_node(int node, string dato_node) {
        auto dato = std::make_shared<string>(dato_node);
        nodes[node] = dato;
    }

    void remove_node(int node) {
        nodes[node] = nullptr;
        // Remove all the edges that use this node!
        for (int i=0; i<N; i++) {
            this->remove_edge(node, i); // It is undirected, no need to remove (i, node) as well.
        }
    }


    bool add_edge(int origin, int target, const TipoEdge& dato_edge) {
        // Check if nodes exists:
        if (!nodes[origin] || !nodes[target]) {
            return false;
        }
        auto edge = std::make_shared<TipoEdge>(dato_edge);
        edges[origin][target] = edge;
        edges[target][origin] = edge;
        return true;
    }

    void remove_edge(int origin, int target) {
        edges[origin][target] = nullptr;
        edges[target][origin] = nullptr;
    }


    vector<int> adjacents(int node) const{
        vector<int> ret;
        for (int i = 0; i < N; i++) {
          if(adj[node][i] != nullptr) {
            ret.push_back(i);
          }
        }
        return ret;
    }

    int _min_idx(array<bool, N> added, array<ShortestPathEdge, N> shortestPathEdges) {
      int minimum = numeric_limits<int>::max();
      int idx = -1;
      for (int i=0; i<N; i++) {
        if (!added[i] && shortestPathEdges[i].distance < minimum) {
          minimum = shortestPathEdges[i].distance;
          idx = i;
        }
      }
      return idx;
    }
       array<ShortestPathEdge, N> dijkstra(int start) const{

         array<ShortestPathEdge, N> shortestPathEdges;
         array<bool, N> added;

         for (int i = 0; i < N; i++) {
           shortestPathEdges[i].distance = numeric_limits<int>::max();
           shortestPathEdges[i].origin = -1;
           added[i] = false;
         }

         shortestPathEdges[start].distance = 0;
         while(!std::all_of(added.begin(), added.end(), [](bool item){return item;})) {

           auto idx = _min_idx(added, shortestPathEdges);
           added[idx] = true;


           for (int n: this->adjacents(idx)) {
             int distance = shortestPathEdges[idx].distance + *adj[idx][n];
             if (distance < shortestPathEdges[n].distance) {
               shortestPathEdges[n].distance = distance;
               shortestPathEdges[n].origin = idx;
             }
           }
         }
         return shortestPathEdges;
    }


    vector<int> shortestPath(int start, int end) const{
        auto shortestPathEdges = this->dijkstra(start);
        vector<int> ret;

         while (end != start) {
           ret.push_back(end);
           end = shortestPathEdges[end].origin;
         }

         ret.push_back(end);
         std::reverse(ret.begin(), ret.end());
         return ret;
    }



    bool are_connected(string city1, string city2) const{
        int pos=0;
        int pos2=0;
        for(int i=0; i <N; i++){
            if(*nodes[i] == city1){
                pos = i;
            }if(*nodes[i] == city2){
                pos2 = i;
            }
        }
        if(edges[pos][pos2] != nullptr){
            cout << "La distancia entre ellas es: " << *edges[pos][pos2] << endl;
            return true;
        }else{
            return false;
        }

    }

    int num_components() const{

    }

    Graph<TipoNode, TipoEdge, N> telephone() const{

    }

    int sum_kilometers() const{
          int result=0;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                   if(edges[i][j]!=nullptr) {
                   result=result+*edges[i][j];
               }
            }
        }
     return result/2;
    }


    array<array<shared_ptr<int>, N>, N> adj;
    array<shared_ptr<string>, N> nodes;
    array<array<shared_ptr<int>, N>, N> edges;


};

template <typename TipoNode, typename TipoEdge, int N>
ostream& operator<<(std::ostream& os, const Graph <TipoNode, TipoEdge, N>& graph){
    os << "  |";
    for (int i=0; i<N; i++) {
        os << " " << i;
    }
    os << endl;
    for (int i=0; i<N; i++) {
        os << i << " | ";
        for (int j=0; j<N; j++) {
            if(graph.edges[i][j]==nullptr){
                os << "0" << " ";
            }else{
                os << *graph.edges[i][j] << " ";
            }
        }

        os << endl;
    }
    return os;
}
