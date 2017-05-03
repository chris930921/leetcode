// 83. Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
void delete(struct ListNode* head){
    if(head == NULL){
        return;
    }
    
    if(head->next == NULL){
        return;
    }
    
    if(head->val == head->next->val){
        head->next = head->next->next;
        delete(head);
    }else{
        delete(head->next);
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    delete(head);
    
    return head;
}