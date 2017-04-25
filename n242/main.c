// 242. Valid Anagram

bool isAnagram(char* s, char* t) {
    // 給 26 個字母建立一個陣列，當作 counter。
    int* letterList = (int*)calloc(26, sizeof(int));
    
    // 找出 s 中每個字母出現的次數，增加到 counter 中。
    for(int i = 0; s[i] != 0; i++){
        int index = s[i] - 97;
        letterList[index]++;
    }
    
    // 找出 t 中每個字母出現的次數，減少到 counter 中。
    for(int i = 0; t[i] != 0; i++){
        int index = t[i] - 97;
        letterList[index]--;
    }
    
    // 找出是否有不等 0 的字母，有則 Anagram 不同，回傳 flase。
    for(int i = 0; i < 26; i++){
        if(letterList[i] != 0){
            return false;
        }
    }
    
    // counter 全部為零，Anagram 相同回傳 true。 
    return true;
}