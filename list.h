#ifndef LIST_H
#define LIST_H

typedef struct node{
    int value;
    struct node *next;
} Node;

Node *insert_start(Node *head, int value);
Node *insert_end(Node *head, int value);
Node *remove_start(Node *head);
Node *remove_end(Node *head);
Node *remove_node(Node *head, int pos);
Node *remove_value(Node *head, int value);
Node *update_value(Node *head, int value, int new_value);
int count_nodes(Node *head);
int sum_values(Node *head);
float avg_value(Node *head);
int highest_value(Node *head);
int lowest_value(Node *head);
int find_node(Node *head, int value);
Node *list_to_array(Node *head);
Node *copy_list(Node *head);
Node *random_allocation(Node *head);
Node *random_values(Node *head, int n);
void print_list(Node *head);
void print_array(Node *head);
void print_adress(Node *head, int type);

#endif