//
//  main.c
//  recursiveList
//
//  Created by Yan Bussieres on 2019-01-26.
//  Copyright © 2019 Yan Bussieres. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//void append(int x);
//void print(struct list_item *first);



struct list_item{
    int value;
    struct list_item * next;
} ;

void append(struct list_item *first, int x);
void print(struct list_item *first);
void prepend(struct list_item *first, int x);
int list_size = 0;


int main()
{

    struct list_item root;
    root.value = -1;
    root.next = NULL;
    printf("befrore %p\n", &root);
    append(&root, 2);
    printf("after APPEND %p\n", &root);
    append(&root, 4);
    prepend(&root, 0);
    printf("after prepend in MAIN %p\n", &root);
    print(&root);

    return 0;
};

void append(struct list_item *first, int x) //,
{
    struct list_item * current = first;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(struct list_item));
    current->next->value = x;
    current->next->next = NULL;
}



void print(struct list_item *first) {
    struct list_item * current = first->next;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next; // (*current).next
    }
}

void prepend(struct list_item *first, int x){
    printf("b4 prepend func %p\n", first);
    struct list_item * new_item;
    new_item = (struct list_item*)malloc(sizeof(struct list_item));

    new_item->value = x;
    new_item->next = first->next;
    first->next = new_item;
    first = new_item;

    printf("after prepend func %p\n", &first);
}
