#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

void print_list(Node_t  *head) {
    Node_t *temp = head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node_t * reverse_list(Node_t *head){
    Node_t *current = head;
    Node_t *next = NULL;
    Node_t *prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node_t * remove_node(Node_t *head, int postion) {
    Node_t *temp = head;
    Node_t *prev = NULL;
    if (postion == 1) {
        head = temp->next;
        free(temp);
        return head;
    }
    else {
        int counter = 1;
        while (temp != NULL && counter != postion) {
            prev = temp;
            temp = temp->next;
            counter++;
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;
}
Node_t * add_node(Node_t *head, int postion, int data) {
    Node_t * temp = head;
    Node_t * prev = NULL;
    Node_t * new = NULL;
    if(postion == 1) {
        new = (Node_t *)malloc(sizeof(Node_t));
        new->next = head;
        new->data = data;
        head = new;
        return head;
    }
    else {
        int counter = 1;
        while (temp != NULL && counter != postion) {
            prev = temp;
            temp = temp->next;
            counter++;
        }
        new = (Node_t *)malloc(sizeof(Node_t));
        prev->next = new;
        new->next = temp;
        new->data = data;
    }
    return head;
}
int main()
{
    Node_t *head = NULL;
    Node_t *temp;
    
    for (int i = 8; i >= 0; i--) {
            temp = (Node_t *)malloc(sizeof(Node_t));
            temp->next = head;
            temp->data = i;
            head = temp;
    }
    
    print_list(head);

    head = add_node(head, 2, 12);
    print_list(head);
    head = add_node(head, 1, 10);
    print_list(head);

    head = remove_node(head, 1);

    print_list(head);
 
    head = reverse_list(head);
    print_list(head);

    return 0;
}