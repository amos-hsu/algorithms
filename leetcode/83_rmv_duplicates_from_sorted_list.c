struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *pre = head;
    struct ListNode *cur = head->next;
    while (cur != NULL) {
        if (pre->val == cur->val) {
            cur = cur->next;
            pre->next = cur;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}