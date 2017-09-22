/**
 * Generic Linked List
 *
 * Like Java in c a Linked List must accept any data value in C
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    void* data;
    struct node* next;
} node;

void push(node **h, void* new_data, size_t data_size)
{
    node* newN = (node*)malloc(sizeof(node));
    newN->data = malloc(data_size);
    newN->next = *h;
    //copy contents of new_data to newly allocated memory
    //char takes 1 bytes so using char to copy
    for(int i=0;i<data_size;i++)
        *(char *)(newN->data + i) = *(char *)(new_data + i);

    *h = newN;
}

//fptr to access the function to be used for printing current node data
//as different data type needs different specifier in printf
void printList(node *h, void (*fptr)(void*))
{
    while(h)
    {
        (*fptr)(h->data);
        h=h->next;
    }
}

//casting void to int
void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

//casting void to float
void printFloat(void *n)
{
    printf(" %f", *(float *)n);
}

int main()
{
    node * head = NULL;
    unsigned int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40, 50};

    for(int i=0;i<5;i++)
        push(&head, &arr[i], int_size);

    printf("\nInteger Linked List is \n");
    printList(head, printInt);

    unsigned float_size = sizeof(float);
    head = NULL;
    float arr2[] = {10.1,20.1,30.1,40.1,50.1};

    for(int i=0;i<5;i++)
        push(&head, &arr2[i], float_size);

    printf("\nFloat Linked List is \n");
    printList(head, printFloat);
}
