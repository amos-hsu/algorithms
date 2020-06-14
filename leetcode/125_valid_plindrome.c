// 验证回文串
bool isPalindrome(char * s)
{
    if (s == NULL) {
        return true;
    }
    int len = strlen(s);
    int l = 0;
    int r = len - 1;
    while (l < r) {
        if (!isalnum(s[l])) {
            l += 1;
            continue;
        }
        if (!isalnum(s[r])) {
            r -= 1;
            continue;
        }
        if (toupper(s[l]) != toupper(s[r])) {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
}