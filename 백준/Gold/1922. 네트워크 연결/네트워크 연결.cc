#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

struct graph {
  int a,b,c;
};

bool compare(graph &g1, graph &g2) {
  return g1.c < g2.c;
}

int parent[1001];

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) parent[y] = x;
}

int main() {
  cin >> n >> m;

  vector<graph> v;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;

    v.push_back({a,b,c});
  }

  sort(v.begin(), v.end(), compare);

  int sum = 0;

  for (int i = 0; i < m; i++) {
    int st = v[i].a;
    int en = v[i].b;
    int cost = v[i].c;

    if (find(st) != find(en)) {
      merge(st, en);
      sum += cost;
    }
  }

  cout << sum;
}