char* convertToBase7(int num) {
    int signedFlag = 0;
    
    if(num < 0){
        signedFlag = 1;
        num = -num;
    }
    
    int remainder = num;
    int digital = 1;
    
    long valueBase7 = num % 7;
    while(num >= 7){
        num /= 7;
        valueBase7 += (num % 7) * pow(10, digital);
        digital++;
    }
    
    if(signedFlag){
        valueBase7 = -valueBase7;
    }
    
    char* result = (char*)calloc(50, sizeof(char));
    sprintf(result, "%d", valueBase7);
    
    return result;
}