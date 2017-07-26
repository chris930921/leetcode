// 521. Longest Uncommon Subsequence I

int findLUSlength(char* a, char* b) {
    int firstStringLength = 0;
    int isSame = 1;
    for(int i = 0; a[i] != 0; i++){
        firstStringLength++;
        isSame &= (a[i] == b[i]); 
    }
    
    int secondStringLength = 0;
    for(int i = 0; b[i] !=0; i++){
        secondStringLength++;
    }
    
    if(firstStringLength == secondStringLength && isSame){
        return -1;
    }
    
    if(firstStringLength > secondStringLength){
        return firstStringLength;
    }else{
        return secondStringLength;
    }
}