#include <stdio.h>

void reverse(char *s, int l, int r)
{
    while (l < r) {
        char ch = s[l];
        s[l++] = s[r];
        s[r--] = ch;
    }
}

char *reverseWords(char * s)
{
    int len = strlen(s);
    reverse(s, 0, len - 1);
    return s;
}

int main()
{
    char *s = "the sky is blue";
    s = reverseWords(s);
    printf("%s\n", s);
    return 0;
}