#ifndef DATASTRUCTURE_HEAP_SORT_H
#define DATASTRUCTURE_HEAP_SORT_H
#define GREATER 1
#define LESS 0

void siftdown_greater(int a[], int i, int n)
{
    int j = 2 * i + 1, t = a[i];
    while ( j < n ){
        if (j < n-1 && a[j] < a[j+1]){
            j ++;
        }
        if (t < a[j]){
            a[i] = a[j];
            i = j;
        }else{
            break;
        }
        j = 2 * i + 1;
    }
    a[i] = t;
}

void swim_greater(int a[], int k)
{
    int t;
    while(k > 0 && a[(k - 1) / 2] < a[k]){
        t = a[(k - 1) / 2];
        a[(k - 1) / 2] = a[k];
        a[k] = t;

        k = (k - 1) / 2;
    }
}

void siftdown_less(int a[], int i, int n)
{
    int j = 2 * i + 1, t = a[i];
    while ( j < n ){
        if (j < n-1 && a[j] > a[j+1]){
            j ++;
        }
        if (t > a[j]){
            a[i] = a[j];
            i = j;
        }else{
            break;
        }
        j = 2 * i + 1;
    }
    a[i] = t;
}

void swim_less(int a[], int k)
{
    int t;
    while(k > 0 && a[(k - 1) / 2] > a[k]){
        t = a[(k - 1) / 2];
        a[(k - 1) / 2] = a[k];
        a[k] = t;

        k = (k - 1) / 2;
    }
}

void build_heap(int a[], int n, int cmp)
{
    if(cmp == GREATER){
        for(int i = (n - 2) / 2; i >= 0; i --){
            siftdown_greater(a, i, n);
        }
    }else if(cmp == LESS){
        for(int i = (n - 2) / 2; i >= 0; i --){
            siftdown_less(a, i, n);
        }
    }
}

void Test()
{
    int a[] = {46, 26, 22, 68, 48, 42, 36, 84, 66};
    int n = 9;
    build_heap(a, n, GREATER);
    for(int i = 0 ; i < n ; i ++){
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
}

#endif //DATASTRUCTURE_HEAP_SORT_H
