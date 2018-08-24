/**
 * 输入一个链表，反转链表后，输出新链表的表头。
 */


public class ReverseLinkedList{
    public ListNode ReverseList(ListNode head) {
        ListNode reverseHead = null;
        ListNode node = head;
        ListNode preNode = null;
        while(node != null){
            ListNode nextNode = node.next;
            if(nextNode == null){
                reverseHead = node;
            }
            node.next = preNode;
            preNode = node;
            node = nextNode;
        }
        return reverseHead;
    }
}

class ListNode{
    int val;
    Node next = null;
    ListNode(int val){
        this.val = val;
    }
}