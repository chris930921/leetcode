// 405. Convert a Number to Hexadecimal

// 還有一種解法是將 int 全部硬轉 hex，在將前面為 0 的部分去除。
char* toHex(int num) {
    // 直接從二進位轉十六進制最方便，不必考慮負數等問題。
    // 例如輸入 26，二進制為 0001 1010，十六進制為 1a。
    
    if(num == 0){
        return "0";
    }
    
    // 須注意，有時會下意識寫出如下賦值方式，雖然 compiler 可以通過，但 run time 會發生錯誤。
    // char* hexTexts = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char hexTexts[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int size = 0;
    
    // 轉成 unsigned int，避免 num 為負數時右移會填入 1 的問題，導致無窮迴圈。
    unsigned int copyNum = num;
    
    // 找出有多少個十六進制字元。
    // 十六進制 1 位數同等於二進制 4 bits，所以一次位移 4 個 bit。
    while(copyNum != 0){
        copyNum >>= 4;
        size++;
    }
    
    // 建立字串陣列，考慮結束符號 \0 所以 +1。
    char* result = (char*)calloc(size + 1, sizeof(char));
    
    copyNum = num;
    for(int i = 0; i < size; i++){
        // 和 0xf 做 AND 可以取得最後四位數。
        int value = copyNum & 0xf;
        
        // 從陣列取出對應的字元。
        result[size - i - 1] = hexTexts[value];
        
        // 最後需要將 num 右移 4 bits，才能取得下 4 個 bits。
        copyNum >>= 4;
    }
    
    return result;
}