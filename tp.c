#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum size for the stack

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0'; // Return null character if stack is empty
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check for balanced symbols
int isBalanced(FILE *fp) {
    Stack stack;
    initStack(&stack);
    int c, inSingleQuote = 0, inDoubleQuote = 0, inComment = 0;

    while ((c = fgetc(fp)) != EOF) {
        // Check for comments
        if (c == '/' && peek(&stack) == '*') {
            inComment = 1; // Start of multi-line comment
            pop(&stack);
            continue;
        }
        if (c == '*' && peek(&stack) == '/') {
            inComment = 0; // End of multi-line comment
            pop(&stack);
            continue;
        }
        // Toggle quotes
        if (c == '\'' && !inDoubleQuote && !inComment) {
            inSingleQuote = !inSingleQuote; // Toggle single quote flag
        } else if (c == '"' && !inSingleQuote && !inComment) {
            inDoubleQuote = !inDoubleQuote; // Toggle double quote flag
        }
        // Ignore characters in comments and quotes
        if (inComment || inSingleQuote || inDoubleQuote) {
            continue;
        }
        // Handle parentheses, brackets, and braces
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c); // Push opening symbols onto the stack
        } else if (c == ')' || c == '}' || c == ']') {
            char expected;
            if (c == ')') expected = '(';
            else if (c == '}') expected = '{';
            else expected = '[';

            if (isEmpty(&stack) || pop(&stack) != expected) {
                printf("Error: Unbalanced %c\n", c);
                return 0; // Unbalanced
            }
        }
    }
    // Check if stack is empty at the end
    if (!isEmpty(&stack)) {
        printf("Error: Unbalanced symbols\n");
        return 0; // Unbalanced
    }

    return 1; // Balanced
}

int main() {
    FILE *fp = fopen("test.c", "r"); // Replace with your file name
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (isBalanced(fp)) {
        printf("No syntax errors detected.\n");
    } else {
        printf("Syntax errors found.\n");
    }

    fclose(fp);
    return 0;
}
