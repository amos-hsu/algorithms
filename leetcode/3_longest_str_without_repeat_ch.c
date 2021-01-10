int lengthOfLongestSubstring(char * s)
{
    int hash[128] = { 0 };
    int l = 0;
    int r = 0;
    int max = 0;
    while (s[r] != '\0') {
        max = max > (r - l + 1) ? max : (r - l + 1);
        hash[s[r]] = 1; // update opr in window: mark right elements int hash table
        // printf("%c is in win\n", s[r]);
        // add new element opr: add right into win
        r++;
        // printf("window: left(%d) right(%d)\n", l, r);
        while (hash[s[r]] != 0) { // check whether need shrink win
            hash[s[l]] = 0;
            l++;
        } // add right into win success
    }
    return max;
}

/* solution 2 */
int lengthOfLongestSubstring(char * s)
{
    int hash[128] = { 0 };
    int l = 0;
    int r = 0;
    int ans = 0;
    int len = 0;
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }
    while (s[r] != '\0') {
        len++;
        hash[s[r]] = 1;
        if (ans < len) {
            ans = len;
        }
        r++;
        while (s[r] != '\0' && hash[s[r]] == 1) {
            hash[s[l]] = 0;
            l++;
            len--;
        }
    }
    return ans;
}