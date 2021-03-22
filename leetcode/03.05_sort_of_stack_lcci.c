typedef struct {
    int v[5000];
    int vt[5000];
    int top;
    int topt;
} SortedStack;

SortedStack* sortedStackCreate() {
    SortedStack *obj = malloc(sizeof(SortedStack));
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, sizeof(SortedStack));
    obj->top = -1;
    obj->topt = -1;
    return obj;
}

void sortedStackPush(SortedStack* obj, int val) {
    if (obj->top == -1 || val < obj->v[obj->top]) {
        obj->v[++obj->top] = val;
        return;
    }
    while (obj->top != -1 && val > obj->v[obj->top]) {
        obj->vt[++obj->topt] = obj->v[obj->top--];
    }
    obj->v[++obj->top] = val;
    while (obj->topt != -1) {
        obj->v[++obj->top] = obj->vt[obj->topt--];
    }
}

void sortedStackPop(SortedStack* obj) {
    if (obj->top == -1) {
        return;
    }
    obj->top--;
}

int sortedStackPeek(SortedStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    return obj->v[obj->top];
}

bool sortedStackIsEmpty(SortedStack* obj) {
    return (obj->top == -1);
}

void sortedStackFree(SortedStack* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your SortedStack struct will be instantiated and called as such:
 * SortedStack* obj = sortedStackCreate();
 * sortedStackPush(obj, val);
 
 * sortedStackPop(obj);
 
 * int param_3 = sortedStackPeek(obj);
 
 * bool param_4 = sortedStackIsEmpty(obj);
 
 * sortedStackFree(obj);
*/