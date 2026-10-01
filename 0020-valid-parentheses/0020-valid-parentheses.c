#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char element;
#define MAX 100000

struct stk {
    element *s;
    int top;
};

int IS_EMPTY(struct stk *s) { return (s->top == -1); }
int IS_FULL(struct stk *s)  { return (s->top == MAX - 1); }
element TOP_STACK(struct stk *s1) { return s1->s[s1->top]; }

struct stk* create() {
    struct stk* my_stack = malloc(sizeof(struct stk));
    my_stack->s = malloc(MAX * sizeof(element));
    my_stack->top = -1;
    return my_stack;
}

int push(struct stk *my_stack, element item) {
    if (IS_FULL(my_stack)) return 0;
    my_stack->s[++my_stack->top] = item;
    return 1;
}

int pop(struct stk *s1, element *item) {
    if (IS_EMPTY(s1)) return 0;
    *item = s1->s[s1->top--];
    return 1;
}

bool isValid(char *str) {
    struct stk *s = create();
    char wch, rch;
    int chk, p;

    for (p = 0; str[p] != '\0'; p++) {
        wch = str[p];

        if (wch == '{' || wch == '(' || wch == '[') {
            if (!push(s, wch)) { free(s->s); free(s); return false; }
        } 
        else if (wch == '}' || wch == ')' || wch == ']') {
            if (IS_EMPTY(s)) { free(s->s); free(s); return false; }
            rch = TOP_STACK(s);
            if ((wch == ')' && rch == '(') ||
                (wch == ']' && rch == '[') ||
                (wch == '}' && rch == '{'))
                pop(s, &rch);
            else { free(s->s); free(s); return false; }
        } 
        else { free(s->s); free(s); return false; } // invalid char
    }

    chk = IS_EMPTY(s);
    free(s->s);
    free(s);
    return chk;
}

