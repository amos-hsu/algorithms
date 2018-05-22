/**
 * 二叉排序树
 */
class TreeNode{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}
public class BinartTree{
    private TreeNode root;
    public BinartTree(){
        root = null;
    }

    //插入二叉排序树
    public void insert(int val){
        TreeNode newTreeNode = new TreeNode(val);
        if(root == null)
            root = newTreeNode;
        else{
            TreeNode cur = root;
            TreeNode parent;
            while(true){
                parent = cur;
                if(val<cur.val){
                    cur = cur.left;
                    if(cur == null){
                        parent.left = newTreeNode;
                        return;
                    }
                }else{
                    cur = cur.right;
                    if(cur = null){
                        parent.right = newTreeNode;
                        return;
                    }
                }
            }
        }
    }

    //数值输入排序二叉树
    public buildTree(int[] data){
        for(int i=0; i<data.length; i ++){
            insert(data[i]);
        }
    }

    //中序遍历
    private void inOrder(TreeNode localRoot){
        if(localRoot != null){
            inOrder(localRoot.left);
            System.out.print(localRoot.val+" ");
            inOrder(localRoot.right);
        }
    }
    public void inOrder(){
        this.inOrder(this.root);
    }

    //先序遍历
    private void preOrder(TreeNode localRoot){
        if(localRoot != null){
            System.out.print(localRoot.val+" ");
            preOrder(localRoot.left);
            preOrder(localRoot.right);
        }
    }
    public void preOrder(){
        this.preOrder(this.root);
    }

    //后序遍历
    private void postOrder(TreeNode localRoot){
        if(localRoot != null){
            postOrder(localRoot.left);
            postOrder(localRoot.right);
            System.out.print(localRoot.val+" ");
        }
    }
    public void postOrder(){
        this.postOrder(this.root);
    }
}