// 嵌套数组
int arrayNesting(int* nums, int numsSize){
    int max = 0;
    int cnt = 0;
    int visited[numsSize];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        cnt = 1;
        if (visited[n] != 0) {
            continue;
        }
        // printf(">> nums[%d]=%d\n", i, nums[i]);
        while (nums[n] != nums[i]) {
            visited[n]++;
            cnt++;
            // printf("n=%d nums[%d]=%d cnt=%d\n", n, n, nums[n], cnt);
            n = nums[n];
        }
        max = fmax(cnt, max);
    }
    return max;
}