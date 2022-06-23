#include <stdio.h>
#include "list.h"

int main() {
    List test;
    test = MakeEmpty();
    for(int i = 0; i < 15; i ++){
        Insert(test, 0, i);
    }
    PrintList(test);
    Delete(test, 1);
    PrintList(test);
    printf("%d\n", Find(test, 13));
    printf("%d\n", Find(test, 12));
    for(int i = 0 ; i < 14; i ++){
        Delete(test, 0);
        PrintList(test);
    }


    return 0;
}
