#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,e;

struct Edge {
  int u,v,w;
};

int parent[10001];

bool compare(Edge &a, Edge &b) {
  return a.w < b.w;
}

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) parent[x] = y;
}

int main() {
  cin >> V >> e;

  vector<Edge> edge;

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({u,v,w});
  }

  sort(edge.begin(), edge.end(), compare);

  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }

  int sum = 0;

  for (int i = 0; i < e; i++) {
    int st = edge[i].u;
    int en = edge[i].v;
    int cost = edge[i].w;

    if (find(st) != find(en)) {
      merge(st, en);
      sum += cost;
    }
  }

  cout << sum;
}