#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> v[50001];
int dist[50001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void djk(int k) {
  fill(dist,dist+50001,1e9);

  dist[k] = 0;
  pq.push(make_pair(0,k));

  while (!pq.empty()) {
    pair<int,int> curr = pq.top();
    pq.pop();

    if (dist[curr.second] < curr.first) {
      continue;
    }

    for (auto a : v[curr.second]) {
      if (dist[a.first] > dist[curr.second] + a.second) {
        dist[a.first] = dist[curr.second] + a.second;
        pq.push(make_pair(dist[a.first],a.first));
      }
    }

  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b,c));
    v[b].push_back(make_pair(a,c));
  }

  djk(1);

  cout << dist[n] << endl;
}