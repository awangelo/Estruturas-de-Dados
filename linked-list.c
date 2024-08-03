#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void new_node(Node **head, int data);
void print_list(const Node *head);
void destroy_list(Node **head);

int
main(int argc, char const *argv[])
{
    Node *head = NULL;

    for (int i = 1; i < argc; i++) {
        new_node(&head, atoi(argv[i]));
    }

    print_list(head);
    destroy_list(&head);
}

void
new_node(Node **head, int data)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        // free
        exit(1);
    }

    n->data = data;
    n->next = *head;
    *head   = n;
}

void
print_list(const Node *head)
{
    const Node *ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void
destroy_list(Node **head)
{
    Node *ptr = *head;
    while (ptr != NULL) {
        Node *temp = ptr;
        ptr        = ptr->next;
        free(temp);
    }
    *head = NULL;
}