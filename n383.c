bool canConstruct(char* ransomNote, char* magazine) {
    int i;
    
    int* letterSet = (int*)calloc(26, sizeof(int));
    
    for(i = 0; magazine[i] != 0; i++){
        letterSet[magazine[i] - 97]++;
    }
    
    for(i = 0; i < 26; i++){
        printf("origin: %u\n", letterSet[i]);
    }
    
    for(i = 0; ransomNote[i] != 0; i++){
        letterSet[ransomNote[i] - 97]--;   
    }
    
    for(i = 0; i < 26; i++){
        printf("result: %u\n", letterSet[i]);
        if(letterSet[i] < 0){
            return false;
        }
    }
    
    return true;
}