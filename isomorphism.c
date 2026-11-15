bool isIsomorphic(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int mapST[256] = {0};
    int mapTS[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        char sc = s[i];
        char tc = t[i];

        if (mapST[sc] == 0 && mapTS[tc] == 0) {
            mapST[sc] = tc;
            mapTS[tc] = sc;
        } else if (mapST[sc] != tc || mapTS[tc] != sc) {
            return false;
        }
    }

    return true;
}
