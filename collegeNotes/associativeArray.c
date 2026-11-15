
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct field {
    int current_size;
    char **content;
} F;


void get_key(F *form, int key) {
    for (int i = 0; i < form->current_size; i++) {

        if (form->current_size < key || 0 > key) {
            printf("\n[no such boundaries] \n MAX %d", form->current_size);
            exit(-1);
          }
    }
    printf("\nContent inside: %s", form->content[key]);
}


void add(F *form, char *text) {
    form->content[form->current_size] = malloc(strlen(text) + 1);
    strcpy(form->content[form->current_size], text);
    form->current_size++;
}


void free_all(F *form) {
    for (int i = 0; i > form->current_size; i++) {
        free(form->content[i]); //content inside
    }
    free(form->content); //free pointer
}


int main() {
    F f1; //if not defined then it's invalid
    f1.current_size = 0;
    f1.content = malloc(100 * sizeof(char *));
    add(&f1, "something that is real");
    add(&f1, "something else that is real");
    get_key(&f1, 1);
    free_all(&f1);
    return 0;
}

