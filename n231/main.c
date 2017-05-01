// 231. Power of Two

bool isPowerOfTwo(int n) {
    if(n > 0){
        // 如果是二的次方，一定可以被更小的二的次方整除。
        return (2147483648 % n) == 0; 
    }else{
        // 負數和零都不是二的次方。
        return 0;
    }
}