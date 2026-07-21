#include<stdio.h>
#include<stdalign.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
int precedence(char);
int isOperator(char);
void infix_to_postfix(char *,char *);

int main() {
  char infix[MAX];
  char postfix[MAX];

  printf("Enter infix expression (no space, single char operands): ");
  fgets(infix,MAX,stdin);

  size_t len = strlen(infix);
  if (len>0 && infix[len-1] == '\n')
  {
    infix[len-1] = '\0';
  }

  infix_to_postfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}

void push(char item) {
  if (top >= MAX-1) {
    printf("Stack Overflow\n");
  }
  stack[++top] = item;
}

char pop() {
  if (top < 0) {
    printf("Stack Underflow\n");
    return '\0';
  }
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

void infix_to_postfix(char *infix, char *postfix) {
  int i=0, j=0;
  char ch, popped;

  while ((ch = infix[i++]) != '\0')
  {
    if (isalnum(ch)) {
      postfix[j++] = ch; // Operand
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (!isEmpty() && stack[top] != '(') {
        postfix[j++] = pop();
      }
      if (!isEmpty() && stack[top] == '(') {
        pop(); // Discard the '('
      }
    } else if (isOperator(ch)) {
      //  For left-associative operators
      while (!isEmpty() && precedence(stack[top]) >= precedence(ch)) {
        if (stack[top] == '^' && ch == '^') break; // Right-associative for ^
        postfix[j++] = pop();
      }
      push(ch);
    } 
  }

  // Pop remaning operators
  while (!isEmpty())
  {
    postfix[j++] = pop();
  }
  
  postfix[j] = '\0';
}
