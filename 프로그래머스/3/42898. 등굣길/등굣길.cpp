#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(int m, int n, vector<vector<int>> p) {
    int answer = 0;
    int dp[101][101];
    int check[101][101];
    
    memset(check, 0, sizeof(check));
    
    for(auto &a : p){
        check[a[0]][a[1]] = 1;
    }    
    
    memset(dp, 0, sizeof(dp));
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i++){
        for(int t = 1; t <= n; t++){
            if((i == 1 && t == 1) || check[i][t] == 1) continue;
    
            dp[i][t] = (dp[i-1][t] + dp[i][t-1]) % 1000000007;
        }
    }
    
    answer = dp[m][n];
    return answer;
}