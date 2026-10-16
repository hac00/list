#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"

int main(){
    srand(time(NULL));
    Node *list1 = NULL;
    Node *list2 = NULL;
    Node *list3 = NULL;
    Node *list4 = NULL;
    Node *list5 = NULL;
    Node *list6 = NULL;
    list1 = insert_end(list1, 1);
    list1 = insert_end(list1, 2);
    list1 = insert_end(list1, 3);
    list1 = insert_end(list1, 4);
    list1 = insert_end(list1, 5);
    list2 = insert_start(list2, 3);
    list2 = insert_start(list2, 2);
    list2 = insert_start(list2, 1);
    list4 = copy_list(list1);
    printf("lista1: ");
    print_list(list1);
    printf("lista2: ");
    print_list(list2);
    list1 = remove_value(list1, 2);
    //list1 = delete(list1, 2);
    //list1 = delete(list1, 3);
    printf("lista1: ");
    print_list(list1);
    list1 = remove_start(list1);
    print_list(list1);
    list1 = remove_end(list1);
    print_list(list1);
    list2 = remove_node(list2, 3);
    print_list(list2);
    //printf("teste");
    list2 = update_value(list2, 2, 3);
    print_list(list2);
    printf("Qtd of Nodes: %d\n", count_nodes(list2));
    printf("Sum of Values: %d\n", sum_values(list2));
    printf("Average Value: %.2f\n", avg_value(list1));
    printf("Highest Value: %d\n", highest_value(list1));
    printf("Lowest Value: %d\n", lowest_value(list1));
    printf("Value %d is the %d element in the list\n", 3, find_node(list2, 3));
    printf("lista4: ");
    print_list(list4);
    list5 = list_to_array(list4);
    printf("lista5: ");
    print_array(list5);
    printf("End l4: ");
    print_adress(list4, 1);
    printf("End l5: ");
    print_adress(list5, 2);
    list6 = random_allocation(list6);
    list6 = random_values(list6, count_nodes(list6));
    printf("list6 (%d): ", count_nodes(list6));
    print_list(list6);
}