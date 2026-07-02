#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int tree[101][101];
bool visited[101];
int node_count = 0;

void dfs(int current_node, int n) {
    visited[current_node] = true;
    node_count++;
    
    for (int next_node = 1; next_node <= n; next_node++) {
        if (tree[current_node][next_node] == 1 && !visited[next_node]) {
            dfs(next_node, n);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int min_difference = 1e9;

    for (const auto &wire : wires) {
        tree[wire[0]][wire[1]] = 1;
        tree[wire[1]][wire[0]] = 1;
    }
    
    for (const auto &wire : wires) {
        int u = wire[0];
        int v = wire[1];
        
        tree[u][v] = 0;
        tree[v][u] = 0;
        
        memset(visited, 0, sizeof(visited));
        node_count = 0;
        
        dfs(u, n);
        int component_a = node_count;
        int component_b = n - component_a;
        
        int current_difference = abs(component_a - component_b);
        if (current_difference < min_difference) {
            min_difference = current_difference;
        }
     
        tree[u][v] = 1;
        tree[v][u] = 1;
    }
    
    return min_difference;
}