/**
 * 二叉排序树
 */
class Node{
    public int val;
    public Node left;
    public Node right;
    public Node(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}
public class BinartTree{
    private Node root;
    public BinartTree(){
        root = null;
    }

    //插入二叉排序树
    public void insert(int val){
        Node newNode = new Node(val);
        if(root == null)
            root = newNode;
        else{
            Node cur = root;
            Node parent;
            while(true){
                parent = cur;
                if(val<cur.val){
                    cur = cur.left;
                    if(cur == null){
                        parent.left = newNode;
                        return;
                    }
                }else{
                    cur = cur.right;
                    if(cur = null){
                        parent.right = newNode;
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
    public void inOrder(Node localRoot){
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
    public void preOrder(Node localRoot){
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
    public void postOrder(Node localRoot){
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