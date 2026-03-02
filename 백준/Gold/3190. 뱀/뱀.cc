#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int mx = 0;
int my = 1;

int graph[101][101];

void check(int x, int y){
    if(mx == 0){
        if(my == 1){
            mx = 1;
            my = 0;
        }
        else if(my == -1){
            mx = -1;
            my = 0;
        }
    }
    else if(my == 0){
        if(mx == 1){
            mx = 0;
            my = -1;
        }
        else if(mx == -1){
            mx = 0;
            my = 1;
        }
    }
}

void check1(int x, int y){
    if(mx == 0){
        if(my == 1){
            mx = -1;
            my = 0;
        }
        else if(my == -1){
            mx = 1;
            my = 0;
        }
    }
    else if(my == 0){
        if(mx == 1){
            mx = 0;
            my = 1;
        }
        else if(mx == -1){
            mx = 0;
            my = -1;
        }
    }
}

int main() {
    queue<pair<int, char>> q;
    deque<pair<int,int>> dq;

   int n, k;
   cin >> n >> k;

   for(int i = 0; i < k; i++){
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = 2;
   }

   int l;
   cin >> l;
   for(int i = 0; i < l; i++){
    int a;
    char b;
    cin >> a;
    cin >> b;
    q.push({a, b});
   }


   int hx = 0;
   int hy = 0;

   dq.push_front({0,0});
    graph[0][0] = 1;

   int cnt = 0;

   while(true){
    cnt++;

    hx += mx;
    hy += my;

    if(hx < 0 || hx >= n || hy < 0 || hy >= n) break;

    if(graph[hx][hy] == 1){
        break;
    }

     if(graph[hx][hy] == 2){
        dq.push_front({hx,hy});
        graph[hx][hy] = 1;
    }
    else{
        dq.push_front({hx,hy});
        graph[hx][hy] = 1;
        pair<int,int> a = dq.back();
        graph[a.first][a.second] = 0;
       dq.pop_back();
    }

    if(!q.empty() && cnt == q.front().first){
        if(q.front().second == 'D'){
            check(mx,my);
        }
        else if(q.front().second == 'L'){
            check1(mx,my);
        }
        q.pop();
    }
   }

   cout << cnt;
}