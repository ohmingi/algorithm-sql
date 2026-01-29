#include <iostream>

using namespace std;

int dist[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) dist[i][j] = 0;
      else dist[i][j] = 1e9;
    }
  }

  for (int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;

    dist[a][b] = min(dist[a][b],c);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
          dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == 1e9) {
        cout << 0 << " ";
        continue;
      }
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }

}