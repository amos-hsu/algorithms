int TreeSize(struct TreeNode* root)
{
    if (root == NULL) return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}
// 递归
void postorder(struct TreeNode *root, int *ans, int *ansSize)
{
    if (root == NULL) return;
    postorder(root->left, ans, ansSize);
    postorder(root->right, ans, ansSize);
    ans[(*ansSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * size);
    memset(ans, 0, sizeof(int) * size);
    *returnSize = 0;
    postorder(root, ans, returnSize);
    return ans;
}
// 迭代
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int *ans = (int *)malloc(sizeof(int) * size);
    memset(ans, 0, sizeof(int) * size);
    struct ListNode *stk[size + 1];
    struct ListNode *p = NULL;
    int top = -1;
    *return = 0;
    while (p != NULL || top > -1) {
        while (p != NULL) {
            stk[++top] = p;
            p = p->left;
        }
        p = stk[top--];
        if (p->right == NULL || )
}