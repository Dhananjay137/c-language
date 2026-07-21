#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top < 0) return '\0';
    return stack[top--];
}

int isEmpty() {
    return top < 0;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Reverse a string
void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char temp[MAX];
    int i = 0, j = 0;
    char ch;

    // Step 1: Reverse the infix expression
    strcpy(temp, infix);
    reverse(temp);

    // Step 2: Convert reversed infix to "postfix-like"
    while ((ch = temp[i++]) != '\0') {
        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == ')') {          // Note: ) becomes ( after reverse
            push(ch);
        }
        else if (ch == '(') {          // Note: ( becomes ) after reverse
            while (!isEmpty() && stack[top] != ')') {
                prefix[j++] = pop();
            }
            if (!isEmpty()) pop();     // discard ')'
        }
        else if (isOperator(ch)) {
            while (!isEmpty() && precedence(stack[top]) > precedence(ch)) {
                // Note: > instead of >= for right-to-left scanning
                if (stack[top] == '^' && ch == '^') break;
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    // Step 3: Reverse the result to get final Prefix
    reverse(prefix);
}

int main() {
    char infix[MAX];
    char prefix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}