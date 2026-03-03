#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int v[100001];

void bfs(int n,int k){
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x == k){
            break;
        }

        if(x - 1 >= 0){
            if(v[x - 1] == -1){   
                q.push(x - 1);
                v[x - 1] = v[x] + 1;
            }   
        }
        if(x + 1 <= 100000){
            if(v[x + 1] == -1){
                q.push(x + 1);
                v[x + 1] = v[x] + 1;
            } 
        }
        if(x * 2 <= 100000){
            if(v[x * 2] == -1){
                q.push(x * 2);
                v[x * 2] = v[x] + 1;
            } 
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;

    fill(v,v+100001,-1);

    v[n] = 0;
    bfs(n,k);

    cout << v[k];
}