#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> v[10001];
int dist[10001];

void djk(int x) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  fill(dist, dist + 10001, 1e9);

  dist[x] = 0;
  pq.push(make_pair(0,x));

  while (!pq.empty()) {
    pair<int,int> cur = pq.top();
    pq.pop();

    if (dist[cur.second] < cur.first) {
      continue;
    }

    for (auto a : v[cur.second]) {
      if (dist[a.first] > dist[cur.second] + a.second) {
        dist[a.first] = dist[cur.second] + a.second;
        pq.push(make_pair(dist[a.first],a.first));
      }
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int cnt = 0;
    int c1 = 0;

    int n, d, c;
    cin >> n >> d >> c;

    for(int i = 1; i <= n; i++) {
      v[i].clear();
    }

    while (d--) {
      int a,b,s;
      cin >> a >> b >> s;

      v[b].push_back(make_pair(a,s));
    }

    djk(c);

    for(int i = 1; i <= n; i++) {
      if (dist[i] == 1e9) {
        continue;
      }
      cnt++;
      c1 = max(c1, dist[i]);
    }

    cout << cnt << " " << c1 << "\n";
  }
}