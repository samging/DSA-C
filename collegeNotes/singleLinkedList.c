#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int *ptr;
    struct node *next;
}
Node; //typedef is a defined datatype now...

//how do we traverse for a value right?

int find_by_value(Node *start, int tofind) {
    int i = 0;
    Node *current = start;
    while (current != NULL) {
        printf("\n Node %d: %d", i, current->data);
        if (current->data == tofind) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1; // not found
}

void read_data(Node *node)
{
    printf("\n data-read: %d\n", node->data);

    if (node->next != NULL) {
        printf("%d\n", node->next->data);
    }
}

Node* add_node(Node *node, int value) {
    Node *new_node = malloc(sizeof(Node));

    new_node->data = value;
    new_node->ptr = &new_node->data;
    new_node->next = node;

    return new_node;
}
int main()
{
    Node n;
    n.data = 10;
    n.ptr = &n.data;
    n.next = NULL;

    Node *nodec = &n;
    nodec = add_node(nodec, 230);
    nodec = add_node(nodec, 234);
    nodec = add_node(nodec, 233);
    nodec = add_node(nodec, 232);

    int index = find_by_value(nodec, 234);
    printf("\nFound at index: %d\n", index);
    read_data(nodec);

    return 0;
}
