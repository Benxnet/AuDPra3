//
// Created by benxn on 02.12.2021.
//
#define MAX 200000
#include "sort.h"
#include <stdlib.h>

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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
    int pi = partition(arr, low, high);

       quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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

void heapsort (int l[], int laenge)
{
    int k;

    for (k = 1; k <= laenge; k++) insert (l[k]);
    for (k = laenge; k >= 1; k--) l[k] = removeheap();
}

