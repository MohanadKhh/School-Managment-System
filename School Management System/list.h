/*
// Created by Mohanad.Khh on 8/3/2023.
*/

#ifndef SCHOOL_MANAGEMENT_SYSTEM_LIST_H
#define SCHOOL_MANAGEMENT_SYSTEM_LIST_H

#define NameSize 30
#define DteOfBirth_SIZE 15
#define AddressSize 30

/* Define the structure for student information */
typedef struct student {
    char name[NameSize]; /* Student's name */
    char dateOfBD[DteOfBirth_SIZE]; /* Student's date of birth */
    unsigned int ID; /* Student's ID */
    char address[AddressSize]; /* Student's address */
    unsigned long long int phoneNumber; /* Student's phone number */
    unsigned char scoreCS; /* Student's Computer Science score */
    unsigned char scoreARM; /* Student's ARM Architecture score */
    unsigned char scoreAUTO; /* Student's Automotive Engineering score */
    unsigned short scoreALL; /* Student's overall score */
} Student;

typedef Student ListEntry; /* List entry type is Student */

/* Define the structure for a list node */
typedef struct listNode {
    struct listNode *next; /* Pointer to the next node */
    ListEntry entry; /* Entry value stored in the node */
} ListNode;

/* Define the structure for a list */
typedef struct list {
    ListNode *head; /* Pointer to the first node in the list */
    short size; /* Current size of the list */
} List;

/* Function prototypes */

void intializeList(List *pl); /* Initialize a list */

void insert(List *pl, ListEntry e, int pos); /* Insert an entry into the list at a specified position */

void delete(List *pl, ListEntry *pe, int pos); /* Delete an entry from the list at a specified position */

void clearNode(List *pl, int pos); /* Clear a node from the list at a specified position */

void replace(List *pl, ListEntry e, int pos); /* Replace the entry in a node at a specified position */

void clearList(List *pl); /* Clear all nodes in the list and free memory */

Student getEntry(List *pl, int pos); /* Display the entry value of a node at a specified position */

int listEmpty(List *pl); /* Check if the list is empty */

int listFull(List *pl); /* Check if the list is full */

int listSize(List *pl); /* Get the current size of the list */

#endif /*SCHOOL_MANAGEMENT_SYSTEM_LIST_H*/