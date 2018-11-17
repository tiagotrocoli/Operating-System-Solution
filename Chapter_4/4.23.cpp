#include <iostream>
#include <pthread.h>
#include <math.h>

using namespace std;

int *prime;
int size = 0;

bool isPrime(int num){

  int limit = sqrt(num) + 1;

  for(int i=2;i<limit;i++){
    if(num % i == 0)
      return false;
  }

  return true;
}

void *runner(void *m){

  int n = *((int *) m);

  for(int i=2;i<=n;i++){
    if(isPrime(i))
      prime[size++] = i;
  }

  pthread_exit(0);
}

int main(){

  int n;
  pthread_t tid;

  cin >> n;

  prime = (int*)malloc((n/2)*sizeof(int));

  pthread_create(&tid, NULL, runner, &n);
  pthread_join(tid, NULL);

  for(int i=0;i<size;i++)
    cout << prime[i] << " ";

  cout << endl;

  return 0;
}
