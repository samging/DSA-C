bool isSubsequence(char* s, char* t) {
    int i = 0;
    int size_s = strlen(s);
    
    for (int j = 0; t[j] != '\0'; j++) {
        if (s[i] == t[j]) {
            i++;
        }
        
        if (i == size_s) {
            return true;
        }
    }
    if(strlen(s) == 0 && strlen(t) == 0){
        return true;
    }
    
    return false;
}
