#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PopFirstElement(vector<int> &heap){
    int tmp = heap[0];
    heap[0] = heap[heap.size()-1];
    heap[heap.size()-1] = tmp;
    heap.pop_back();
}

void RunOperator(string op, vector<int> &heap){
    if(op[0] == 'I'){
        int num = atoi(op.substr(2).c_str());
        heap.push_back(num);
    }else{
        if(heap.empty())return;
        if(op.substr(2) == "-1"){
            make_heap(heap.begin(), heap.end(), greater<int>());
            PopFirstElement(heap);
        }else{
            make_heap(heap.begin(), heap.end(), less<int>());
            PopFirstElement(heap);
        }
    }
}

int GetMin(vector<int> &heap){
    if(heap.empty()) return 0;
    make_heap(heap.begin(), heap.end(), greater<int>());
    return heap[0];
}

int GetMax(vector<int> &heap){
    if(heap.empty()) return 0;
    make_heap(heap.begin(), heap.end(), less<int>());
    return heap[0];
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> heap;
    
    for(int i = 0;i < operations.size();i++){    
        RunOperator(operations[i], heap);
    }
    answer.push_back(GetMax(heap));
    answer.push_back(GetMin(heap));
    return answer;
}
