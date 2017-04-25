int addDigits(int num) {
    if((num / 10) == 0) return num;
    
    int total = 0;
    while(num != 0){
        total += num % 10;
        num /= 10;
    }
    
    return addDigits(total);
}