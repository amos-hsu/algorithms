int TreeSize(struct TreeNode* root)
{
    if (root == NULL) return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}
// 迭代
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * size);
    struct TreeNode *stack[size + 1];
    struct TreeNode *pNode = root;
    *returnSize = 0;
    int top = -1;
    while (pNode != NULL || top != -1) {
        while (pNode != NULL) {
            ans[(*returnSize)++] = pNode->val;  // 前序遍历
            stack[++top] = pNode;
            pNode = pNode->left;
        }
        pNode = stack[top--];
        pNode = pNode->right;
    }
    return ans;
}
// 递归
void Preorder(struct TreeNode *root, int *ans, int *ansSize)
{
    if (root == NULL) return;
    ans[(*ansSize)++] = root->val;
    Preorder(root->left, ans, ansSize);
    Preorder(root->right, ans, ansSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * size);
    memset(ans, 0, sizeof(int) * size);
    *returnSize = 0;
    Preorder(root, ans, returnSize);
    return ans;
}