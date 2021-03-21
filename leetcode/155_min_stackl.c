#define MAX_SIZE 10000
typedef struct {
    int data[MAX_SIZE];
    int min[MAX_SIZE];
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s = (MinStack *)malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    int min = (obj->top == -1) ? INT_MAX : obj->min[obj->top];
    obj->top++;
    obj->data[obj->top] = val;
    obj->min[obj->top] = fmin(min, val);
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    if (obj != NULL) {
        free(obj);
    }
}