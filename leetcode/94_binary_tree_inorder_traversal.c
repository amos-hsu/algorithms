int TreeSize(struct TreeNode* root)
{
    if (root == NULL) return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

// 方法一：迭代
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * (size));
    struct TreeNode *nodeStack[size + 1];
    struct TreeNode *pNode = root;
    *returnSize = 0;
    int top = -1;
    while (pNode != NULL || top > -1) {
        while (pNode != NULL) {
            nodeStack[++top] = pNode;
            pNode = pNode->left;
        }
        pNode = nodeStack[top--];
        ans[(*returnSize)++] = pNode->val;  // 中序遍历
        pNode = pNode->right;
    }
    return ans;
} // 4ms 70.36% / 7.2MB 65.65%

// 方法二：递归
void InorderBinTree(struct TreeNode *root, int *ans, int *returnSize)
{
    if (root == NULL) return;
    InorderBinTree(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    InorderBinTree(root->right, ans, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * size);
    memset(ans, 0, sizeof(int) * size);
    *returnSize = 0;
    InorderBinTree(root, ans, returnSize);
    return ans;
} // 4ms 70.36% / 7.1MB 72.68%