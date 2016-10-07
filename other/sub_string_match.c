bool canConstruct(char* ransomNote, char* magazine) {
    int i;
    
    for(i = 0; ransomNote[i] != 0; i++);
    int noteLength = i;
    
    for(i = 0; magazine[i] != 0; i++);
    int magazineLength = i;
    
    if(noteLength == 0 && magazineLength == 0){
        return true;
    }
    
    for(i = 0; i < magazineLength - noteLength; i++){
        int j;
        for(j = 0; j < noteLength; j++){
            if(magazine[i + j] != ransomNote[j]){
                break;
            }
        }
        if(j == noteLength){
            return true;
        }
    }
    return false;
}