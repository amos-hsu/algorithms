// 递归方式
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) return NULL;
    struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int pIndex = numsSize / 2;
    pNode->val = nums[pIndex];
    pNode->left = sortedArrayToBST(nums, pIndex);
    pNode->right = sortedArrayToBST(&nums[pIndex + 1], numsSize - pIndex -1);
    return pNode;
}
