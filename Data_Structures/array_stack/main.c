#include <stdio.h>
#include "stack.h"

int main() {
    Stack test;
    test = CreateStack(10);
    push(test, 100);
    PrintStack(test);
    for(int i = 0; i < 9; i ++){
        push(test, i);
    }
    printf("********************\n");
    PrintStack(test);

    printf("%d\n", pop(test));
    printf("********************\n");
    PrintStack(test);
    return 0;
}
