void DumpStk(char *stk, int top)
{
    if (top == -1) {
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%c ", stk[i]);
    }
    printf("\n");
}

bool isValid(char * s)
{
    char stk[10000] = { 0 };
    int top = -1;
    if (s[0] == 'b' || s[0] == 'c' || s[1] == 'c' || strlen(s) % 3 != 0) {
        return false;
    }
    for (int i = 0; i < strlen(s); i++) {
        printf("s[%d]=%c\n", i, s[i]);
        if (s[i] != 'c') {
            stk[++top] = s[i];
            // printf("stk[%d]=%c\n", top, stk[top]);
            // DumpStk(stk, top);
        } else if (s[i] == 'c' && top != -1 && stk[top] == 'b' && stk[top - 1] =='a') {
            top -= 2;
            // DumpStk(stk, top);
        } else {
            return false;
        }
    }
    // printf(">> top = %d\n", top);
    if (top == -1) {
        return true;
    }
    return false;
}