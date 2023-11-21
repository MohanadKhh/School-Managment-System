/*
// Created by Mohanad.Khh on 8/3/2023.
*/

#include <stdio.h>
#include <string.h>
#include "students.h"       // Include your header file

List list;      /* Declare a global instance of List for student data*/

/* Function to add a new student to the list*/
void NEW_STUDENT() {
    ListEntry newStudent;
    ListEntry *ptrNewStudent = &newStudent;

    printf("\nEnter Student Name: ");
    gets(newStudent.name); /* Gather student information */

    char flag = 1;
    while (flag) {
        flag = 0;
        printf("Enter ID: ");
        scanf("%d", &newStudent.ID); /* Gather student information */
        while (getchar() != '\n'); // Clear input buffer
        size_t i;
        for (i = 0; i < listSize(&list); ++i) { /* Find the position of the student with the given ID */
            if (getEntry(&list, i).ID == newStudent.ID) {
                flag = 1;
                printf("\nThis ID is Taken, Try another one...\n");
                break;
            }
        }
    }

    printf("Enter Address: ");
    gets(newStudent.address); // Gather student information

    printf("Enter Date of Birth (dd/mm/yyyy): ");
    gets(newStudent.dateOfBD);

    printf("Enter Phone Number: ");
    scanf("%lld", &(ptrNewStudent->phoneNumber)); // Gather student information
    while (getchar() != '\n'); // Clear input buffer

    printf("\n");

    // Initialize scores to zero
    newStudent.scoreCS = 0;
    newStudent.scoreARM = 0;
    newStudent.scoreAUTO = 0;
    newStudent.scoreALL = 0;

    insert(&list, newStudent, 0); /* Push student information in the list as struct */
}

/* Function to delete a student from the list*/
void DELETE_STUDENT() {
    short position = -1;

    /* Keep asking for student ID until a valid ID is found */
    while (position == -1) {
        int id;
        printf("\nEnter student ID that you want to delete: ");
        scanf("%d", &id);

        size_t i;
        for (i = 0; i < listSize(&list); ++i) { /* Find the position of the student with the given ID */
            if (getEntry(&list, i).ID == id) {
                position = i;
            }
        }
        if (position != -1) { /* Perform deletion if the position is valid */
            clearNode(&list, position);
            printf("\n--------------- Deleted Successfully ---------------\n");
        } else {
            char condition;
            printf("\nThere is no student ID equal %d\n", id);
            printf("press (1) to re-enter ID or others to quit: ");
            scanf("%d", &condition);
            if (condition != 1) {
                position = 0;
            }
        }
    }
}

static void sorted(List *pl) {
    /* Iterate through the list entries for sorting */
    size_t i;
    for (i = 0; i < listSize(pl); i++) {
        char flag = 1;
        Student s = getEntry(pl, i);  /* Get the current student at index 'i' */

        /* Compare the current student's name with the names of subsequent students */
        size_t j;
        for (j = i + 1; j < listSize(pl); j++) {
            if (stricmp(s.name, getEntry(pl, j).name) > 0) {
                flag = 0;  /* Set the flag to indicate unordered elements */
                break;     /* Exit the loop if an out-of-order element is found */
            }
        }

        /* If flag is false, swap the current student with the out-of-order student */
        if (!flag) {
            insert(pl, s, listSize(pl));  /* Insert the current student at the end */
            clearNode(pl, i);             /* Remove the current student from its original position */
            i--;                          /* Decrement 'i' to re-evaluate the current position */
        }
    }
}


static void Print_List(List *ptrList) {
    ListNode *temp = ptrList->head;

    /* Check if the list is empty */
    if (temp == NULL) {
        printf("\nEmpty!! no data to show\n");
        return;
    }

    /* Print the header for the student data table */
    printf("\n________________________________________________________________________________________________________________________"
           "          Name         |    ID     |      Phone      |  Birth Date  |        Address         |   Score\n"
           "------------------------------------------------------------------------------------------------------------------------\n");

    /* Iterate through the list and print each student's information */
    while (temp != NULL) {
        printf("%-23s| %-10d| +20 %-12lld| %-13s| %-23s| C-Programming (100): %d\n"
               "                       |           |                 |              |                        | ARM (100)          : %d\n"
               "                       |           |                 |              |                        | Automotive (100)   : %d\n"
               "                       |           |                 |              |                        | Total (300)        : %d\n"
               "------------------------------------------------------------------------------------------------------------------------\n",
               temp->entry.name, temp->entry.ID,
               temp->entry.phoneNumber,
               temp->entry.dateOfBD, temp->entry.address, temp->entry.scoreCS, temp->entry.scoreARM,
               temp->entry.scoreAUTO, temp->entry.scoreALL);
        temp = temp->next;
    }
}


