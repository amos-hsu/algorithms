public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
//原始代码，没有开辟新空间
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
            while(pNode.next != null) {
                if(pNode.next.left == pNode)
                    return pNode.next;
                pNode = pNode.next;
            }
            return null;
        }
    }
}
