// 206. Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // Link List 為空，不必反轉。
    if(head == NULL){
        return head;
    }
    
    // 假設 LinkList 是 [10, 20, 30, 40]。
    // 使 origin 永遠指向一開始的 head node，也就是 [10]。
    struct ListNode* origin = head;
    
    // 從 origin 取出 [20] 並將前後連接成為 [10, 30, 40]。
    // 將 [20] 和 [10, 30, 40] 連接，成為 [20, 10, 30, 40]。
    // 更新 head node 從 [10] 為 [20]。
    
    // 從 origin 取出 [30] 並將前後連接成為 [20, 10, 40]。
    // 將 [30] 和 [20, 10, 40] 連接，成為 [30, 20, 10, 40]。
    // 更新 head node 從 [20] 為 [30]。
    
    // 從 origin 取出 [40] 並將前後連接成為 [30, 20, 10]。
    // 將 [40] 和 [30, 20, 10] 連接，成為 [40, 30, 20, 10]。
    // 更新 head node 從 [30] 為 [40]。
    
    // [40, 30, 20, 10] 反轉完畢。
    struct ListNode* tmp = NULL;
    while(origin->next != NULL){
        tmp = origin->next;
        origin->next = tmp->next;
        tmp->next = head;
        head = tmp;
    }
    
    return head;
}