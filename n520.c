bool detectCapitalUse(char* word) {
    int headFlag = 0;
    
    // 97 -> a
    if(*word < 97){
        headFlag = 1;
    }
    
    int totalCount = 0;
    int capitalCount = 0;
    while(*word){
        // 97 -> a
        if(*word < 97){
            capitalCount++;
        }
        totalCount++;
        word++;
    }
    
    if(headFlag == 1 && capitalCount == 1){ // example "Abc"
        return 1;
    }else if(totalCount == capitalCount){ // example "ABC"
        return 1;
    }else if(capitalCount == 0){ // example "abc"
        return 1;
    }else{ // example "aBc"
        return 0;
    }
}