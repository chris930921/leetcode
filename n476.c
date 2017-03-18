int findComplement(int num) {
    int count = 0;
    int copy = num;
    for(;copy != 0; copy >>= 1) count++;
    copy = (2147483647) >> (31 - count);
    return num ^ copy;
}