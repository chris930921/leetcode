// 557. Reverse Words in a String III

// 用來反轉字串，須提供反轉的起點(start)和結束點(end)。
void reverse(char* s, int start, int end){
    while(start < end){
        int tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int start = 0;
    int end = 0;
    
    // 紀錄子字串的起點和結束點，遇到空格或是 \0 時將子字串反轉。
    for(int i = 0; s[i] != 0; i++){
        if(s[i] == ' '){
            reverse(s, start, end);
            start = i+1;
        }else{
            end = i;
            if(s[i+1] == 0){
                reverse(s, start, end);
            }
        }
    }
    
    return s;
}