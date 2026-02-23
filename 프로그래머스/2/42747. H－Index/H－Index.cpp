#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater());
    
    for(int i = 0; i <= citations[0]; i++){
        if(i > citations.size()){
            break;
        }
        
        for(int t = 0; t < citations.size() - 1; t++){
            if(t + 1 == i && citations[t] >= i && citations[t + 1] <= i){
                answer = i;
            }
        }
        
        if(i == citations.size() && citations[citations.size() - 1] >= i){
            answer = citations.size();
        }
    }
    return answer;
}