#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} node_t;

void print_list(node_t *node) {
    node_t *temp = node;
    while (temp != NULL) {
        printf(" %d <--> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void print_node_from_tail(node_t *tail_node, int position) {
    node_t *temp = tail_node;
    if (position == 1) {
        printf("value from tail at position %d is %d\n", position, temp->data);
        return;
    } else {
        for(int i = 1; i < position; i++) {
            temp = temp->prev;
        }
        printf("value from tail at position %d is %d\n", position, temp->data);
    }
}

int main() {
    node_t * head = NULL;
    node_t * tail = NULL;
    node_t * temp = NULL;

    for (int i = 9; i != 0; i--) {
        temp = (node_t *)malloc(sizeof(node_t));
        
        if (tail == NULL) {
            tail = temp;
        }
        temp->data = i;
        temp->next = head;
        temp->prev = NULL;
        
        if(head != NULL) {
            head->prev = temp;
        }
        head = temp;
    }

    print_list(head);

    printf("tail data is %d\n", tail->data);
    printf("head data is %d\n", head->data);

    print_node_from_tail(tail, 3);
    
    return 0;
}