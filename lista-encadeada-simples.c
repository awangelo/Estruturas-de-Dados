#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no *next;
} no;

no *novo_no(no *l, int valor);
void print_lista(no *head);
no *destroy_lista(no *head, int valor);

int
main()
{
    no *head = NULL;
    for (int i = 0; i < 10; i++) {
        head = novo_no(head, i);
    }

    for (int i = 0; i < 10; i += 2) {
        head = destroy_lista(head, i);
    }

    print_lista(head);
    // Leak porque ainda falta dar free no restante
    puts("");
}

no *
novo_no(no *h, int valor)
{
    if (h == NULL) {
        h        = malloc(sizeof(no));
        h->value = valor;
        h->next  = NULL;

        return h;
    }

    no *nova    = malloc(sizeof(no));
    nova->value = valor;
    nova->next  = h;

    h = nova;

    return h;
}

no *
destroy_lista(no *head, int target)
{
    // Lista vazia
    if (head == NULL) {
        return NULL;
    }

    // Primeiro valor
    if (head->value == target) {
        no *temp = head;
        head     = head->next;
        free(temp);

        return head;
    }

    //
    no *temp = head;
    while (temp->next != NULL && temp->next->value != target) {
        temp = temp->next;
    }
    if (temp->next->value == target) {
        no *del    = temp->next;
        temp->next = temp->next->next;
        free(del);
    }

    return head;
}

void
print_lista(no *head)
{
    no *ptr = head;

    while (ptr != NULL) {
        printf("%d <- ", ptr->value);
        ptr = ptr->next;
    }
    printf("inicio\n");
}