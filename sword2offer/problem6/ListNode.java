//链表

class Node{
    int val;
    Node next = null;
    Node(int val){
        this.val = val;
    }
}
class MyLinkedList{
    Node head = null;
    /**向链表插入数据
     * @param val:插入的数据内容
     */
    public void addToTail(int val){
        Node newNode = new Node(val);
        if(head == null){
            head = newNode;
            return;
        }
        Node tmp = head;
        while(tmp.next != null){
            tmp = tmp.next;
        }
        tmp.next = newNode;
    }
    /**删除第index个结点
     * @param index:待删除结点
     * @return true:成功 
     */
    public Boolean deleteNode(int index){
        
    }
}