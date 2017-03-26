/**
 * @file main.c
 * @author: Zhang Hai
 */

#include "Common.h"

#include "LinkedStack.h"


int main() {
    LinkedStack *stack;
    Time_start();
    stack = LinkedStack_new();
    $(stack, delete);
    return 0;
}
