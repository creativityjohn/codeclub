#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 20

typedef struct node_struct
{
    int val;
    struct node_struct *pNextNode;
} node;

void ll_print(node *pNode)
{
    while (pNode != NULL)
    {
        printf("%d ", pNode->val);
        pNode = pNode->pNextNode;
    }
    printf("\n");
}

node* ll_add(int val, node *pNode)
{
    // save head to return if list is not empty
    node *pHead = pNode;
    node *pIterator = pNode;

    // check if this is first entry
    if (pIterator == NULL)
    {
        pIterator = malloc(sizeof(node));
        pIterator->val = val;
        pIterator->pNextNode = NULL;
        return pIterator;
    }

    // find end
    while (pIterator->pNextNode != NULL)
    {
        pIterator = pIterator->pNextNode;
    }

    // add new entry
    pIterator->pNextNode = malloc(sizeof(node));
    pIterator = pIterator->pNextNode;
    pIterator->val = val;
    pIterator->pNextNode = NULL;
    return pHead;
}

node* ll_delete(int val, node *pNode)
{
    // save head to return if list is empty
    node *pHead = pNode;
    node *pPreviousIterator = pNode;
    node *pIterator = pNode;

    // check if this is first entry
    if (pIterator == NULL)
    {
        return pHead;
    }

    // find entry
    // if item to delete is the head, must point to the next one
    if (pIterator->val == val)
    {
        return pIterator->pNextNode;
    }

    // previous iterator must point to the next one if current one is deleted
    pPreviousIterator = pIterator;
    pIterator = pIterator->pNextNode;

    while (pIterator != NULL)
    {
        if (pIterator->val == val)
        {
            pPreviousIterator->pNextNode = pIterator->pNextNode;
            return pHead;
        }
        else
        {
            pIterator = pIterator->pNextNode;
        }
    }

    return pHead;
}

void main()
{
    char input;
    int value;
    node *pLinkedList;

    pLinkedList = NULL;
    printf ("Integer Linked List\na x to add x, d x to delete x, p to print\n");
    while (1)
    {
        printf("waiting for input\n");
        scanf(" %c", &input);
        if (input != 'p')
        {
            scanf ("%d", &value);
        }
        switch (input)
        {
            case 'a':
                pLinkedList = ll_add(value, pLinkedList);
                break;
            case 'd':
                pLinkedList = ll_delete(value, pLinkedList);
                break;
            case 'p':
                ll_print(pLinkedList);
                break;
            case '\n':
                // do nothing
                break;
            default:
                printf("invalid input\n");
                break;
        }
    }
}

