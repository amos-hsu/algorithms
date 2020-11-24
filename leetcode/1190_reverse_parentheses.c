void ReverseString(char *s, int left, int right)
{
    while(left < right) {
        char ch = s[left];
        s[left++] = s[right];
        s[right--] = ch;
    }
}

char * reverseParentheses(char * s)
{
    int stk[1000] = { 0 };
    int top = -1;
    char *res = malloc(sizeof(char) * strlen(s) + 1);
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stk[++top] = i;
        } else if (s[i] == ')') {
            ReverseString(s, stk[top--] + 1, i - 1);
        }
    }
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] != '(' && s[j] != ')') {
            res[count++] = s[j]; 
        }
    }
    res[count] = '\0';
    return res;
}