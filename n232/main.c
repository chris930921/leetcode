// Add to List 232. Implement Queue using Stacks

typedef struct {
    int* list;
    int startIndex;
    int endIndex;
    int tailIndex;
    int maxSize;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue* newData = (MyQueue*)calloc(1, sizeof(MyQueue));
    newData->list = (int*)calloc(maxSize + 1, sizeof(int));
    newData->startIndex = 0;
    newData->endIndex = 0;
    newData->maxSize = maxSize;
    return newData;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    int nextIndex;
    if(obj->endIndex == obj->maxSize){
        nextIndex = 0;
    }else{
        nextIndex = obj->endIndex + 1;
    }
    
    if(nextIndex == obj->startIndex){
        return;
    }else{
        obj->list[obj->endIndex] = x;
        obj->endIndex = nextIndex;
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int result = obj->list[obj->startIndex];
    
    if(obj->startIndex == obj->maxSize){
        obj->startIndex = 0;
    }else{
        obj->startIndex++;
    }
    
    return result;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->list[obj->startIndex];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->startIndex == obj->endIndex;
}

void myQueueFree(MyQueue* obj) {
    free(obj->list);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */