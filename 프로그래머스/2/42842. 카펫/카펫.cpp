#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i <= yellow; i++){
        if(yellow % i == 0 && brown == (i + yellow / i)*2 + 4){
            answer.push_back(yellow / i + 2) ;
            answer.push_back(i + 2);
            break;
        }
    }
    
    return answer;
}