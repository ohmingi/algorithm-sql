
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int y, x, d;
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };

    queue<Node> bfs;
    bool visited[101][101] = {};
    bfs.push({ 0, 0, 1 });
    visited[0][0] = true;

    while (!bfs.empty())
    {
        auto [y, x, d] = bfs.front();
        bfs.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || maps[ny][nx] == 0)
                continue;

            if (ny == n - 1 && nx == m - 1)
                return d + 1;

            bfs.push({ ny, nx, d + 1 });
            visited[ny][nx] = true;
        }
    }

    return -1;
}
