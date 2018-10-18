#include <iostream>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int *arr;
int *vec;


struct VALUES{
    int low;
    int high;
};

typedef struct VALUES values;

// A utility function to swap two elements
void swap(int* a, int* b){

    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int low, int high) {

    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */

void quickSort(int low, int high) {

    if (low < high){
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void *sort(void *var) {

    int low  = ((values *) var)->low;
    int high = ((values *) var)->high;

    quickSort(low, high);
}

void generate_arr(int n){

    srand (time(NULL));

    arr = (int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        arr[i] = rand()%100 + 1;

}

void print(int *v, int n){

    for(int i = 0;i<n;i++)
        cout << v[i] << " ";
}

void *merge(void *var){

    int n = *((int *) var);
    int i = 0;
    int j = n/2;

    vec = (int*)malloc(n*sizeof(int));

    for(int k=0;k<n;k++){

        if(arr[i] > arr[j]){

            vec[k]  = arr[j];
            j       = j + 1;

        }else{
            vec[k]  = arr[i];

            if(i + 1 < n/2)
              i = i + 1;
        }
    }

}

int main(){

    int n;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;

    cin >> n;

    values var1;
    values var2;

    var1.low  = 0;
    var1.high = n/2-1;

    var2.low  = n/2;
    var2.high = n-1;

    generate_arr(n);

    pthread_create(&tid1, NULL, sort, &var1);
    pthread_create(&tid2, NULL, sort, &var2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, NULL, merge, &n);

    merge(&n);

    pthread_join(tid3, NULL);

    print(vec, n);

    return 0;
}
