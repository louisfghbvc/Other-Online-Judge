// Remember to connect prev.

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    typedef DoublyLinkedListNode ListNode;
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next = prev;
        if(prev) prev->prev = cur;
        prev = cur;
        cur = tmp;
    }
    return prev;
}
