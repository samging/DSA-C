int strStr(char *haystack, char *needle) {
    if (needle[0] == '\0') {
        return 0;
    }
    
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (strncmp(&haystack[i], needle, needleLen) == 0) {
            return i;
        }
    }
    
    return -1;
}
