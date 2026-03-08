#include <iostream>
#include <algorithm>

using namespace std;

int mxcnt = 0;

bool check(int x, int y, int X, int Y){
    return x >= 0 && x < X && y >= 0 && y < Y;
}

void dfs(int x, int y, int X, int Y, int (&graph)[8][8], bool (&visited)[8][8]){
    graph[x][y] = 2;
    visited[x][y] = true;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check(nx,ny,X,Y) && !visited[nx][ny] && graph[nx][ny] == 0){
            dfs(nx,ny,X,Y,graph,visited);
        }
    }
}

void cal(int x, int y, int (&graph)[8][8]){
    bool visited[8][8] = {false};
    int g[8][8];

    int cnt = 0;

    for(int i = 0; i < x; i++){
        for(int t = 0; t < y; t++){
            g[i][t] = graph[i][t];
        }
    }


    for(int i = 0; i < x; i++){
        for(int t = 0; t < y; t++){
           if(!visited[i][t] && g[i][t] == 2){
            dfs(i,t,x,y,g,visited);
           }
        }
    }

    for(int i = 0; i < x; i++){
        for(int t = 0; t < y; t++){
           if(g[i][t] == 0){
            cnt++;
           }
        }
    }

    mxcnt = max(mxcnt,cnt);
}

void back(int X, int Y, int (&graph)[8][8], int x, int y, int cnt){
    if(cnt == 3){
        cal(X,Y,graph);
        return;
    }

    for(int i = x; i < X; i++){
        if(i == x) {
            y = y;
        }
        else{
            y = 0;
        
        }

        for(int t = y; t < Y; t++){
            if(graph[i][t] == 0){
                graph[i][t] = 1;
                back(X,Y,graph,i,t,cnt+1);
                graph[i][t] = 0;
            }
        }
    }
}

int main(){
    int x,y;

    mxcnt = 0;

    cin >> x >> y;

    int graph[8][8];

    for(int i = 0; i < x; i++){
        for(int t = 0; t < y; t++){
            cin >> graph[i][t];
        }
    }

    back(x,y,graph,0,0,0);

    cout << mxcnt;
}