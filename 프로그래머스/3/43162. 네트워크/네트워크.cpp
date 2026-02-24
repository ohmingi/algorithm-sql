#include <string>
#include <vector>

using namespace std;

bool visited[201];
int graph[201][201];

void dfs(int x, int n1){
    for(int i = 1; i <= n1; i++){
        if(visited[i] == false && graph[x][i] == 1 && x != i){
            visited[i] = true;
            dfs(i, n1);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); i++){
        for(int t = 0; t < computers[i].size(); t++){
            if(computers[i][t] == 1){
                graph[i + 1][t + 1] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            dfs(i, n);
            answer++;
        }
    }
    return answer;
}