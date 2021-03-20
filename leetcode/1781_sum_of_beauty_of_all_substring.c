int beautySum(char * s){
    int res = 0;
    int max;
    int min;
    if (strlen(s) < 3) {
        return 0;
    }
    for (int i = 0; i < strlen(s) - 2; i++) {
        int cnt[CHAR_NUM] = { 0 };
        cnt[s[i] - 'a']++;
        cnt[s[i + 1] - 'a']++;
        for (int j = i + 2; j < strlen(s); j++) {
            max = INT_MIN;
            min = INT_MAX;
            cnt[s[j] - 'a']++;
            // DumpArray(cnt, CHAR_NUM);
            for (int k = 0; k < CHAR_NUM; k++) {
                if (cnt[k] == 0) {
                    continue;
                }
                max = fmax(max, cnt[k]);
                min = fmin(min, cnt[k]);
            }
            // printf("diff=%d\n", max - min);
            res += (max - min);
        }
    }
    return res;
}