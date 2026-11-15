int lengthOfLastWord(char* s) {

    int wordSize = 0;
    for(int i = strlen(s)-1; i >= 0; i--){
        if(s[i] == 32){
            if(wordSize != 0){return wordSize;}
        }else{
            wordSize++;
        }
    }

    return wordSize;
}
