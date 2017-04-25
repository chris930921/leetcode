int titleToNumber(char* s) {
    int length = 0;
    for(;s[length] != 0; length++);
    
    int result = 0;
    for(int i = 0; i < length; i++){
        int digit = length - 1 - i;
        result += (s[i] - 64) * power(26, digit);
    }
    return result;
}

int power(int value, int num){
    if(num == 0){
        return 1;
    }
    return value * power(value, num - 1);
}