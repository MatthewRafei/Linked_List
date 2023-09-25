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

    remove_node(&list, 8);

    return 0;
}