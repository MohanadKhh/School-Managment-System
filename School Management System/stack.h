//
// Created by Mohanad.Khh on 8/3/2023.
//

#ifndef SCHOOL_MANAGEMENT_SYSTEM_STACK_H
#define SCHOOL_MANAGEMENT_SYSTEM_STACK_H

typedef struct student {
    char name[55];
    char dateOfBD[10];
    int ID;
    char address[150];
    long long int phoneNumber;
} Student;

typedef Student StackEntry;

typedef struct stackNode {
    struct stackNode *next;
    StackEntry entry;
} StackNode;

typedef struct stack {
    StackNode *top;
    int size;
} Stack;

void intializeStack(Stack *ps);

void push(Stack *ps, StackEntry e);

void pop(Stack *ps, StackEntry *pe);

char stackFull(Stack *ps);

int stackEmpty(Stack *ps);

StackEntry stackTop(Stack *ps);

int stackSize(Stack *ps);

void clearStack(Stack *ps);

#endif //SCHOOL_MANAGEMENT_SYSTEM_STACK_H
