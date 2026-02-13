#include <string>
#include <vector>

using namespace std;

int n = 0;

void dfs(vector<int> &num,int t,int cnt,int ind){
    if(cnt == t && ind == num.size()){
        n++;
        return;
    }
    if(ind == num.size()){
        return;
    }
            cnt += num[ind];
            dfs(num,t,cnt,ind + 1);
            cnt -= num[ind];
            cnt -= num[ind];
            dfs(num,t,cnt,ind + 1);    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0);
        
    answer = n;
    return answer;
}