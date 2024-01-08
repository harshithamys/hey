#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int stack[MAX], top = -1, status = 0, item;

void push() {
    if (top == (MAX - 1))
        printf("Overflow\n");
    else {
        stack[++top] = item;
        status++;
    }
}

int pop() {
    int ret;
    if (top == -1)
        printf("Underflow\n");
    else {
        ret = stack[top--];
        printf("Deleted element is %d\n", ret);
        status--;
    }
    return ret;
}

void palindrome() {
    int temp, count = 0, i;
    temp = status;

    for (i = 0; i < temp; i++) {
        if (stack[i] == pop()) {
            count++;
        }
    }

    if (temp == count)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}

void display() {
    int i;
    printf("Stack elements are:\n");

    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    int ch;

    while (1) {
        printf("1. Push 2. Pop 3. Palindrome 4. Display\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
