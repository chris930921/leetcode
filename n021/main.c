// 21. Merge Two Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL){
        return l2;
    }
    
    if(l2 == NULL){
        return l1;
    }
    
    struct ListNode newListHead;
    struct ListNode* cursor = &newListHead;
    
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            cursor->next = l1;
            cursor = cursor->next;
            l1 = l1->next;
        }else{
            cursor->next = l2;
            cursor = cursor->next;
            l2 = l2->next;
        }
    }
    
    if(l1 == NULL){
        cursor->next = l2;
    }else if(l2 == NULL){
        cursor->next = l1;
    }
    
    return newListHead.next;
}