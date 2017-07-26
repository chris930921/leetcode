// 191. Number of 1 Bits

int hammingWeight(uint32_t n) {
    int bitsNumber = 0;
    // 將 n 一個一個位移，並且和 0b1 做 AND 判斷是否為 1。
    // 是 1 的話總值增加 1。
    for(int i = 0; i < 32; i++){
        bitsNumber += (0b1 & (n >> i)); 
    }
    return bitsNumber;
}