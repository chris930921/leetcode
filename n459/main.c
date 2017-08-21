// 459. Repeated Substring Pattern

bool repeatedSubstringPattern(char* s) {
    int size = 0;
    while(s[size] != 0){
        size++;
    }
    
    int i;
    int j;
    int index;
    for(i = 1; i < (size / 2) + 1; i++){
        if(size % i != 0){
            continue;
        }
        
        index = 0;
        for(j = 0; j < size; j++){
            if(s[j] != s[index]){
                break;
            }
            index++;
            if(index == i){
                index = 0;
            }
        }
        if(j == size && j % i == 0){
            return true;
        }
    }
    return false;
}