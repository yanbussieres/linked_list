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
// void prepend(struct list_item *first, int x);
// void input_sorted(struct list_item *first);
void swap(struct list_item *a, struct list_item *b);  // Function used too swap 2 nodes. Used in the input_sorted function.
void clear_list(struct list_item *first);

int list_size = 0;


int main()
{

    //
    struct list_item root;
    //
    //root = (struct list_item*)malloc(sizeof(struct list_item));
    root.value = -1;
    root.next = NULL;
    append(&root, 4545);
    append(&root, 4);
    append(&root, 32);
    clear_list(&root);
    print(&root);
    //clear_list(root);

    //free(root);

    return 0;
};

void clear_list(struct list_item *first)
{

  struct list_item *tmp;
  while(first != NULL){
    tmp= first;
    first = first->next;
    free(tmp);
  }
  struct list_item *current = first;
  struct list_item *next;


  while (current->next != NULL)
  {
    //next = *current->next;
    //free(current->next);
    free(current->next);
    current = next;
  }
}

void append(struct list_item *first, int x) //,
{
    struct list_item * current = first;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (struct list_item*)malloc(sizeof(struct list_item));

   // current->next = malloc(sizeof(struct list_item));
    current->next->value = x;
    current->next->next = NULL;
    //free(current->next);
}



void print(struct list_item *first) {
    if (first->next==NULL){
        //printf("Nothing to print! The list is empty!\n");
    }
    else{
      struct list_item * current = first->next;

      while (current != NULL) {
          printf("%d\n", current->value);
          current = current->next; // (*current).next
      }
    }
}

// void prepend(struct list_item *first, int x){
//     struct list_item * new_item;
//     new_item = (struct list_item*)malloc(sizeof(struct list_item));
//
//     new_item->value = x;
//     new_item->next = first->next;
//     first->next = new_item;
//     first = new_item;
//     }

// void input_sorted(struct list_item *first)
// {
//     int swapped;
//     struct list_item *ptr1;
//     struct list_item *lptr = NULL;
//
//     /* Checking for empty list */
//     if (first->next == NULL){
//         printf("Cannot sort an empty list ! \n");
//         return;
//     }
//     printf("The list stored in memory has been sorted\n");
//     do
//     {
//         swapped = 0;  // Acting as a boolen.
//         ptr1 = first->next;    // first->next in order to avoid the first element.
//
//         while (ptr1->next != lptr)
//         {
//             if (ptr1->value > ptr1->next->value)
//             {
//                 swap(ptr1, ptr1->next);
//                 swapped = 1;
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     }
//     while (swapped);
// }
//
// /* function to swap list_item of two list_items a and b*/
void swap(struct list_item *a, struct list_item *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
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
