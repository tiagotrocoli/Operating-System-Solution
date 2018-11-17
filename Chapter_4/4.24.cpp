#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int t_points;
int p_circle;

void *runner(void *ptr){
    
    p_circle = 0;
    
    for(int i=0;i<t_points;i++){
        
        double x = 2*((double)rand()/(double)(RAND_MAX)) - 1;
        double y = 2*((double)rand()/(double)(RAND_MAX)) - 1;
        
        if(sqrt(x*x + y*y) <= 1.0)
            ++p_circle;
    }
    
    pthread_exit(0);
}


int main(){
    
    pthread_t tid;
    
    cin >> t_points;
    
    pthread_create(&tid, NULL, runner, NULL);
    pthread_join(tid, NULL);
    
    cout << "Pi = " << 4.0*(p_circle)/(1.0*t_points) <<endl;
    
    return 0;
}
