int hammingDistance(int x, int y) {
    x ^= y;
    for(y = 0; x != 0; x >>= 1){
        y += (x & 1);
    }
    return y;
}