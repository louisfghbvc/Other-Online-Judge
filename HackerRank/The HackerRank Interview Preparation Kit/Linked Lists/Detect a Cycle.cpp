// Just floyd cycle. O(N)

bool has_cycle(Node* head) {
    if(!head) return false;
    Node* slow = head;
    Node* fast = head;
    do{
        if(slow->next) slow = slow->next;
        else return false;
        if(fast->next && fast->next->next) fast = fast->next->next;
        else return false;
    }while(slow != fast);
    return true;
}
