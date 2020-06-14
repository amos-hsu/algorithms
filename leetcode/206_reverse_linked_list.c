struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *preNode = NULL;
    struct ListNode *curNode = head;
    struct ListNode *nextNode = NULL;
    while (curNode != NULL) {
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    return preNode;
}