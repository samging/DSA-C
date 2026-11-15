int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char* longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    qsort(strs, strsSize, sizeof(char *), compareStrings);

    char *first = strs[0];
    char *last = strs[strsSize - 1];

    int i = 0;
    while (first[i] && last[i] && first[i] == last[i]) {
        i++;
    }

    char *prefix = (char *)malloc(i + 1);  
    if (prefix) {
        strncpy(prefix, first, i);
        prefix[i] = '\0'; 
    }

    return prefix;
}
