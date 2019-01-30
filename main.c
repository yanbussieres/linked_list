//
//  main.c
//  recursiveList
//
//  Created by Yan Bussieres on 2019-01-26.
//  Copyright © 2019 Yan Bussieres. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct list_item{
    int value;
    struct list_item * next;
} ;

void append(struct list_item *first, int x);
void print(struct list_item *first);
void prepend(struct list_item *first, int x);
void input_sorted(struct list_item *first);
void swap(struct list_item *a, struct list_item *b);  // Function used too swap 2 nodes. Used in the input_sorted function.
void clear_list(struct list_item *first);

int list_size = 0;


int main()
{
    struct list_item * root;
    root = (struct list_item*)malloc(sizeof(struct list_item));


    struct list_item * root;

    root = (struct list_item*)malloc(sizeof(struct list_item));

    root->value = -1;
    root->next = NULL;

    /*Multiple tests in order to see if all functions are working correctly
     */

    //test print
    print(root);

    //test append/prepend
    //append(&root, 3);
    //append(&root, 2);
    //prepend(&root, -2);
    //append(&root, 1);
    //prepend(&root, -1);
    //print(&root);

    //test sorted_list
    //input_sorted(&root);
   // print(&root);

    //test clear
    clear_list(root);
    print(root);

    //test re-using append/prepend after clearing list
    append(root, 6);
    append(root, 5);
    prepend(root, -4);
    append(root, 4);
    prepend(root, -3);
    print(root);

    //test input_sorted after using clear
    input_sorted(root);
    print(root);

    //re-testing clear, adding a new list with prepend/append, sort it out.
    clear_list(root);
    append(root, 22);
    append(root, 312);
    prepend(root, -32321);
    append(root, 3293);
    prepend(root, 0);
    input_sorted(root);
    print(root);


    return 0;
};

void append(struct list_item *first, int x) //,
{

    /* now we can add a new variable */
    struct list_item * current;
    current = (struct list_item*)malloc(sizeof(struct list_item));

    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (struct list_item*)malloc(sizeof(struct list_item));

   // current->next = malloc(sizeof(struct list_item));
    current->next->value = x;
    current->next->next = NULL;

}

void clear_list(struct list_item *first)
{

    struct list_item *tmp;
    while(first != NULL){
        tmp= first;
        first = first->next;
        free(tmp);
    }
//    struct list_item *current = first;
//    struct list_item *next;
//
//
//    while (current->next != NULL)
//    {
//        //next = *current->next;
//        //free(current->next);
//        free(current->next);
//        current = next;
    }

//    void freeList(struct node* head)
//    {
//        struct node* tmp;
//
//        while (head != NULL)
//        {
//            tmp = head;
//            head = head->next;
//            free(tmp);
//        }
//
//    }

    // Allocate the value NULL to the attribut *next of the first element
    // Note: At this point, the first element (root) is going to be the unique element of the list.
//    first->next = NULL;
//    current = NULL;
//    printf("The list has been clear !\n");
//}
