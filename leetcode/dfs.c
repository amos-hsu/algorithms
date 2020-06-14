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
 
int TreeSize(struct TreeNode *root)
{
    if (root == NULL) return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}
 
int *inorder(struct TreeNode *root, int *retSize)
{
    int size = TreeSize(root);
    *retSize = 0;
    int *ans = (int *)malloc(sizeof(int) * size);
    struct TreeNode *stack[size];
    struct TreeNode *node = root;
    int top = -1;
    while (node != NULL || top != -1) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        ans[(*retSize)++] = node->val;
        node = node->right;
    }
    return ans;
}
 
int *preorder(struct TreeNode *root, int *retSize)
{
    int size = TreeSize(root);
    *retSize = 0;
    int *ans = (int *)malloc(sizeof(int) * size);
    struct TreeNode *stack[size];
    struct TreeNode *node = root;
    int top = -1;
    while (node != NULL || top != -1) {
        while (node != NULL) {
            ans[(*retSize)++] = node->val;
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        node = node->right;
    }
    return ans;
}
 
int main()
{
    /* 用例输入的用一维数组表示的二叉树 */
    int nodeVal[] = {1, null, 2, 3};
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
        if (result[i] == null) continue;
        printf("%d\n", result[i]);
    }
 
    free(result);
    /* 释放测试用例输入参数中申请的内存 */
    for (int i = 0; i < nodeNum; i++) {
        free(node[i]);
    }
    return 0;
}
