// Same as single. just check if prev null

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    typedef DoublyLinkedListNode List;
    List* prev = NULL;
    List* cur = head;
    while(cur && data > cur->data){
        prev = cur;
        cur = cur->next;
    }
    if(prev){
        prev->next = new List(data);
        prev->next->prev = prev;
        prev->next->next = cur;
    }
    else{
        prev = new List(data);
        prev->next = cur;
        cur->prev = prev;
        head = prev;
    }
    return head;
}
