/*
// Created by Mohanad.Khh on 8/3/2023.
*/

#ifndef SCHOOL_MANAGEMENT_SYSTEM_STUDENTS_H
#define SCHOOL_MANAGEMENT_SYSTEM_STUDENTS_H

#include "list.h"

extern List list;

/* Function prototypes for managing student information */

void NEW_STUDENT(); /* Add a new student to the system */

void DELETE_STUDENT(); /* Delete a student from the system */

void STUDENT_LIST(List *ptrList); /* Display a list of students */

void STUDENT_EDIT(); /* Edit student information */

void UPDATE_STUDENTS_SCORE(); /* Update students' scores */

void RANK_STUDENT(); /* Rank students based on their scores */

#endif /*SCHOOL_MANAGEMENT_SYSTEM_STUDENTS_H*/