/*
// Created by Mohanad.Khh on 8/3/2023.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void intializeList(List *pl) {
    pl->head = NULL; /* Set the head pointer to NULL, indicating an empty list */
    pl->size = 0; /* Initialize the size of the list to zero */
}

int listSize(List *pl) {
    return pl->size; /* Return the current size of the list */
}

void insert(List *pl, ListEntry e, int pos) {
    /* Check if the desired position is within the valid range */
    if (pl->size >= pos) {
        ListNode *p = NULL, *q = NULL; /* Declare pointers for new node and traversal */
        size_t i; /* Variable for loop counter */

        /* Allocate memory for the new node */
        p = (ListNode *) malloc(sizeof(ListNode));
        if (p) { /* Check if memory allocation was successful */
            p->entry = e; /* Assign the entry value to the new node */
            p->next = NULL; /* Initialize the new node's next pointer */

            if (pos == 0) { /* If inserting at the beginning */
                p->next = pl->head; /* New node points to the current head */
                pl->head = p; /* Update head to point to the new node */
            } else {
                /* Traverse the list to find the node before the desired position */
                for (q = pl->head, i = 0; i < pos - 1; i++) {
                    q = q->next;
                }
                /* Insert the new node between q and q->next */
                p->next = q->next;
                q->next = p;
            }
            pl->size++; /* Increment the list size */
        } else {
            printf("There is no free space !!"); /* Memory allocation failed */
        }
    } else {
        printf("This position is out of list range !!"); /* Invalid position */
    }
}

void delete(List *pl, ListEntry *pe, int pos) {
    /* Check if the desired position is within the valid range */
    if (pos <= pl->size) {
        ListNode *q = NULL, *tmp = NULL; /* Declare pointers for traversal and temporary storage */
        size_t i; /* Variable for loop counter */

        if (pos == 0) {
            *pe = pl->head->entry; /* Store the entry value of the head node to be deleted */
            tmp = pl->head->next; /* Store the next node after the head */
            free(pl->head); /* Deallocate memory for the head node */
            pl->head = tmp; /* Update head to point to the next node */
        } else {
            /* Traverse the list to find the node before the desired position */
            for (q = pl->head, i = 0; i < pos - 1; ++i) {
                q = q->next;
            }
            *pe = q->next->entry; /* Store the entry value of the node to be deleted */
            tmp = q->next->next; /* Store the next node after the one to be deleted */
            free(q->next); /* Deallocate memory for the node to be deleted */
            q->next = tmp; /* Update the previous node's next pointer to skip the deleted node */
        }
        pl->size--; /* Decrement the list size */
    } else {
        printf("This position is out of list range !!"); /* Invalid position */
    }
}

void clearNode(List *pl, int pos) {
    /* Check if the desired position is within the valid range */
    if (pos <= pl->size) {
        ListNode *q = NULL, *tmp = NULL; /* Declare pointers for traversal and temporary storage */
        size_t i; /* Variable for loop counter */

        if (pos == 0) {
            tmp = pl->head->next; /* Store the next node after the head */
            free(pl->head); /* Deallocate memory for the head node */
            pl->head = tmp; /* Update head to point to the next node */
        } else {
            /* Traverse the list to find the node before the desired position */
            for (q = pl->head, i = 0; i < pos - 1; i++) {
                q = q->next;
            }
            tmp = q->next->next; /* Store the next node after the one to be deleted */
            free(q->next); /* Deallocate memory for the node to be deleted */
            q->next = tmp; /* Update the previous node's next pointer to skip the deleted node */
        }
        pl->size--; /* Decrement the list size */
    } else {
        printf("This position is out of list range !!"); /* Invalid position */
    }
}

void replace(List *pl, ListEntry e, int pos) {
    /* Check if the desired position is within the valid range */
    if (pos <= pl->size) {
        size_t i; /* Variable for loop counter */
        ListNode *q = NULL; /* Declare pointer for traversal */

        /* Traverse the list to find the node at the desired position */
        for (q = pl->head, i = 0; i < pos; i++) {
            q = q->next;
        }

        q->entry = e; /* Replace the entry value of the node at the specified position */
    } else {
        printf("This position is out of list range !!"); /* Invalid position */
    }
}

Student getEntry(List *pl, int pos) {
    size_t i; /* Variable for loop counter */
    ListNode *pn = NULL; /* Declare pointer for traversal */

    /* Traverse the list to find the node at the desired position */
    for (pn = pl->head, i = 0; i < pos; ++i) {
        pn = pn->next;
    }

    if (pos <= pl->size) {
        return pn->entry; /* Return the entry value of the node at the specified position */
    } else {
        printf("This position is out of list range !!\n"
               "return garbage values !!!\n"); /* Invalid position */
        return pn->entry; /* Return the entry value, even though it may be garbage */
    }
}

void clearList(List *pl) {
    ListNode *pq = pl->head;
    while (pq) {
        pq = pl->head->next;
        free(pl->head);
        pl->head = pq;
    }
    pl->size = 0;
}

int listEmpty(List *pl) {
    return !pl->size;
}

int listFull(List *pl) {
    return 0;
}