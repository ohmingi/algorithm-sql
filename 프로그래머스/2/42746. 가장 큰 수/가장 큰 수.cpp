#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b){
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i = 0; i < numbers.size(); i++){
        string s = to_string(numbers[i]);
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < v.size(); i++){
        answer += v[i];
    }
    
    if(answer[0] == '0'){
        answer = '0';
    }

    return answer;
}