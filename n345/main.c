// 345. Reverse Vowels of a String

char* reverseVowels(char* s) {
    int size = 0;
    for(int i = 0; s[i]; i++){
        size++;
    }
    
    int i = 0;
    int j = size - 1;
    char tmp;
    for(; i < j; i++){
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
          s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'){
            continue;
        }
        
        // printf("i:%c\n", s[i]);
        for(; i < j ; j--){
            if(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
                s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U'){
                continue;
            }
            
            // printf("j:%c\n", s[j]);
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            j--;
            break;
        }
    }
    
    return s;
}