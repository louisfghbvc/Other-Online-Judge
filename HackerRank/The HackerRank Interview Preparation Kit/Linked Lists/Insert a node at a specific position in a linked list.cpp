// Just maintain 2 node.
// O(N).

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    typedef SinglyLinkedListNode List;
    int cnt = 0;
    List* prev = NULL;
    List* cur = head;
    while(cnt < position){
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    prev->next = new List(data);
    prev->next->next = cur;
    return head;
}
