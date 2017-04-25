int firstUniqChar(char* s) {
    int* letterLow = (int*)calloc(26, sizeof(int));
    int* position = (int*)calloc(26,sizeof(int));
    
    int counter = 0;
    while(*s != 0){
        letterLow[*s - 97]++;
        position[*s - 97] = counter; 
        s++;
        counter++;
    }
    
    unsigned int min = -1;
    for(int i = 0; i < 26; i++){
        if(letterLow[i] == 1){
            if(position[i] < min){
                min = position[i];
            }
        }
    }
    
    return min;
}