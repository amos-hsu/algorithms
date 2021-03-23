// TODO: to resolve by dynamic programming
int* countBits(int num, int* returnSize){
    int *res = malloc(sizeof(int) * (num + 1));
    memset(res, 0, sizeof(int) * (num + 1));
    for (int i = 0; i <= num; i++) {
        int n = i;
        while (n != 0) {
            if (n & 0x1 == 1) {
                res[i]++;
            }
            n >>= 1;
        }
    }
    *returnSize = num + 1;
    return res;
}
