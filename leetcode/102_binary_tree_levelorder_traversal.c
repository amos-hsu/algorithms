#define MAXSIZE 10000
int MaxDepthOfTree(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    int left = MaxDepthOfTree(root->left);
    int right = MaxDepthOfTree(root->right);
    return ((left > right) ? left : right) + 1;
}
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int depth = MaxDepthOfTree(root); // 返回的二维数组行数
    if (depth == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *colSizes = (int *)malloc(sizeof(int) * depth); // 返回的二维数组每行列数
    int **res = (int **)malloc(sizeof(int *) * depth);   // 返回的二维数组
    struct TreeNode *queue[MAXSIZE];
    int rear = 0;
    int front = 0;
    int level = 0;
    int i;
    queue[rear++] = root;
    while (front != rear) {
        int col = rear - front;
        colSizes[level] = col;
        res[level] = (int *)malloc(sizeof(int) * col);
        for(i = 0; i < col; i++) {
            struct TreeNode *cur = queue[front++];
            res[level][i] = cur->val;
            if (cur->left != NULL) queue[rear++] = cur->left;
            if (cur->right != NULL) queue[rear++] = cur->right;
        }
        level++;
    }
    *returnSize = depth;
    *returnColumnSizes = colSizes;
    return res;
}