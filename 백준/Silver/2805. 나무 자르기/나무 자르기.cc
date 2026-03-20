#include <iostream>
#include <vector>

using namespace std;

int ans;

void binary_search(int mid, int left, int right, vector<int> &v, int m){
    if(left > right){
        cout << ans << endl;
        return;
    } 

    long long cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > mid){
            cnt += v[i] - mid;
        }
    }



    if(cnt >= m){
        ans = mid;
        left = mid + 1;
        mid = (left + right) / 2;
        binary_search(mid, left, right, v, m);
    }

    if(cnt < m){
        right = mid - 1;
        mid = (left + right) / 2;
        binary_search(mid, left, right, v, m);
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    int Max = 0;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);

        if(a > Max) Max = a;
    }

    int mid = Max / 2;

    binary_search(mid, 0, Max, v, m);

}