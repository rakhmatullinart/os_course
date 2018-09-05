//
//  main.c
//  ex3
//
//  Created by admin on 05/09/2018.
//  Copyright © 2018 admin. All rights reserved.
//

#include <stdio.h>
#define a_size(a) (sizeof(a) / sizeof(*a))

struct node{
    int value;
    struct node* next;
};

struct node* create(int data, struct node* next){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = data;
    newNode->next = next;
    return newNode;
}

void insert(struct node* head, int val){
    if (head == NULL)
        return;
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct node* newNode = create(val, NULL);
    current->next = newNode;
}

void printList(struct node* head){
    struct node *current = head;
    while (current->next != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("%d ", current->value);
}



int main(int argc, const char * argv[]) {
    
    struct node* head = create(5, NULL);
    
    
    insert(head, 8);
    
    printList(head);
    
    
    
    return 0;
}
