// 121. Best Time to Buy and Sell Stock

int maxProfit(int* prices, int pricesSize) {
    unsigned int minStock = -1;
    unsigned int maxProfit = 0;
    
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < min){
            // 如果遇到最小的股票就記錄起來。
            min = prices[i];
        }else if((prices[i] - min) > max){
            // 將每個股票和最小的股票相減求利潤，如果比之前的大就記錄起來。
            max = prices[i] - min;
        }
    }
    
    return max;
}