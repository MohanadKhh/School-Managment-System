//
// Created by Mohanad.Khh on 8/3/2023.
//


#include <stdlib.h>
#include "stack.h"

void intializeStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}

void push(Stack *ps, StackEntry e) {
    StackNode *pn = (StackNode *) malloc(sizeof e);
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop(Stack *ps, StackEntry *pe) {
    StackNode *pn = ps->top;
    *pe = pn->entry;
    ps->top = pn->next;
    free(pn);
    ps->size--;
}

char stackFull(Stack *ps) {
    return 0;
}

int stackEmpty(Stack *ps) {
    return !ps->top;
}

StackEntry stackTop(Stack *ps) {
    return ps->top->entry;
}

int stackSize(Stack *ps) {
    return ps->size;
}

void clearStack(Stack *ps) {
    StackNode *pn = ps->top;
    while (pn) {
        pn = ps->top->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}
