int longestPalindrome(char* s) {
    int* upperLetterSet = (int*)calloc(26, sizeof(int));
    int* lowerLetterSet = (int*)calloc(26, sizeof(int));
    
    for(int i = 0; s[i] != 0; i++){
        if(s[i] < 97){
            upperLetterSet[s[i] - 65]++;
        }else{
            lowerLetterSet[s[i] - 97]++;
        }
    }
    
    int length = 0;
    for(int i = 0; i < 26; i++){
        length += upperLetterSet[i] / 2;
        length += lowerLetterSet[i] / 2;
    }
    length *= 2;
    
    for(int i = 0; i < 26; i++){
        if(upperLetterSet[i] % 2 == 1){
            length += 1;
            break;
        }
        if(lowerLetterSet[i] % 2 == 1){
            length += 1;
            break;
        }
    }
    
    return length;
}