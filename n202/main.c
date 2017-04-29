// 因為檢查是否重複出現過，一定要保留計算過的數值。
// 所以需要 List 儲存。
typedef struct Node{
    int value;
    struct Node* next;
} Node;

// 將 value 加入到 List 的尾端。
// 例如 List 是 [0, 1, 2, 3]，輸入 4 後 List 為 [0, 1, 2, 3, 4]。
// 例如 List 是 NULL，輸入 0 後 List 為 [0]。
void addListNode(Node** nodeSlot, int value){
    while(*nodeSlot){
        nodeSlot = &((*nodeSlot)->next);
    }
    
    (*nodeSlot) = (Node*)calloc(1, sizeof(Node));
    (*nodeSlot)->value = value;
}

// 檢查 List 中是否出現過相同的 value。
// 例如 List 是 [0, 1, 2, 3]，輸入 0 發現已經重複出現，回傳 true。
// 例如 List 是 [0, 1, 2, 3]，輸入 4 發現沒有重複出現，回傳 false。
// 例如 List 是 NULL，輸入 1 發現沒有重複出現，回傳 flase。
int containsListNode(Node* node, int value){
   int isContains = 0; 
    
    while(node){
        if(node->value == value){
            isContains = 1;
            break;
        }
        node = node->next;
    }
    
    return isContains;
}

// 將每個位數平方後加總。
// 例如輸入 19，將 (1^2) + (9^2) 後等於 1 + 81 = 82。
int sumOfSquare(int value){
    int sum = 0;
    while(value){
        int num = value % 10;
        sum += num * num;
        value = value / 10;
    }
    return sum;
}

bool isHappy(int n) {
    // 如果 n 可以成功算出 1，這個 boolean 會保持 true 直到被輸出。
    int isHappyNumber = 1;
    // 初始化是必要的，沒賦值不一定就是 NULL。
    Node* list = NULL;
    
    while(n != 1){
        // 如果數值重複過，設定為 false 後 break。
        if(containsListNode(list, n)){
            isHappyNumber = 0;
            break;
        // 如果數值沒有重複過，放入 List 然後計算下一次的數值。
        }else{
            addListNode(&list, n);
            n = sumOfSquare(n);
        }
    }
    
    return isHappyNumber;
}