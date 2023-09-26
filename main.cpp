#include <iostream>

struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
};

void initalize_linked_list(struct LinkedList *list)
{
    list->head = NULL;
}

void insert_node(struct LinkedList *list, int value)
{
    struct Node *new_node = new Node;

    new_node->value = value;
    new_node->next = NULL;

    if(list->head == NULL){
        list->head = new_node;
        return;
    }

    struct Node *temp = list->head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
}

void insert_node_after_certain_value(struct LinkedList* list, int index_find, int value)
{
    struct Node *new_node = new Node;

    new_node->value = value;
    new_node->next = nullptr;

    if(list->head == NULL){
        list->head = new_node;
        return;
    }

    struct Node *temp = list->head;
    struct Node *next_node = temp->next;


    while(temp->value != index_find){
        if(temp->next == NULL){
            std::cout << "Value not found in linked list" << std::endl;
            return;
        }
        else{
            next_node = temp;
        }
        temp = temp->next;

    }

    // The issue is that the last node in the list in the first iteration has its node pointer properly linked to null 
    // but all iterations after that will result in infinite loop
    temp->next = new_node;
    new_node->next = next_node;


    // SEG FAULT
    next_node->next = NULL;


}

void print_list(struct LinkedList *list)
{
    struct Node *temp = list->head;

    if(temp == NULL){
        std::cout << "NULL" << std::endl;
        return;
    }

    while(temp != NULL){
        std::cout << temp->value << " -> ";
        temp = temp->next;
        if (temp == NULL){
            std::cout << "NULL" << std::endl;
        }
    }
}

void remove_node(struct LinkedList *list, int value)
{
    struct Node *temp = list->head;
    struct Node *prev = NULL;

    if(temp->value == value){
        list->head = temp->next;
        delete(temp);
        return;
    }

    while(temp->value != value){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            std::cout << "Value not found" << std::endl;
            return;
        }
    }

    prev->next = temp->next;

    delete(temp);
}

void destroy_list(struct LinkedList *list)
{
    struct Node *temp = list->head;
    struct Node *prev = NULL;

    if(temp == NULL){
        std::cout << "List is already destroyed" << std::endl;
        delete(temp);
        return;
    }

    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete(prev);
    }

    list->head = NULL;
}

int main()
{
    struct LinkedList list;

    initalize_linked_list(&list);

    print_list(&list);

    insert_node(&list, 9);

    insert_node(&list, 10);

    insert_node(&list, 20);

    insert_node(&list, 23);

    print_list(&list);

    remove_node(&list, 20);

    print_list(&list);

    destroy_list(&list);

    print_list(&list);

    insert_node(&list, 8);

    print_list(&list);
    
    insert_node_after_certain_value(&list, 8, 9);

    print_list(&list);

    insert_node_after_certain_value(&list, 9, 12);

    print_list(&list);

    /*

    insert_node_after_certain_value(&list, 8, 10);

    print_list(&list);

    insert_node_after_certain_value(&list, 10, 12);

    print_list(&list);
    */


    return 0;
}