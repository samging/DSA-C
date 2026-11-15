bool canConstruct(char* ransomNote, char* magazine) {
    int letterCount[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        letterCount[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = ransomNote[i] - 'a';
        if (letterCount[index] == 0) {
            return false; 
        }
        letterCount[index]--;
    }

    return true;
}
