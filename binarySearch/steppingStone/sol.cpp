#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool IsPossible(const vector<int> &rocks, const int min_distance, const int n){
    int num_of_removed = 0;
    int current_distance = 0;
    for(int i = 0;i < rocks.size();i++){
        int tmp_distance = rocks[i] - current_distance;
        if(tmp_distance < min_distance){
            num_of_removed += 1;
        }else{
            current_distance = rocks[i];
        }
        if(num_of_removed > n){ // mid_distance 를 최소로 만들기 위해 없애야 하는 돌의 수가 n 이 넘었다면 불가능한 것
            return false;
        }
    }
    
    return true; //n보다 작게 없애고 min_distance를 만족한다는건 n 만큼 없애고도 할 수 있다는 말이 된다.
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    int high = distance;
    int low = 0, mid;
    sort(rocks.begin(), rocks.end());
    
    while(1){
        mid = (high+low)/2;
        if(mid == answer){
            answer = mid;  
            break;
        }

        if(IsPossible(rocks, mid, n)){
            low = mid; 
            answer = mid; // min_distance를 만족하는 mid 값 중 가장 큰 값을 찾아야 한다.
                          // IsPossible 에서는 mid 값이 최소가 될수 있는지 보는 것이지 mid 가 존재하는 것은 보장하지 않는다.

        }else{
            high = mid;
        }
    }
    
    return answer;
}
