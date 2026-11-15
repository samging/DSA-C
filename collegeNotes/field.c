#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getItem(const char **pole, int key) {

    printf("%s", (char*)pole[1]);
    //strncpy(buff, pole + shift_index, end - start);
    return "okay";
}

char **set(const char **pole, int *setnew, int index){
    char *buff = (char *)calloc(100, sizeof(char));
    strncpy(buff, pole[index], sizeof(pole[index]));
    printf("%s", buff);
    char x = (char**)'x';
    return x;
}
int main() {
    //[] -> returns pointer: if [[] []] -> returns pointer to pointers
    const char *pole[] = {"this is some", "this is some other"};
    char ton[] = "new string here";

    set(pole, ton, 0);

    getItem(pole, (int)1);
    return 0;
}
