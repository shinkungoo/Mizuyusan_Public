#include <stdio.h>
#include "list.h"

int main() {
    List test;
    test = MakeEmpty();
    PrintList(test);
    Delete(test, test->Next);
    for(int i = 0; i < 15; i ++){
        Insert(test, i, test->Next);
    }
    PrintList(test);
    Position target = Find(test, 13);
    Delete(test, target);
    PrintList(test);
    printf("%p\n", Find(test, 10));
    printf("%p\n", Find(test, 13));
    Insert(test, 0, NULL);
    PrintList(test);

    return 0;
}
