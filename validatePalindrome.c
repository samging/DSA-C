bool has_palindrome(const char *write) {
    size_t len = strlen(write);
    
    for (size_t i = 0; i < len / 2; ++i) {
        if (write[i] != write[len - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(char *s) {
    size_t size_s = strlen(s);
    char *write = (char*)malloc(size_s + 1);
    
    if (!write) {
        return false; 
    }

    char *temp = write;
    while (*s) {
        if (isalnum((unsigned char)*s)) { 
            *temp = tolower((unsigned char)*s);
            temp++;
        }
        s++;
    }

    *temp = '\0';

    bool result = has_palindrome(write);
    
    free(write);
    return result;
}
