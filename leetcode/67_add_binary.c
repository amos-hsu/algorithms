char *addBinary(char * a, char * b)
{
    if (a == NULL || b == NULL) return NULL;
    int aLen = strlen(a);
    int bLen = strlen(b);
    int ansLen = (((aLen >= bLen) ? aLen : bLen) + 1);
    char *ans = (char *)malloc(sizeof(char) * (ansLen + 1));
    ans[ansLen] = '\0';
    int carry = 0, sum = 0;
    int i, j, k;
    for (i = aLen - 1, j = bLen - 1, k = ansLen - 1; 
         k >= 0; i--, j--, k--) {
        if (i < 0 && j < 0) {
            sum = carry;
        } else if (i < 0) {
            sum = b[j] + carry - '0';
        } else if (j < 0) {
            sum = a[i] + carry - '0';
        } else {
            sum = a[i] + b[j] + carry - '0' * 2;
        }
        carry = sum / 2;
        ans[k] = sum % 2 + '0';
    }
    if (ans[0] == '0') {
        return &ans[1];
    }
    return ans;
}