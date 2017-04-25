int getSum(int a, int b) {
    int result = a ^ b;
    int carry = a & b;
    int nextResult = 0;
    while(carry){
        nextResult = result ^ (carry << 1);
        carry = result & (carry << 1);
        result = nextResult;
    }
    return result;
}