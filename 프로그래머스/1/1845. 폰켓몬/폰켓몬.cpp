#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    vector<int> v;
    
    for(int i = 0; i < nums.size(); i++){
        auto it = find(v.begin(), v.end(), nums[i]);
        
        if(it == v.end()){
            answer++;
            v.push_back(nums[i]);
        }

    }
    
    if(answer > nums.size() / 2){
        answer = nums.size() / 2;
    }
    return answer;
}