struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode dummyNode;
    dummyNode.next = head;
    struct ListNode *left = &dummyNode;
    struct ListNode *right = &dummyNode;
    int i = 0;
    for(i = 0; i < n; i++) {
        right = right->next;
    }
    while(right->next != NULL) {
        right = right->next;
        left = left->next;
    }
    left->next = left->next->next;
    return dummyNode.next;
}