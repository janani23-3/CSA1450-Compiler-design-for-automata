#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int apply_operator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int evaluate_expression(char *exp) {
    int stack[100];
    char opstack[100];
    int top = -1;
    int optop = -1;

    for(int i = 0; exp[i]; i++) {
        if(exp[i] == ' ')
            continue;

        if(isdigit(exp[i])) {
            int num = 0;
            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        }
        else if(exp[i] == '(') {
            opstack[++optop] = exp[i];
        }
        else if(exp[i] == ')') {
            while(optop != -1 && opstack[optop] != '(') {
                int b = stack[top--];
                int a = stack[top--];
                char op = opstack[optop--];
                stack[++top] = apply_operator(a, b, op);
            }
            optop--;
        }
        else {
            while(optop != -1 && precedence(opstack[optop]) >= precedence(exp[i])) {
                int b = stack[top--];
                int a = stack[top--];
                char op = opstack[optop--];
                stack[++top] = apply_operator(a, b, op);
            }
            opstack[++optop] = exp[i];
        }
    }

    while(optop != -1) {
        int b = stack[top--];
        int a = stack[top--];
        char op = opstack[optop--];
        stack[++top] = apply_operator(a, b, op);
    }

    return stack[top];
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluate_expression(expression);
    printf("Result: %d\n", result);

    return 0;
}

