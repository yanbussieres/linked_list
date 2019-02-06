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
void real_input_sorted(struct list_item *first, int x);
void input_sorted(struct list_item *first);
void swap(struct list_item *a, struct list_item *b);  // Function used too swap 2 nodes. Used in the input_sorted function.
void clear_list(struct list_item *first);

int list_size = 0;


int main(int argc, char *argv[]){

    //
    struct list_item root;
    //
    //root = (struct list_item*)malloc(sizeof(struct list_item));
    root.value = -1;
    root.next = NULL;

    real_input_sorted(&root, 2);
    append(&root, 1);
    append(&root, 3);
    append(&root, 4);
    append(&root, 1);

    //real_input_sorted(&root, 2);
    print(&root);

    append(&root, 1);
    append(&root, 2);
    append(&root, 3);
    prepend(&root, -3);
    print(&root);
    clear_list(&root);
    print(&root);

    append(&root, 1);
    print(&root);
    append(&root, 2);
    prepend(&root, -3);
    append(&root, 3);
    print(&root);
    clear_list(&root);

    prepend(&root, -3);
    append(&root, 9);
    append(&root, 7);
    append(&root, 5);
    real_input_sorted(&root, -100);
    input_sorted(&root);
    print(&root);
    clear_list(&root);
    print(&root);
    input_sorted(&root);
    return 0;
};

void clear_list(struct list_item *first)
{
   struct list_item *current = first;

    while(current->next != NULL){
      struct list_item *temp = current->next->next;
      free(current->next);
      current->next = temp;
   }
   printf("The list is clear WITHOUT ANY MEMORY LEAKS!!! Party !\n");
}

void append(struct list_item *first, int x) //,
{
    struct list_item * current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (struct list_item*)malloc(sizeof(struct list_item));
    current->next->value = x;
    current->next->next = NULL;
}

void real_input_sorted(struct list_item *first, int x) //,
{

  struct list_item * current = first;
  struct list_item * next_item = current->next;

  if (current->next == NULL) {
    append(first, x);
  }
  else{
    while (next_item->value < x) {
      next_item = next_item->next;
      current = current->next;
      }
       current->next = (struct list_item*)malloc(sizeof(struct list_item));
       current->next->value = x;
       current->next->next = next_item;
     }
}



void print(struct list_item *first) {
    if (first->next==NULL){
        printf("Nothing to print! The list is empty!\n");
    }
    else{
      struct list_item * current = first->next;

      while (current != NULL) {
          printf("%d\n", current->value);
          current = current->next; // (*current).next
      }
    }
}

void prepend(struct list_item *first, int x){
    struct list_item * new_item;
    new_item = (struct list_item*)malloc(sizeof(struct list_item));

    new_item->value = x;
    new_item->next = first->next;
    first->next = new_item;
    first = new_item;
     }

void input_sorted(struct list_item *first)
{
    int swapped;
    struct list_item *ptr1;
    struct list_item *lptr = NULL;

    /* Checking for empty list */
    if (first->next == NULL){
        printf("Cannot sort an empty list ! \n");
        return;
    }
    printf("The list stored in memory has been sorted\n");
    do
    {
        swapped = 0;  // Acting as a boolen.
        ptr1 = first->next;    // first->next in order to avoid the first element.

        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

// /* function to swap list_item of two list_items a and b*/
void swap(struct list_item *a, struct list_item *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}
