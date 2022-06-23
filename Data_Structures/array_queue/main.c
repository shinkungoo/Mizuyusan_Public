#include <stdio.h>
#include "queue.h"

int main() {
    Queue test = CreateQueue(10);
    PrintQueue(test);
    printf("%d\n", Dequeue(test));
    for(int i = 0 ; i < 15; i ++){
        printf("%d\n", Enqueue(test, i));
    }
    PrintQueue(test);
    for (int i = 0; i < 5; ++i) {
        Dequeue(test);
    }
    PrintQueue(test);
    for (int i = 0; i < 3; ++i) {
        Enqueue(test, i);
    }
    PrintQueue(test);

    return 0;
}
