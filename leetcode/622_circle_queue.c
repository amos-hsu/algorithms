typedef struct {
    int *q;
    int size;
    int front;
    int rear;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    if (obj == NULL) {
        return NULL;
    }
    obj->q = (int *)malloc((k + 1) * sizeof(int));
    if (obj->q == NULL) {
        free(obj);
        return NULL;
    }
    obj->size = k + 1;
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // printf("EN ==front=%d rear=%d v=%d\n", obj->front, obj->rear, value);
    if (obj->front == (obj->rear + 1) % obj->size) {
        // printf("EN ==FULL\n");
        return false;
    }
    obj->q[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    // printf("EN ++front=%d rear=%d\n", obj->front, obj->rear);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // printf("DE ==front=%d rear=%d\n", obj->front, obj->rear);
    if (obj->front == obj->rear) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->size;
    // printf("DE ---front=%d rear=%d\n", obj->front, obj->rear);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj == NULL || obj->front == obj->rear) {
        return -1;
    }
    return obj->q[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj == NULL || obj->front == obj->rear) {
        return -1;
    }
    return obj->q[(obj->rear - 1 + obj->size) % obj->size];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == (obj->rear + 1) % obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) {
        return;
    }
    if (obj->q != NULL) {
        free(obj->q);
        obj->q = NULL;
    }
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/