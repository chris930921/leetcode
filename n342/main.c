// 342. Power of Four

bool isPowerOfFour(int num) {
	int result = 0;

	// 負數一定不是 4 的次方。
	result &= (num > 0);
	// 判斷最後一個 bit 是不是 0。
	result &= ((num & (num - 1)) == 0);
	// 4 的次方 mod 3 會是 1。
	result &= (num % 3 == 0);
	
    return result
}