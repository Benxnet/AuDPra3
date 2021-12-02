#include <stdio.h>
#include <time.h>
#include "sort.h"
#include <stdlib.h>
#define MAX 200000

int bool = 1;
int listran[MAX];


void randarray (int a[]){
    if(bool){
        for (int i = 0; i < MAX; ++i) {
            listran[i] = rand();
        }
        bool--;
    }
    for (int i = 0; i < MAX; ++i) {
        a[i] = listran[i];
    }


}
void maxmin (int a[]){
    int j = MAX;
    for (int i = 0; i<MAX ; ++i) {
        a[i] = j;
        j--;
    }
}
void minmax (int a[]){
    for (int i = 0; i < MAX; ++i) {
        a[i] = i+1;
    }
}


void ausgaben(long time[]){
    char verfahren[6][11]={{"Selection\0"},
                           {"Insertion\0"},
                           {"Shellsort\0"},
                           {"Quicksort\0"},
                           {"Mergesort\0"},
                           {"Heapsort \0"}};
    char array[3][8]={{"Random\0"},
                      {"MinMax\0"},
                      {"MaxMin\0"}};

    printf("|Verfahren| List |Zeit1|Zeit2|Zeit3|Schnitt|\n");
    for (int i = 0; i < 18; ++i) {
        printf("|%s|%s|%10ld|%10ld|%10ld|%10ld  |\n",verfahren[i/3],array[i%3],time[4*i],time[4*i+1],time[4*i+2],time[4*i+3]);
    }
}

void sort() {
    int pos = 0;
    int list[MAX];
    long time[74];
    clock_t start_t, ende_t;
    srand(0);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j%3 == 0) {randarray(list);}
                if(j%3 == 1) {minmax(list);}
                if(j%3 == 2) {maxmin(list);}
                if(i==0){start_t = clock();/*selection(list,MAX);*/ende_t = clock();}
                if(i==1){start_t = clock();/*insertion(list,MAX);*/ende_t = clock();}
                if(i==2){start_t = clock();shellsort(list,MAX);ende_t = clock();}
                if(i==3){start_t = clock();/*quicksort(list,0,1);*/ende_t = clock();}
                if(i==4){start_t = clock();mergesort(list,0,MAX);ende_t = clock();}
                if(i==5){start_t = clock();heapsort(list,MAX);ende_t = clock();}
                time[pos] =((long)(ende_t-start_t));
                pos++;
            }
            time[pos] = (time[pos] + time[pos] + time[pos]) / 3;
            pos++;
        }
    }
    ausgaben(time);
}




int main() {
    //sort();
    int list[MAX];
    long time[74];
    clock_t start_t, ende_t;
    srand(0);
    int new = 0;
    //Selection
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        selection(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    //insertion
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        insertion(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        insertion(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        insertion(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    //shellsort
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        shellsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        shellsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        shellsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    //quicksort
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        quicksort(list,0,MAX-1);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    new++;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        //quicksort(list,0,MAX-1);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        //quicksort(list,0,MAX-1);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    //mergesort
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        mergesort(list,0,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        mergesort(list,0,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        mergesort(list,0,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    //heapsort
    for (int i = 0; i < 3 ; ++i) {
        randarray(list);
        start_t=clock();
        heapsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        minmax(list);
        start_t=clock();
        heapsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    for (int i = 0; i < 3 ; ++i) {
        maxmin(list);
        start_t=clock();
        heapsort(list,MAX);
        ende_t=clock();
        time[i+4*new]=((long)(ende_t-start_t));
    }
    new++;
    time[new*4-1]=(time[new*4-2]+time[new*4-3]+time[new*4-4])/3;
    ausgaben(time);
    return 0;
}
