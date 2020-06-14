struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *cur = &dummy; // slow ptr
    struct ListNode *fast = cur->next; // fast ptr
    while (fast != NULL && fast->next != NULL) {
        if (fast->val == fast->next->val) {
            while(fast != NULL && fast->next != NULL && fast->val == fast->next->val){
                fast = fast->next;
            }
            fast = fast->next;
            cur->next = fast;
        } else {
            cur = fast;
            fast = fast->next;
        }
    }
    return dummy.next;
}