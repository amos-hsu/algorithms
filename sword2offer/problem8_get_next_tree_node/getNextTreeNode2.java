public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode parent = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
//原始代码，没有开辟新空间
//问题：破坏了原来的树结构
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode) {
        if(pNode == null) return null;
        if(pNode.right != null) {
            pNode = pNode.right;
            while(pNode.left != null)
                pNode = pNode.left;
            return pNode;
        }
        else{
            while(pNode.parent != null) {
                if(pNode.parent.left == pNode)
                    return pNode.parent;
                pNode = pNode.parent;
            }
            return null;
        }
    }
}
