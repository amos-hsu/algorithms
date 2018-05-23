/**
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * 
 * 思路：
 * 若该节点存在右子树，则下一个节点为右子树最左边的节点；
 * 若该节点没有右子树，分两种情况：
 *      若该节点是父节点的左孩子，则下一个节点为其父节点；
 *      若该节点是父节点的右孩子，则沿着父节点向上遍历：
 *              如果遍历直到找到一个节点为其父节点的左孩子，下一个节点是这个节点；
 *              否则遍历到根节点仍没有找到，返回null。
 */

public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode){
        if(pNode == null) return null;
        if(pNode.right != null){
            TreeLikNode node = pNode.right;
            while(node.left != null)
                node = node.left;
            return node;
        }else{
            while(pNode.next != null){
                TreeLinkNode parent = pNode.next;
                if(parent.left == pNode)
                    return parent;
                pNode = pNode.next;
            }
            return null;
        }
    }
}