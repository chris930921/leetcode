char fizzText[] = "Fizz";
char buzzText[] = "Buzz";
char allText[] = "FizzBuzz";
 
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** result = (char**)malloc(sizeof(char*) * n);
    
    for(int i = 0; i < n; i++){
        // 2^32 = 4294967296, 10 digits + Null-terminated string = 11 chars;
        char* number = (char*)malloc(sizeof(char)* 11);
        sprintf(number, "%u", i + 1);
        result[i] = number;
    }
    
    for(int i = 3; i <= n; i += 3){
        result[i - 1] = fizzText;
    }
    
    for(int i = 5; i <= n; i += 5){
        result[i - 1] = buzzText;
    }
    
    for(int i = 15; i <= n; i += 15){
        result[i - 1] = allText;
    }
    
    return result;
}