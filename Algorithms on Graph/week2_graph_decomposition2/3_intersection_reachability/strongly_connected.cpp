#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;
using std::pair;

void dfs(vector<vector<int> > &adj, int v, vector<bool> &visited, stack<int> &order){
    visited[v] = true;
    for(auto w: adj[v])
        if(!visited[w])
            dfs(adj, w, visited,order);

    //all vertices reachable from v are processed now, push v to stack
    order.push(v);
}

vector<vector<int> > reverse_graph(vector<vector<int> > &adj){
    vector<vector<int> > reverse_adj(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++)
        for(int j = 0; j < adj[i].size(); j++)
            //for every node reverse the link
            reverse_adj[adj[i][j]].push_back(i);

    return reverse_adj;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  vector<vector<int> > reverse_adj = reverse_graph(adj);
  vector<bool> visited(adj.size(),false);
  //use stack for ordering of the vertex
  stack<int> order;

  //run DFS on reversed graph
  for(int v = 0; v < reverse_adj.size(); v++)
    if(!visited[v])
        dfs(reverse_adj, v, visited,order);

  //refill visited vector with false;
  std::fill(visited.begin(), visited.end(), false);

  //process vertex defined in stack
  while(!order.empty()){
    int v = order.top();
    order.pop();

    if(!visited[v]){
        stack<int> component_stack;
        dfs(adj, v, visited, component_stack);
        result++;
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
