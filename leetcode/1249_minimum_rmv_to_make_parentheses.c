void DumpS(char *s)
{
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

char * minRemoveToMakeValid(char * s)
{
    if (s == NULL || strlen(s) == 0) {
        return "";
    }
    char *ans = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    int stk[strlen(s)];
    int top = -1;
    int count = 0;
    (void)memset(ans, 0, strlen(s) + 1);
    (void)memset(stk, 0, sizeof(stk));
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stk[++top] = i;
        } else if (s[i] == ')') {
            if (top == -1) {
                s[i] = -1; 
            } else if (s[stk[top]] == '(') {
                top--;
            }
        }
    }
    // DumpS(s);
    while (top != -1) {
        s[stk[top]] = -1;
        top--;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == -1) {
            continue;
        }
        ans[count++] = s[i];
    }
    ans[count] = '\0';
    return ans;
}