#include <string>
#include <vector>

using namespace std;

void MakeHeapToPush(vector<int> &heap){
    int child = heap.size() - 1;
    
    int root = -1;
    while(child > 0) {
        if(child % 2 == 0) root = child / 2 - 1;
        else root = child / 2;
        if(heap[child] < heap[root]) {
            int temp = heap[child];
            heap[child] = heap[root];
            heap[root] = temp;
            child = root;
        }
        else break;
    }    
}

void MakeHeapToPop(vector<int> &heap){
    int root = 0;

    while(true) {
        if(root > (heap.size()/2))break;
        int child = root*2 + 1;
        
        if(child > heap.size()-1) break;
        
        if(child < heap.size()-1 && heap[child] > heap[child+1]){
            child+=1;
        }
   
        if(heap[child] < heap[root]) {
            int temp = heap[child];
            heap[child] = heap[root];
            heap[root] = temp;
            root = child;
        }else{
            break;
        }
        
    }
}

void HeapPush(vector<int> &heap, int n) {
    heap.push_back(n);
    MakeHeapToPush(heap);
}

int HeapPop(vector<int> &heap) {
    int value = heap[0];

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    MakeHeapToPop(heap);

    return value;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int s = 0;
    vector<int> v;

    for(int i = 0; i < scoville.size(); i++) {
        HeapPush(v, scoville[i]);
    }

    while(v.size() > 1) {
        answer++;
        int food1 = HeapPop(v);
        int food2 = HeapPop(v);
        HeapPush(v, food1 + (food2 * 2));
        if(v[0] >= K) return answer;
    }

    return -1;
}
