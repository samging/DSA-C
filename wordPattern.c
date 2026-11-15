bool is_wordPattern(char *t, char *s);
bool wordPattern(char *pattern, char *s);
int count_words(const char *str);

bool wordPattern(char *pattern, char *s) {
    return is_wordPattern(pattern, s);
}

int count_words(const char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (isspace(*str)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
        str++;
    }
    return count;
}

bool is_wordPattern(char *t, char *s) {
    size_t size = strlen(t);
    int wordCount = count_words(s);

    int *list = calloc(size, sizeof(int));
    int k = 0, count = 0, pattern = 1;
    size_t sizeS = strlen(s), pattern_size = strlen(t);
    int *listS = calloc(wordCount, sizeof(int));
    int *resultsS = calloc(wordCount, sizeof(int));
    int countS = 0;
    int pos = 0;
    int kS = 0, countPattern = 0, phrasePattern = 1;    

    if (t == NULL || s == NULL) {
        printf("false\n");
        return false;
    }

    if (wordCount != pattern_size) {
        return false;
    }

    while (count != size) {
        for (int i = 0; i < size; i++) {
            if (t[i] == t[k] && list[i] == 0) {
                list[i] += pattern;
            }
        }
        k++;
        pattern++;
        count++;
    }

    for (int i = 0; i < sizeS; i++) {
        if (s[i] != ' ') {
            countS += s[i];
        }
        if (s[i] == ' ' && countS != 0) {
            resultsS[pos++] = countS;
            countS = 0;
        }
        if (s[i] == ' ' && countS == 0) {
        }
        if (i + 1 == sizeS) {
            if (pos < pattern_size) {
                resultsS[pos++] = countS;
            }
            if (pos != pattern_size) {
                return false;
            }
            countS = 0;
        }
    }

    for (int i = 0; i < pattern_size; i++) {
        printf("\nresult: %d | list: %d", resultsS[i], list[i]);
    }

    while (countPattern != pattern_size) {
        for (int i = 0; i < pattern_size; i++) {
            if (resultsS[i] == resultsS[kS] && listS[i] == 0) {
                listS[i] += phrasePattern;
            }
        }
        
        kS++;
        phrasePattern++;
        countPattern++;
    }
    
    int validity = 0;
    for (int i = 0; i < pattern_size; i++) {
        if (list[i] == listS[i]) {
            validity++;
        } else {
            printf("\nvalidity check: Res: %d =? Match: %d", listS[i], list[i]);
        }
    }

    if (validity == pattern_size) {
        printf("true\n");
        free(resultsS);
        free(listS);
        free(list);
        return true;
    } else {
        free(resultsS);
        free(listS);
        free(list);
        return false;
    }
}
