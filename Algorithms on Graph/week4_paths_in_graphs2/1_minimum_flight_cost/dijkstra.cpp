#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;


long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here

  //pair is of (weight, distance)
  priority_queue<pair<int,int>, vector<pair<int, int> >, std::greater<pair<int,int> > > pq;
  //Initialize distance as -1 as INF
  vector<int> dist(adj.size(), INT_MAX);
  dist[s] = 0;
  pq.push(make_pair(dist[s], s));
  int weight_index;

  while(!pq.empty()){
    int v = pq.top().second; //extract neighbour of s with min cost
    pq.pop();
    weight_index = 0;
    for(auto u : adj[v]){
        if(dist[u] > dist[v] + cost[v][weight_index]){
            dist[u] = dist[v] + cost[v][weight_index];
            pq.push(make_pair(dist[u], u));
        }
        weight_index++;
    }
  }

  if(dist[t] == INT_MAX) return -1;
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
