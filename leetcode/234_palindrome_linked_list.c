// 后半部分链表反转，O(1)
bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *pre = NULL;
    while (fast != NULL && fast->next != NULL) { // find mid node by slow ptr
        slow = slow->next;
        fast = fast->next->next;
    }

    while (slow != NULL) { // reverse second half list
        struct ListNode *tmp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = tmp;
    }

    while (pre != NULL && head != NULL) {
        if (pre->val != head->val) return false;
        pre = pre->next;
        head = head->next;
    }
    return true;
}