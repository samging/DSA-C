bool isAnagram(char* s, char* t) {
    int pole[26] = {0};

    for(int i = 0; s[i] != '\0' ; i++){
        pole[s[i]-97] = pole[s[i]-97]+1;
    }
    for(int i = 0; t[i] != '\0' ; i++){
        pole[t[i]-97] = pole[t[i]-97]-1;
    }
    for(int i = 0; i < 26; i++){
        if(pole[i] != 0){
            return false;
        }
    }
    return true;
}
