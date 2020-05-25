#include "securec.h"
#include "securectype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

/* *
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define null 0xffffff

int TreeSize(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

int MaxDepthOfTree(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    int left = MaxDepthOfTree(root->left);
    int right = MaxDepthOfTree(root->right);
    return ((left > right) ? left : right) + 1;
}

#define MAXSIZE 1000
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int **res = NULL;
    int *colSizes = NULL;
    int depth = MaxDepthOfTree(root); // 返回的二维数组行数
    if (depth < 0) {
        return NULL;
    }
    colSizes = (int *)malloc(sizeof(int) * depth); // 返回的二维数组每行列数
    res = (int **)malloc(sizeof(int *) * depth);   // 返回的二维数组
    struct TreeNode *queue[MAXSIZE];
    int rear = 0;
    int front = 0;
    int level = 0;
    int i;
    queue[rear++] = root;
    while (front != rear) {
        int col = rear - front;
        colSizes[level++] = col;
        for(i = 0; i < col; i++) {
            
        }
    }

    *returnSize = depth;
    *returnColumnSizes = colSizes;
    return res;
}

int main()
{
    /* 用例输入的用一维数组表示的二叉树 */
    int nodeVal[] = { 3, 9, 20, null, null, 15, 7 };
    int nodeNum = sizeof(nodeVal) / sizeof(int);
    struct TreeNode *node[nodeNum];

    /* 申请测试用例输入参数中需要的内存并根据用例输入初始化 */
    for (int i = 0; i < nodeNum; i++) {
        node[i] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node[i]->val = nodeVal[i];
        node[i]->right = NULL;
        node[i]->left = NULL;
    }

    /* 将用例的一维数组转换成二叉树 */
    int absentNum = 0;
    int left;
    int right;
    for (int i = 0; i < nodeNum; i++) {
        if (nodeVal[i] == null) {
            absentNum++;
            continue;
        }
        left = i * 2 - 2 * absentNum + 1;
        right = i * 2 - 2 * absentNum + 2;
        if (left < nodeNum) {
            node[i]->left = node[left];
        }
        if (right < nodeNum) {
            node[i]->right = node[right];
        }
    }
    /* 运行测试用例给出的接口函数 */
    int resSize = 0;
    int *result = preorder(node[0], &resSize);
    for (int i = 0; i < resSize; i++) {
        if (result[i] == null)
            continue;
        printf("%d\n", result[i]);
    }

    free(result);
    /* 释放测试用例输入参数中申请的内存 */
    for (int i = 0; i < nodeNum; i++) {
        free(node[i]);
    }
    return 0;
}
