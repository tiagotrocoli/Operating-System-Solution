#include <iostream>
#include <pthread.h>

int n;

using namespace std;

void *runner(void *arr){

  int *vec = (int *) arr;

  int fib1 = 0;
  int fib2 = 1;

  if(n >= 1)
    vec[0] = fib1;

  if(n >= 2)
    vec[1] = fib2;

  for(int i=2;i<n;i++){

    int temp  = fib2;
    fib2      = fib1 + fib2;
    fib1      = temp;

    vec[i] = fib2;
  }

  pthread_exit(0);
}

int main(){

  cin >> n;

  int *arr = (int *)malloc(n*sizeof(int));

  pthread_t tid;

  pthread_create(&tid, NULL, runner, arr);
  pthread_join(tid, NULL);

  for(int i=0;i<n;i++)
    cout << arr[i] << endl;


  return 0;
}
