
// 401. Binary Watch

char** readBinaryWatch(int num, int* returnSize) {
    // 小時最高到 11 小時 (01011)，最多有 3 個 LED 會亮，加上全不亮共 4 種情況。
    // 分鐘最高到 59 分鐘 (111011)，最多有 5 個 LED 會亮，加上全不亮共 6 種情況。
    
    // 建立陣列，儲存 0 個亮、 1 個亮、2 個亮、3 個亮，四種情況。
    int** hoursLed = (int**)calloc(4, sizeof(int*));
    for(int i = 0; i < 4; i++){
        // 預設每個分類最多用到 5 個空間。
        hoursLed[i] = (int*)calloc(5, sizeof(int));
    }
    
    // 分類所有小時的數字，分別有幾個 1 在裡面。
    // hour 0 個 1 : 0, 
    // hour 1 個 1 : 1, 2, 4, 8, 
    // hour 2 個 1 : 3, 5, 6, 9, 10, 
    // hour 3 個 1 : 7, 11, 
    int* hoursPushIndexes = (int*)calloc(4, sizeof(int));
    for(int i = 0; i < 12; i++){
        int value = i;
        int oneCounter = 0;
        
        // 找出某個數字有個 1。
        while(value != 0){
            oneCounter += value & 1;
            value >>= 1;
        }
        
        // 用 1 的個數當作分類，找出群組並放入時間。
        int index = hoursPushIndexes[oneCounter];
        hoursLed[oneCounter][index] = i;
        hoursPushIndexes[oneCounter]++;
    }
    
    // 建立陣列，儲存 0 個亮、 1 個亮、2 個亮、3 個亮、4 個亮、5 個亮，六種情況。
    int** minsLed = (int**)calloc(6, sizeof(int*));
    for(int i = 0; i < 6; i++){
         // 預設每個分類最多用到 20 個空間。
        minsLed[i] = (int*)calloc(20, sizeof(int));
    }
    
    // 分類所有分鐘的數字，分別有幾個 1 在裡面。
    // min 0 個 1 : 0, 
    // min 1 個 1 : 1, 2, 4, 8, 16, 32, 
    // min 2 個 1 : 3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48, 
    // min 3 個 1 : 7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56, 
    // min 4 個 1 : 15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58, 
    // min 5 個 1 : 31, 47, 55, 59, 
    int* minsPushIndexes = (int*)calloc(6, sizeof(int));
    for(int i = 0; i < 60; i++){
        int value = i;
        int oneCounter = 0;
        // 找出某個數字有個 1。
        while(value != 0){
            oneCounter += value & 1;
            value >>= 1;
        }
        
        // 用 1 的個數當作分類，找出群組並放入時間。
        int index = minsPushIndexes[oneCounter];
        minsLed[oneCounter][index] = i;
        minsPushIndexes[oneCounter]++;
    }
    
    // 如果有 3 個以上的燈亮了，設定 hour 的迴圈只跑到 3。
    // 如果只有 2 個燈亮了，設定 hour 的迴圈只跑到 2。
    int hoursLimit = 0;
    if(num > 3){
        hoursLimit = 4;
    }else{
        hoursLimit = num + 1;
    }
    
    // 如果 5 個燈以上亮了，代表 hour 不可能 0 個燈亮，從 num - 5 個燈亮開始找。
    // 假設 6 個燈亮了，分鐘部分最多只能亮 5 個燈，所以小時部分必亮 1 個燈。
    int hoursStart = 0;
    if(num > 5){
        hoursStart = num - 5;
    }
    
    // 計算要回傳多少個字串。
    *returnSize = 0;
    for(int hourLedNumber = hoursStart; hourLedNumber < hoursLimit; hourLedNumber++){
        // 減去小時部分亮的燈，算出分鐘部分亮多少燈。
        int minLedNumber = num - hourLedNumber;
        // 透過 push 時用的 index，相乘後加總算出有多少字串。
        int hoursSize = hoursPushIndexes[hourLedNumber];
        int minsSize = minsPushIndexes[minLedNumber];

        *returnSize += hoursSize * minsSize;
    }
    
    char** results = (char**)calloc(*returnSize, sizeof(char*));
    int pushTimeIndex = 0;
    // 假設有 3 個燈亮，這裡需找出小時部分 0 個燈亮到 3 個燈亮全部的情況。
    for(int hourLedNumber = hoursStart; hourLedNumber < hoursLimit; hourLedNumber++){
        // 找出分鐘部分亮幾個燈。
        int minLedNumber = num - hourLedNumber;
        int hoursSize = hoursPushIndexes[hourLedNumber];
        int minsSize = minsPushIndexes[minLedNumber];
        
        // 假設全部亮 3 個燈，目前小時部分亮 0 個燈，分鐘部分亮 3 個燈。
        // 找出小時 0 個燈的群組和分鐘 3 個燈的群組。
        int* hours = hoursLed[hourLedNumber];
        int* mins = minsLed[minLedNumber];
        for(int x = 0; x < hoursSize; x++){
            for(int y = 0; y < minsSize; y++){
                int hour = hours[x];
                int min = mins[y];
                
                // 兩個群組全部的值相互對應，產生結果。
                char* time = (char*)calloc(6, sizeof(char));
                sprintf(time, "%d:%02d", hour, min);
                results[pushTimeIndex] = time;
                pushTimeIndex++;
            }
        }
    }
    
    return results;
}