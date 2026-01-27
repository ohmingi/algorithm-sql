#include <iostream>
#include <vector>
#include <queue>

int dist[100001];
using namespace std;

void djk(int x, int y) {
  fill(dist,dist+100001,1e9);

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push(make_pair(0,x));
  dist[x] = 0;

  while (!pq.empty()) {
    pair<int,int> curr = pq.top();
    pq.pop();

    if (curr.second == y) {break;}

    if (dist[curr.second] < curr.first) {continue;}

    if (curr.second - 1 >= 0) {
      if (dist[curr.second - 1] > curr.first + 1) {
        dist[curr.second - 1] = curr.first + 1;
        pq.push(make_pair(dist[curr.second - 1],curr.second - 1));
      }
    }
    if (curr.second + 1 <= 100000) {
      if (dist[curr.second + 1] > curr.first + 1) {
        dist[curr.second + 1] = curr.first + 1;
        pq.push(make_pair(dist[curr.second + 1],curr.second + 1));
      }
    }
    if (curr.second * 2 <= 100000) {
      if (dist[curr.second * 2] > curr.first) {
        dist[curr.second * 2] = curr.first;
        pq.push(make_pair(dist[curr.second * 2],curr.second * 2));
      }
    }
  }
}

int main() {
  int n,k;
  cin >> n >> k;

  djk(n,k);

  cout << dist[k];
}