#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> answer(v.size());
    
   
    stack<int> st;
    
    for(int i = 0; i < v.size(); i++){
        if(st.empty()){
            st.push(i);
            continue;
        }
        
        while(v[st.top()] < v[i]){
            answer[st.top()] = v[i];
            st.pop();
            
            if(st.empty()) break;
        }
        st.push(i);
        
    }
    
    while(!st.empty()){
        answer[st.top()] = -1;
        st.pop();
    }
    
    return answer;
}