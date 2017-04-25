// 541. Reverse String II

char* reverseStr(char* s, int k) {
    // 找出字串長度
    int size = 0;
    for(size = 0; s[size] != 0; size++);
    
    // 例如 123456789012，k = 5，字串長度為 12。
    // 第一次 head = 0、foot = 4、interva; = 5，反轉 s[0:4] 部分後得到 543216789012。
    // 第二次 head = 10、foot = 14、interva; = 5，foot 已經超過字串的長度，所以修改邊界如下
    //        head = 10、foot = 11、interva; = 1，反轉 s[10:11] 部分後得到 543216789021。
    for(int i = 0; i < size; i += 2*k){
        int head = i;
        int foot = i + k - 1;
        int interval = k;
        
        // 超過字串的長度，所以修改邊界。
        if(foot >= size){
            foot = size - 1;
            interval = foot - head;
        }
        
        // 假設要反轉的字串為 [char, char, char, char]。
        // 指標一開始為 [*head, char, char, *foot]，head 和 foot 會進行交換。
        // 接著指標向內移動 [char, *head, *foot, char]。head 和 foot 會進行交換。
        // 指標繼續向內移動 [char, *foot, *head, char]。head > foot 所以停止交換。
        
        // 假設要反轉的字串為 [char, char, char]。
        // 指標一開始為 [*head, char, *foot]，head 和 foot 會進行交換。
        // 接著指標向內移動 [*char, (*head|*foot), char]，head == foot 所以停止交換。
        for(int j = 0; head + j <= foot - j; j++){
            char tmp = s[head + j];
            s[head + j] = s[foot - j];
            s[foot - j] = tmp;
        }
    }
    
    return s;
}