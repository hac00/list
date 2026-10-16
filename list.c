#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

Node *insert_start(Node *head, int value){
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = head;
    
    if (new == NULL){
        printf("Unable to allocate memory!\n");
        return head;
    }
    
    if (head == NULL){
        new->next = NULL;
        return new;
    }
    
    return new;
}

Node *insert_end(Node *head, int value){
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    
    if (new == NULL){
        printf("Unable to allocate new memory!\n");
        return head;
    }
    
    if (head == NULL){
        return new;
    }
    
    Node *aux = head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = new;
    
    return head;
}

Node *remove_start(Node *head){
    Node *aux = head;
    if (head == NULL){
        printf("Nao foi possivel remover item\n");
        return NULL;
    }
    head = aux->next;
    free(aux);
    return head;
}
Node *remove_end(Node *head){
    Node *aux = head;
    if (head == NULL){
        printf("Nao foi possivel remover item\n");
        return NULL;
    }
    Node *prev;
    while (aux->next != NULL){
        prev = aux;
        aux = aux->next;
    }
    prev->next = NULL;
    free(aux);
    
    return head;
}
Node *remove_node(Node *head, int pos){
    Node *aux = head, *prev;
    int i = 1;
    if (head == NULL){
        printf("Nao foi possivel remover item\n");
        return NULL;
    }
    while (aux != NULL){
        if (i == pos){
            if (aux == head){
                head = aux->next;
                free(aux);
            } else if (aux->next == NULL){
                prev->next = NULL;
                free(aux);
            } else {
                prev->next = aux->next;
                free(aux);
            }
            break;
        }
        i++;
        prev = aux;
        aux = aux->next;
    }

    return head;
}

Node *remove_value(Node *head, int value){
    if (head == NULL){
        printf("Unable to delete\n");
        return NULL;
    }
    
    Node *aux = head;
    Node *prev = NULL;
        
    while(aux != NULL){
        if (aux->value == value){
            if (prev == NULL){
                head = aux->next;
            } else {
                prev->next = aux->next;
            }
            aux->next = NULL;
            free(aux);
            aux = NULL;
            return head;
        }
        prev = aux;
        aux = aux->next;
    }
    
    return head;
}

Node *update_value(Node *head, int value, int new_value){
    Node *aux = head;
    int i = 0;
    while (aux != NULL){
        if (aux->value == value){
            aux->value = new_value;
            i = 1;
            break;
        } else {
           i = 0;
        }
        aux = aux->next;
    }
    if (i == 0){
        printf("Value not found!\n");
    }

    return head;
}

int count_nodes(Node *head){
    int i = 0;
    Node *aux = head;
    while (aux != NULL){
        aux = aux->next;
        i++;
    }
    
    return i;
}

int sum_values(Node *head){
    Node *aux = head;
    int a = 0;
    while (aux != NULL){
        a += aux->value;
        aux = aux->next;
    }

    return a;
}

float avg_value(Node *head){
    Node *aux = head;
    int q = count_nodes(aux);
    if (q == 0) { return 0.0; }
    int a = sum_values(aux);
    float avg = (float)a/q;
    return avg;
}

int highest_value(Node *head){
    Node *aux = head;
    int highest = 0;
    while (aux != NULL){
        if (aux->value > highest){
            highest = aux->value;
        }
        aux = aux->next;
    }
    return highest;
}

int lowest_value(Node *head){
    if (head == NULL) return 0;
    int lowest = head->value;
    Node *aux = head->next;
    while (aux != NULL){
        if (aux->value < lowest) lowest = aux->value;
        aux = aux->next;
    }
    return lowest;
}

int find_node(Node *head, int value){
    Node *aux = head;
    int pos = 0, i = 1;
    while (aux != NULL){
        if (aux->value == value){
            pos = i;
        }
        aux = aux->next;
        i++;
    }
    if (pos == 0){
        printf("Uninitialized list or no value match\n");
    }
    return pos;
}

Node *list_to_array(Node *head){
    Node *aux = head;
    int n = count_nodes(aux);
    Node *array = malloc(sizeof(Node) * n);
    for (int i=0; i<n; i++){
        array[i].value = aux->value;
        array[i].next = NULL;
        aux = aux->next;
    }

    return array;
}

Node *copy_list(Node *head){
    Node *aux = head;
    Node *copy = NULL;
    while (aux != NULL){
        copy = insert_end(copy, aux->value);
        aux = aux->next;
    }
    
    return copy;
}

Node *random_allocation(Node *head){
    int total_nodes = (rand() % 1000) + 1;
    for (int i = 0; i < total_nodes; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            printf("Error allocating memory!\n");
            return head;
        }
        
        new_node->value = rand() % 1000;
        new_node->next = head;
        head = new_node;
    }

    return head;
}

Node *random_values(Node *head, int n){
    Node *current = head;
    int count = 0;

    while (current != NULL && count < n) {
        current->value = rand() % 1000;
        current = current->next;
        count++;
    }

    return head;
}

void print_list(Node *head){
    Node *aux = head;
    while(aux != NULL){
        printf("%d -> ", aux->value);
        aux = aux->next;
    }
    printf("NULL\n");
}

void print_array(Node *head){
    Node *aux = head;
    for(int i=0; i<count_nodes(head); i++){
        printf("%d -> ", aux[i].value);
    }
    printf("NULL\n");
}

void print_adress(Node *head, int type){
    Node *aux = head;
    if (type == 1){
        while (aux != NULL){
            printf("%p -> ", aux);
            aux = aux->next;
        }
        printf("NULL\n");
    }
    if (type == 2){
        for(int i=0; i<count_nodes(aux); i++){
            printf("%p -> ", &aux[i]);
        }
        printf("NULL\n");
    }
}