// 70. Climbing Stairs

int climb(int n, int* dynamicTable){
    // 如果剩下 2 階，一次走 2 階剩下 0，代表這種組合可以接受，走法數量 + 1。
    // 如果剩下 1 階，一次走 1 階剩下 0，代表這種組合可以接受，走法數量 + 1。
    if(n == 0){
        return 1;
    // 如果剩下 1 階，一次走 2 階剩下 -1，代表這種組合不可接受，走法數量 + 0。
    // 如果剩下 0 階，一次走 1 階剩下 -1，代表這種組合不可接受，走法數量 + 0。
    }else if(n < 0){
        return 0;
    }
    
    int resultOfTwoStep = 0;
    int resultOfOneStep = 0;
    int resultStep = 0;
    
    // 如果表裡第 n 階已經有計算好的數值 x ，直接取出後回傳，走法數量 + x。
    if(dynamicTable[n] != 0){
        resultStep = dynamicTable[n];
    // 如果表裡第 n 階還沒有結果，使用 n - 2 和 n - 1 的遞迴進行計算。
    }else{
        resultOfTwoStep = climb(n - 2, dynamicTable);
        resultOfOneStep = climb(n - 1, dynamicTable);
        resultStep = resultOfTwoStep + resultOfOneStep;
        // 算出來以後要儲存到表裡，可以提供下次使用。
        dynamicTable[n] = resultStep;
    }
    
    return resultStep;
}

int climbStairs(int n) {
    // 採用動態規劃，宣告階數 + 1 大小的陣列。
    // 每次計算出結果後就保存起來，遞迴遇到相同計算可以直接取結果。
    // 這樣做可以很大程度的節省時間。
    int* dynamicTable = (int*)calloc(n + 1, sizeof(int));
    return climb(n, dynamicTable);
}