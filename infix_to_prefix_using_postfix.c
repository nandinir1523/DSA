#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char ch) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = ch;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int i, j;
    char ch;

    for (i = strlen(infix) - 1, j = 0; i >= 0; i--) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == ')') {
            push(&s, ch);
        } else if (ch == '(') {
            while (s.top != -1 && s.stack[s.top] != ')') {
                postfix[j++] = pop(&s);
            }
            if (s.top == -1) {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(1);
            }
            pop(&s); // Discard the '('
        } else if (isOperator(ch)) {
            while (s.top != -1 && precedence(ch) <= precedence(s.stack[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (s.top != -1) {
        if (s.stack[s.top] == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    // Reverse the postfix expression to get the prefix expression
    int len = strlen(postfix);
    for (i = 0; i < len / 2; i++) {
        char temp = postfix[i];
        postfix[i] = postfix[len - i - 1];
        postfix[len - i - 1] = temp;
    }
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Prefix expression: %s\n", postfix);

    return 0;
}
