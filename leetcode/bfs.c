#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define null -1

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

int main(void)
{
    /* 用例：一维数组表示的二叉树 */
    int nodeVals[] = { 3, 9, 20, null, null, 15, 7 };
    int nodeNum = sizeof(nodeVals) / sizeof(int);
    struct TreeNode *node[nodeNum];

    /* 申请测试用例需要的内存，根据用例输入初始化 */
    for (int i = 0; i < nodeNum; i++) {
        node[i] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node[i]->val = nodeVals[i];
        node[i]->right = NULL;
        node[i]->left = NULL;
    }

    /* 将一维数组转换成二叉树 */
    int nullNodeNum = 0;
    int left;
    int right;
    for (int i = 0; i < nodeNum; i++) {
        if (nodeVals[i] == null) {
            nullNodeNum++;
            continue;
        }
        left = i * 2 - 2 * nullNodeNum + 1;
        right = i * 2 - 2 * nullNodeNum + 2;
        if (left < nodeNum) {
            node[i]->left = node[left];
        }
        if (right < nodeNum) {
            node[i]->right = node[right];
        }
    }
    /* 运行测试用例给出的接口函数 */
    int resSize = 0;
    int *resColSizes;
    int **result = levelOrder(node[0], &resSize, &resColSizes);
    if (result == NULL) return 0;
    for (int i = 0; i < resSize; i++) {
        for (int j = 0; j < resColSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    free(resColSizes);

    /* 释放测试用例输入参数中申请的内存 */
    for (int i = 0; i < nodeNum; i++) {
        free(node[i]);
    }
    return 0;
}
