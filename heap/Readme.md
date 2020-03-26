## Heap
#### 완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 자료구조이다.
#### 여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조이다.
#### 힙은 일종의 반정렬 상태(느슨한 정렬 상태) 를 유지한다.
#### 큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있다는 정도
#### 간단히 말하면 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리를 말한다.
#### 힙 트리에서는 중복된 값을 허용한다. (이진 탐색 트리에서는 중복된 값을 허용하지 않는다.)


### 힙(heap)의 종류
#### 최대 힙(max heap)
- 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
- key(부모 노드) >= key(자식 노드)

#### 최소 힙(min heap)
- 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리
- key(부모 노드) <= key(자식 노드)


#### 구현 예
- 최소 힙, Vector<int> 구조의 Priority Queue
```
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


```

#### MakeHeap 을 할때는 logN 의 복잡도로 수행이 된다.