void STUDENT_LIST(List *ptrList) {
    sorted(ptrList);   /* Sort list Alphabetically */
    Print_List(ptrList);    /* Print List in a table form after sorted it */
}

void STUDENT_EDIT() {
    short position = -1;

    /* Loop to ensure a valid student ID is provided */
    while (position == -1) {
        int id;
        printf("\nEnter student ID that you want to edit his data: ");
        scanf("%d", &id);

        /* Find the position of the student with the given ID */
        size_t i;
        for (i = 0; i < listSize(&list); ++i) {
            if (getEntry(&list, i).ID == id) {
                position = i;
                break;  /* Exit loop once position is found */
            }
        }

        /* If a valid student is found, allow editing */
        if (position != -1) {
            short y = 1;
            while (y) {
                ListEntry editStudent = getEntry(&list, position);
                printf("\nChoose what you want to edit:\n");
                printf("1. Name     2. Address     3. Date of Birth     4. Phone Number     5. Finish\n");
                scanf("%d", &y);
                while (getchar() != '\n');

                switch (y) {
                    case 1:
                        printf("\nEnter new name: ");
                        gets(editStudent.name);  /* Read new name from user */
                        replace(&list, editStudent, position);  /* Replace student data in the list */
                        break;
                    case 2:
                        printf("\nEnter new Address: ");
                        gets(editStudent.address);  /* Read new address from user */
                        replace(&list, editStudent, position);  /* Replace student data in the list */
                        break;
                    case 3:
                        printf("\nEnter new Date of Birth: ");
                        gets(editStudent.dateOfBD);  /* Read new date of birth from user */
                        replace(&list, editStudent, position);  /* Replace student data in the list */
                        break;
                    case 4:
                        printf("\nEnter new Phone Number: ");
                        scanf("%lld", &editStudent.phoneNumber);  /* Read new phone number from user */
                        while (getchar() != '\n');
                        replace(&list, editStudent, position);  /* Replace student data in the list */
                        break;
                    case 5:
                        printf("\n--------------- Edited Successfully ---------------\n");
                        y = 0;  /* Finish editing loop */
                        break;
                    default:
                        printf("\n !!!!!!!!!! Wrong choice !!!!!!!!!!\n"
                               "Please choose from (1 -> 5)\n");
                        break;
                }
            }
        } else {
            char condition;
            printf("\nThere is no student with ID equal to %d\n", id);
            printf("Press (1) to re-enter ID or any other key to quit: ");
            scanf("%d", &condition);
            if (condition != 1) {
                position = 0;  /* Exit the loop */
            }
        }
    }
}


void UPDATE_STUDENTS_SCORE() {
    ListEntry studentScore;

    /* Iterate through the list to update students' scores */
    size_t i;
    for (i = 0; i < listSize(&list); ++i) {
        do {
            /* Check for invalid scores exceeding the limit */
            if (studentScore.scoreCS > 100 || studentScore.scoreARM > 100 || studentScore.scoreAUTO > 100) {
                printf("\nError !!!!!\n"
                       "Enter valid score min.(0) & max.(100)\n");
            }

            /* Get the current student's information */
            studentScore = getEntry(&list, i);

            /* Prompt user for scores */
            printf("\nEnter Scores of %s...\n", studentScore.name);
            printf("Note: Max.(100) & Min.(0)\n\n");

            printf("C-Programming = ");
            scanf("%d", &studentScore.scoreCS);

            printf("ARM = ");
            scanf("%d", &studentScore.scoreARM);

            printf("Automotive = ");
            scanf("%d", &studentScore.scoreAUTO);

            /* Calculate the total score for the student */
            studentScore.scoreALL = studentScore.scoreCS + studentScore.scoreARM + studentScore.scoreAUTO;

            /* Replace the student's updated data in the list */
            replace(&list, studentScore, i);

            /* Repeat the input process if any score is out of bounds */
        } while (studentScore.scoreCS > 100 || studentScore.scoreARM > 100 || studentScore.scoreAUTO > 100);
    }
}


static void Print_RankedList(List *ptrList) {
    ListNode *temp = ptrList->head;  /* Pointer to traverse the ranked list */
    if (temp == NULL) {
        printf("\nEmpty!! no data to show\n");  /* Handle empty list case */
        return;
    }

    /* Print header for the ranked list table */
    printf("_______________________________________________________________\n");
    printf("          Name            |    ID     |      Score\n"
           "---------------------------------------------------------------\n");

    /* Iterate through the ranked list and print each student's information */
    while (temp != NULL) {
        printf("%-25s | %-10d| C-Programming (100): %d\n"
               "                          |           | ARM (100)          : %d\n"
               "                          |           | Automotive (100)   : %d\n"
               "                          |           | Total (300)        : %d\n"
               "---------------------------------------------------------------\n",
               temp->entry.name, temp->entry.ID, temp->entry.scoreCS, temp->entry.scoreARM,
               temp->entry.scoreAUTO, temp->entry.scoreALL);
        temp = temp->next;  /* Move to the next student node */
    }
}


