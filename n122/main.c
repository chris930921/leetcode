// 122. Best Time to Buy and Sell Stock II

int maxProfit(int* prices, int pricesSize) {
    // 找出第一個可以買進的價格，也就是準備要上升的時候。
    // 例如 [10, 20, 15, 30]，第一個可以買的價格就是 10。
    // 例如 [30, 20, 15, 40]，第一個可以買的價格就是 15。
    int current = -1;
    for(int i = 0; i < pricesSize - 1; i++){
        if(prices[i] < prices[i+1]){
            current = i;
            break;
        }
    }
    
    // 例如 [40, 30, 20, 10]，全是降序所以沒有可買的價格，current 保持 -1，直接回傳利潤為 0。
    if(current == -1){
        return 0;
    }
    
    int profitSum = 0;
    int j = 0;
    int x = 0;
    // 設定尋找利潤的結束條件。
    // 例如 [20, 30, 40, 10]，current 指向第 4 個價格 (current = j + 1)，已是最後一個價格，所以結束迴圈。
    // 例如 [30, 40, 10 ,20]，current 指向第 5 個價格 (current = j + 1)，已經超出陣列大小，所以結束迴圈。
    while(current < (pricesSize - 1)){
        // 找出價格下降的時間點，獲得最大利潤。
        // 例如 [30, 40, 10 ,20]，買進 30 後，在 40 的時間點賣出是最好的。
        // 例如 [30, 40, 10 ,20]，買進 10 後，在 20 的時間點賣出是最好的。
        for(j = current + 1; j < pricesSize - 1; j++){
            if(prices[j] > prices[j+1]){
                break;
            }
        }
        
        profitSum += prices[j] - prices[current];
        current = j + 1;
        
        // 從賣出的價格繼續尋找，找出下一個價格上升的情況。
        // 例如 [30, 40, 10 ,20]，買進 30 賣出 40 後，又找到 20 < 10 這個情況，設定 current 等於 10 這個價格。
        for(x = current; x < pricesSize - 1; x++){
            if(prices[x] < prices[x+1]){
                break;
            }
        }
        current = x;
    }
    
    // 心得，利用迴圈尋找特定情況時，迴圈內只對狀況做判斷並決定何時 break 迴圈，
    // 對特定情況的相關操作，最好放到迴圈之外進行。
    return profitSum;
}