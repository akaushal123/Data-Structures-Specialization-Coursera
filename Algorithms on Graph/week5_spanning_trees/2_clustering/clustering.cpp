#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

struct VertexNode {
    int x, y, parent, rank;
    VertexNode(int x,int y, int parent = -1,int rank = 0): x(x), y(y), parent(parent), rank(rank) {}
};

struct Edge {
    int u,v;
    double weight;
    Edge(int u,int v, double wt):u(u), v(v), weight(wt){}
};

double weight(int x1,int x2, int y1, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void make_set(vector<VertexNode> &nodes, vector<int> x,vector<int> y){
    for(int i = 0; i < x.size(); i++)
        nodes.push_back(VertexNode(x[i], y[i], i));
}

bool cmp (Edge a, Edge b){
    return a.weight < b.weight;
}

int find(int i, vector<VertexNode> &nodes){
    if(i != nodes[i].parent)
        nodes[i].parent = find(nodes[i].parent, nodes);
    return nodes[i].parent;
}

void union_set(int u, int v, vector<VertexNode> &nodes){
    int u_find = find(u, nodes);
    int v_find = find(v, nodes);

    if(u_find != v_find){
        if(nodes[u_find].rank > nodes[v_find].rank)
            nodes[v_find].parent = u_find;
        else {
            nodes[u_find].parent= v_find;
            if(nodes[u_find].rank == nodes[v_find].rank)
                nodes[v_find].rank++;
        }
    }
}

void make_edges(vector<Edge> &edges, vector<int> &x, vector<int> &y){
    for(int i = 0;i < x.size(); i++)
        for(int j = i + 1; j < x.size(); j++)
            edges.push_back(Edge(i, j, weight(x[i], x[j], y[i],y[j])));
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  vector<VertexNode> nodes;
  vector<Edge> edges;

  make_set(nodes, x, y);
  make_edges(edges, x, y);

  std::sort(edges.begin(), edges.end(), cmp);

  int union_num = 0;

  for(Edge edge: edges){
    if(find(edge.u, nodes) != find(edge.v, nodes)){
        union_num++;
        union_set(edge.u, edge.v, nodes);
    }
    if(union_num > x.size() - k) return edge.weight;
  }

  return -1.;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
