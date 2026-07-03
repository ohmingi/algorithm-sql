#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> qq;
    
    for(int a : truck_weights){
        qq.push(a);
    }
    
    queue<int> q;
    
    for(int i = 0; i < bridge_length - 1; i++){
        q.push(-1);
    }
    
    int time = 1;
    
    q.push(qq.front());
    weight -= qq.front();
    qq.pop();
    
    while(!q.empty()){
        if(q.front() > 0){
            weight += q.front();
        }
        q.pop();
        
        if(!qq.empty()){
            if(weight >= qq.front()){
                q.push(qq.front());
                weight -= qq.front();
                qq.pop();
            }
            else{
                q.push(-1);
            }
        }
        
        time++;
    }
    
    answer = time;
    return answer;
}