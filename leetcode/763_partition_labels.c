int* partitionLabels(char * S, int* returnSize){
    int cnt[26] = { 0 };
    int len = strlen(S);
    int l = 0;
    int r = 0;
    int *res = (int *)malloc(sizeof(int) * len);
    int resIdx = 0;
    int subLen = 0;
    for (int i = 0; i < len; i++) {
        cnt[S[i] - 'a']++;
    }
    while (r < len) {
        char ch = S[r];
        r++;
        subLen++;
        // printf("l=%d r=%d idx=%d subLen=%d\n", l, r, resIdx, subLen);
        if (ch = S[l]) {
            cnt[S[l] - 'a']--;
        }
        while (l < r && cnt[S[l] - 'a'] == 0) {
            l++;
        }
        if (r == l) {
            res[resIdx++] = subLen;
            subLen = 0;
        }
    }
    *returnSize = resIdx;
    return res;
}