void RANK_STUDENT() {
    printf("\nChoose which rank you want....\n");
    printf("1. C-Programming Level     2. ARM Level     3. Automotive Level     4. Total Score\n");

    char condition = 1;
    while (condition) {
        int z;
        size_t i;
        size_t j;
        scanf("%d", &z);

        switch (z) {
            case 1:
                /* Rank students based on C-Programming scores */
                for (i = 0; i < listSize(&list); i++) {
                    int flag = 1;
                    Student s = getEntry(&list, i);

                    /* Compare with other students for ranking */
                    for (j = i + 1; j < listSize(&list); j++) {
                        if (s.scoreCS < getEntry(&list, j).scoreCS) {
                            flag = 0;
                            break;  /* Exit loop if ranking is not required */
                        }
                    }

                    /* Reorder list for ranking and update index */
                    if (!flag) {
                        insert(&list, s, listSize(&list));  /* Insert student in proper rank */
                        clearNode(&list, i);  /* Remove the original entry from the list */
                        i--;  /* Adjust index for further processing */
                    }
                }
                printf("\n____________ Student Ranks of C-Programming Level ____________\n");
                Print_RankedList(&list);
                condition = 0;  /* Exit the loop */
                break;

            case 2:
                /* Rank students based on ARM scores */
                for (i = 0; i < listSize(&list); i++) {
                    int flag = 1;
                    Student s = getEntry(&list, i);

                    /* Compare with other students for ranking */
                    for (j = i + 1; j < listSize(&list); j++) {
                        if (s.scoreARM < getEntry(&list, j).scoreARM) {
                            flag = 0;
                            break;  /* Exit loop if ranking is not required */
                        }
                    }

                    /* Reorder list for ranking and update index */
                    if (!flag) {
                        insert(&list, s, listSize(&list));  /* Insert student in proper rank */
                        clearNode(&list, i);  /* Remove the original entry from the list */
                        i--;  /* Adjust index for further processing */
                    }
                }
                printf("\n_________________ Student Ranks of ARM Level _________________\n");
                Print_RankedList(&list);
                condition = 0;  /* Exit the loop */
                break;

            case 3:
                /* Rank students based on Automotive scores */
                for (i = 0; i < listSize(&list); i++) {
                    int flag = 1;
                    Student s = getEntry(&list, i);

                    /* Compare with other students for ranking */
                    for (j = i + 1; j < listSize(&list); j++) {
                        if (s.scoreAUTO < getEntry(&list, j).scoreAUTO) {
                            flag = 0;
                            break;  /* Exit loop if ranking is not required */
                        }
                    }

                    /* Reorder list for ranking and update index */
                    if (!flag) {
                        insert(&list, s, listSize(&list));  /* Insert student in proper rank */
                        clearNode(&list, i);  /* Remove the original entry from the list */
                        i--;  /* Adjust index for further processing */
                    }
                }
                printf("\n______________ Student Ranks of Automotive Level ______________\n");
                Print_RankedList(&list);
                condition = 0;  /* Exit the loop */
                break;

            case 4:
                /* Rank students based on Total scores */
                for (i = 0; i < listSize(&list); i++) {
                    int flag = 1;
                    Student s = getEntry(&list, i);

                    /* Compare with other students for ranking */
                    for (j = i + 1; j < listSize(&list); j++) {
                        if (s.scoreALL < getEntry(&list, j).scoreALL) {
                            flag = 0;
                            break;  /* Exit loop if ranking is not required */
                        }
                    }

                    /* Reorder list for ranking and update index */
                    if (!flag) {
                        insert(&list, s, listSize(&list));  /* Insert student in proper rank */
                        clearNode(&list, i);  /* Remove the original entry from the list */
                        i--;  /* Adjust index for further processing */
                    }
                }
                printf("\n_______________ Student Ranks by Total Score _______________\n");
                Print_RankedList(&list);
                condition = 0;  /* Exit the loop */
                break;

            default:
                /* Invalid choice from the user */
                printf("\n !!!!!!!!!! Wrong choice !!!!!!!!!!\n"
                       "Please choose from (1 -> 4)\n");
                break;
        }
    }
}