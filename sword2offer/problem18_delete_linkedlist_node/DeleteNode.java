class ListNode{
    int val;
    ListNode next;
    ListNode(int val){
        this.val = val;
    }
}
public class Solution{
    
    //给定一个链表和一个节点对象，在O(1)时间内删除该节点
    public void deleteNode(ListNode head, ListNode delteNode){
        if(head == nul || head.next == null || deleteNode == null)
            return ;
        if(deleteNode.next != null){
            ListNode nextNode = deleteNode.next;
            deleteNode.val = nextNode.val;
            deleteNode.next = nextNode.next;
        }
        else if(head == deleteNode){
            head = null;
        }
        else{
            ListNode curNode = head;
            while(curNode.next != deleteNode){
                curNode = curNode.next;
            }
            curNode.next = null;
        }
    }
}