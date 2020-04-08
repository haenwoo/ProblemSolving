#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long max = times[0]*n;
    long long mid;
    long long min = 0;

    while(1){
        mid = (max + min) / 2;
        long long checked_num = 0;

        if(answer == mid) break;
        
        for(int i = 0;i < times.size();i++){
            checked_num += mid/times[i];
        }
        
        if(checked_num < n){
            min = mid+1;
        }else if(checked_num >= n){
            max = mid;
            answer = mid;
        }
            
    }   
    
    return answer;
}