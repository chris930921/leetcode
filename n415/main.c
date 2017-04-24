// 415. Add Strings

char* addStrings(char* num1, char* num2) {
    // 找出 num1 字串的長度。
    int num1Size = 0;
    for(; num1[num1Size] != 0; num1Size++);
    
    // 找出 num2 字串的長度。
    int num2Size = 0;
    for(; num2[num2Size] != 0; num2Size++);
    
    char* tmpNum;
    int tmpSize;
    // 如果 num2 的長度比 num1 長，將兩者交換，使 num1 長度總是 > num2。
    // 可使後面的程式不必判斷誰比較長而增加 if 判斷，也減少了縮排。
    if(num1Size < num2Size){
        tmpNum = num1;
        num1 = num2;
        num2 = tmpNum;
        
        tmpSize = num1Size;
        num1Size = num2Size;
        num2Size = tmpSize;
    }
    
    // 字串的長度，並考慮總和後的溢位，所以長度 +1。
    int sumSize = num1Size + 1;
    
    // 計算 num1 和 num2 的長度和 sum 的長度差多少。
    // 如果 num1 和 num2 的長度不一樣，相同位數會有不同 index。
    // 利用這兩個 delta 來做位置修正。
    int num1Delta = sumSize - num1Size;
    int num2Delta = sumSize - num2Size;
    
    // 建立總和的字串。
    char* sum = (char*)calloc(sumSize + 1, sizeof(char));
    
    // "0" 字元的 ascii 碼。
    int zeroAscii = 48;
    // 每個位數加總後是否溢位。
    int overflow = 0;
    for(int i = 0; i < sumSize; i++){
        int sumIndex = sumSize - i - 1;
        
        // 從個位數開始找起，利用 delta 修正相同位數的不同位置。
        int num1Index = sumIndex - num1Delta;
        int num2Index = sumIndex - num2Delta;
        
        // 找出同位數的字元，並轉換成數字。
        int value1 = (num1Index >= 0) ? num1[num1Index] - zeroAscii : 0;
        int value2 = (num2Index >= 0) ? num2[num2Index] - zeroAscii : 0;
        
        // 兩個數字相加，並考慮前一次的進位。
        int count = value1 + value2 + overflow;
        
        // 最後取出個位數，並判斷是否進位。
        int result =  (count % 10);
        overflow = (count >= 10);
        
        // 轉回字串。
        sum[sumIndex] = result + zeroAscii;
    }
    
    // 將 pointer 移動到開頭不為 0 的部分 (sum[0] == zeroAscii)。
    // 如果只有一位數就不移動 (sum[1] != 0)。
    for(; sum[0] == zeroAscii && sum[1] != 0; sum++);
    
    return sum;
}