int removeElement(int* nums, int numsSize, int val){
    if (nums == NULL || numsSize == 0) return 0;
    int index = 0;
    int i;
    while (i < numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize - 1];
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
}