// Tricky. O(N) super short.
// Cuz head1 -> tail -> head2 -> counter point 
// same as head2 -> tail -> head1 -> counter point

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    typedef SinglyLinkedListNode ListNode;
    ListNode *cur1 = head1, *cur2 = head2;
    while(cur1 != cur2){
        if(cur1->next) cur1 = cur1->next;
        else cur1 = head2;

        if(cur2->next) cur2 = cur2->next;
        else cur2 = head1;
    }
    return cur1->data;
}
