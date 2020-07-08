#include <stdio.h>
#include <string.h>
#include <assert.h>

void Reverse(char *s, int l, int r)
{
    while (l < r) {
        char ch = s[l];
        s[l++] = s[r];
        s[r--] = ch;
    }
}

char * reverseWords(char * s)  // double ptr
{
    int l = 0;
    int r = 0;
    int len = strlen(s);
    while (r < len) {
        if (s[r] == ' ') {
            Reverse(s, l, r - 1);
            l = r + 1;
        }
        if (r == len -1) {
            Reverse(s, l, r);
        }
        r += 1;
    }
    return s;
}

int main()
{
    const char *s = "Let's take LeetCode contest";
    s = reverseWords(s);
    printf("%s\n", s);
    return 0;
}