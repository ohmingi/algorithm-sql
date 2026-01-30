#include <iostream>
#include <unordered_map>

using namespace std;

int dist[101][101];
unordered_map<int,int> mp;

int main() {
  int n, m, r;
  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    mp[i] = a;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        dist[i][j] = 0;
        continue;
      }
      dist[i][j] = 1e9;
    }
  }

  for (int i = 0; i < r; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    dist[a][b] = min(dist[a][b],c);
    dist[b][a] = min(dist[b][a],c);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    int a = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] <= m) {
        a += mp[j];
      }
    }
    cnt = max(cnt, a);
  }

  cout << cnt;
}