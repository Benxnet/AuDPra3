#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 200000


int list[MAX];


void randarray (){
    for (int i = 0; i < MAX; ++i) {
        list[i] = rand();
    }
}
void maxmin (){
    int j;
    for (int i = MAX; 0 < i; --i) {
        list[j] = i;
        ++j;
    }
}
void minmax (){
    for (int i = 0; i < MAX; ++i) {
        list[i] = i-1;
    }
}

void selection (int a[], int N)
{
    int i, j, min, t;

    for (i = 1; i < N; i++)
    {
        min = i;
        for (j = i + 1; j <= N; j++)
            if (a[j] < a[min]) min = j;
        t = a[min]; a[min] = a[i]; a[i] = t;
    }
}


void insertion (int a[], int N)
{
    int i, j, v;

    for (i = 2; i <= N; i++)
    {
        v = a[i]; j = i;
        while (a[j-1] > v)
        {a[j] = a[j-1]; j--;}
        a[j] = v;
    }
}
void shellsort (int a[], int N)
{
    int i, j, h, v;

    for (h = 1; h <= N/3; h = 3*h + 1) ;
    for ( ; h > 0; h /= 3)
        for (i = h + 1; i <= N; i++)
        {
            v = a[i]; j = i;
            while (j > h && a[j-h] > v)
            { a[j] = a[j-h]; j -= h;}
            a[j] = v;
        }
}

void quicksort (int a[], int l, int r)
{
    int v, i, j, t;

    if (r > l)
    {
        v = a[r]; i = l-1; j = r;
        for (;;)
        {
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;
        quicksort (a, l, i-1);
        quicksort (a, i+1, r);
    }
}

int b[MAX+1];
void mergesort (int a[], int l, int r)
{
    int i, j, k, m;

    if (r > l)
    {
        m = (r + l)/2;
        mergesort (a, l, m);
        mergesort (a, m+1, r);
        for (i = m+1; i > l; i--) b[i-1] = a[i-1];
        for (j = m; j < r; j++) b[r+m-j] = a[j+1];
        for (k = l; k <= r; k++)
            a[k] = (b[i] < b[j])? b[i++] : b[j--];
    }
}

static int a[MAX+1], N;

void upheap (int k)
{
    int v;

    v = a[k]; a[0] = INT_MAX;
    while (a[k/2] <= v)
    { a[k] = a[k/2]; k = k/2; }
    a[k] = v;
}

void insert (int v)
{
    a[++N] = v;
    upheap (N);
}

void downheap (int k)
{
    int j, v;

    v = a[k];
    while (k <= N/2)
    {
        j = k+k;
        if (j < N && a[j] < a[j+1]) j++;
        if (v >= a[j]) break;
        a[k] = a[j]; k = j;
    }
    a[k] = v;
}

int removeheap()
{
    int v = a[1];

    a[1] = a[N--];
    downheap (1);
    return v;
}

void heapsort (int a[], int laenge)
{
    int k;

    for (k = 1; k <= laenge; k++) insert (a[k]);
    for (k = laenge; k >= 1; k--) a[k] = removeheap();
}







int main() {
    clock_t start_t, ende_t;
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < 3 ; ++i) {
        randarray();
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        printf("Laufzeit %.5f Sekunden\n",(float)(ende_t-start_t) / CLOCKS_PER_SEC);
    }
    for (int i = 0; i < 3 ; ++i) {
        minmax();
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        printf("Laufzeit %.5f Sekunden\n",(float)(ende_t-start_t) / CLOCKS_PER_SEC);
    }
    for (int i = 0; i < 3 ; ++i) {
        maxmin();
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        printf("Laufzeit %.5f Sekunden\n",(float)(ende_t-start_t) / CLOCKS_PER_SEC);
    }
    return 0;
}
