/*
// Created by Mohanad.Khh on 8/3/2023.
*/

#include <stdio.h>
#include "students.h"

int main() {
    intializeList(&list);
    printf("\n");
    printf("\\         /\'         //   ||=====   ||       ,=======   ,======,       /\'        /\'      ||===== \n");
    printf(" \\       // \\       //    ||        ||       ||         ||    ||      // \\      // \\     ||      \n");
    printf("  \\     //   \\     //     ||=====   ||       ||         ||    ||     //   \\    //   \\    ||===== \n");
    printf("   \\   //     \\   //      ||        ||       ||         ||    ||    //     \\  //     \\   ||      \n");
    printf("    \\ //       \\ //       ||=====   '======  '=======   '======'   //       \\//       \\  ||===== \n");

    printf("\n");
    printf("                ====||==== ,======,           ||\\   || ====||==== ====||==== \n");
    printf("                    ||     ||    ||           || \\  ||     ||         ||     \n");
    printf("                    ||     ||    ||           ||  \\ ||     ||         ||     \n");
    printf("                    ||     '======'           ||   \\||     ||     ====||==== \n");

    printf("\n-------------------------------------- Welcome to our NTI School --------------------------------------\n"
           "----------------------------------- This a management system program -----------------------------------\n"
           "-------------------------- At this program we help you to manage students data --------------------------\n");

    int x = 1;
    while (x) {
        printf("\nThese are the activities that we provided:\n");
        printf("1. Enter data of new student\n"
               "2. Delete data of student\n"
               "3. Display all students data\n"
               "4. Edit data of student\n"
               "5. Display the Students ranks of course\n"
               "6. Update score of students for each course\n"
               "7. Quit from Program\n"
               "Please, Choose which activity you want (1 -> 7): ");
        scanf("%i", &x);
        while (getchar() != '\n');

        switch (x) {
            case 1:
                NEW_STUDENT(); /* Call function to enter data of new student */
                break;
            case 2:
                DELETE_STUDENT(); /* Call function to delete data of student */
                break;
            case 3:
                STUDENT_LIST(&list); /* Call function to getEntry all students data */
                break;
            case 4:
                STUDENT_EDIT(); /* Call function to edit data of student */
                break;
            case 5:
                RANK_STUDENT(); /* Call function to getEntry the Students ranks of course */
                break;
            case 6:
                UPDATE_STUDENTS_SCORE(); /* Call function to update score of students for each course */
                break;
            case 7:
                x = 0; /* Set x to 0 to quit from the program */
                break;
            default:
                printf("\n!!!!!!!!!! Wrong choice !!!!!!!!!!\n"
                       "Please choose from (1->7)...\n");
                break;
        }
    }
    return 0;
}