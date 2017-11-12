// 38. Count and Say

char* countAndSay(int n) {
    n -= 1;
    
    if(n == 0){
        return "1";
    }
    
    // 每次讀取的字串。
    char* result = (char*)calloc(5000, sizeof(char));
    result[0] = '1';
    result[1] = 0;
    
    // 每次建立的字串。
    char* tmpResult = (char*)calloc(5000, sizeof(char));
    
    // 從第一層開始。
    for(int i = 0; i < n; i++){
        char* current = result;
        char* currentTmp = tmpResult;
        
        // 計算重複幾次。
        while(current[0]){
            char number = current[0];
            int count = 0;
            
            while(current[0] == number){
                current++;
                count++;
            }
            
            currentTmp[0] = '0' + count;
            currentTmp[1] = number;
            currentTmp += 2;
        }
        
        currentTmp = 0;
        
        // 將建立好的字串放到讀取，給下一層使用。
        char* tmp = tmpResult;
        tmpResult = result;
        result = tmp;
    }
    
    return result;
}