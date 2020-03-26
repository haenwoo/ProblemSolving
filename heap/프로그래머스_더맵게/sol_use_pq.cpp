#include <string>
#include <vector>
#include <queue>

using namespace std;

void MixFood(priority_queue<long long, vector<long long>, greater<long long> > &scoville_heap){
    long long scoville_of_first = scoville_heap.top();
    scoville_heap.pop();
    long long scoville_of_second = scoville_heap.top();
    scoville_heap.pop();
    
    long long new_scoville = scoville_of_first + scoville_of_second*2;
    scoville_heap.push(new_scoville);
    return;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long> > scoville_heap;
    
    for(int i = 0;i < scoville.size();i++){
        scoville_heap.push((long long)scoville[i]);
    }
    
    while(1){
        if(scoville_heap.top() < K){
            if(scoville_heap.size() < 2){
                answer = -1;
                break;
            }
            MixFood(scoville_heap);
            answer +=1;
        }else{
            break;
        }
    }
    
    
    return answer;
}