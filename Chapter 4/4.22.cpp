#include <iostream>
#include <pthread.h>

using namespace std;

int avg, mini, maxi;

void *getAVG(void *vec){

  int *arr    = (int *) vec;
  int sum  = 0;
  int i = 0;

  while(arr[i] != -1){
    sum = sum + arr[i];
    ++i;
  }

  avg = sum/(i);

  pthread_exit(0);
}

void *getMIN(void *vec){

  int *arr  = (int *) vec;
  int i     = 0;
  mini      = arr[0];


  while(arr[i]!=-1){
    if(arr[i] < mini)
      mini = arr[i];
    ++i;
  }

  pthread_exit(0);
}

void *getMAX(void *vec){

  int *arr  = (int *) vec;
  int i     = 0;
  maxi      = arr[0];

  while(arr[i]!=-1){
    if(arr[i] > maxi)
      maxi = arr[i];
    ++i;
  }

  pthread_exit(0);
}


int main(){

  int n;
  int *vec = NULL;
  pthread_t workers[3];

  cin >> n;

  vec = (int *)malloc((n+1)*sizeof(int));

  for(int i=0;i<n;i++)
    cin >> vec[i];

  vec[n] = -1;

  pthread_create(&workers[0], NULL, getAVG, vec);
  pthread_create(&workers[1], NULL, getMIN, vec);
  pthread_create(&workers[2], NULL, getMAX, vec);

  pthread_join(workers[0], NULL);
  pthread_join(workers[1], NULL);
  pthread_join(workers[2], NULL);

  cout << "Average = " << avg << endl;
  cout << "Min = " << mini << endl;
  cout << "Max = " << maxi << endl;

  return 0;
}
