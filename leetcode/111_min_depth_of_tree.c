// 递归
#define MIN(a, b) ((a) > (b) ? (b) : (a))
int minDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (root->left == NULL || root->right == NULL) ? 
           (1 + leftDepth + rightDepth) :
           (1 + MIN(leftDepth, rightDepth));
}
// 迭代
int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    struct TreeNode *queue[100000];
    int rear = 0;
    int front = 0;
    queue[rear++] = root;
    int depth = 1;
    while (front != rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode *cur = queue[front++];
            if (cur->left == NULL && cur->right == NULL) {
                return depth;
            }
            if (cur->left != NULL) {
                queue[rear++] = cur->left;
            }
            if (cur->right != NULL) {
                queue[rear++] = cur->right;
            }
        }
        depth++;
    }
    return depth;
}