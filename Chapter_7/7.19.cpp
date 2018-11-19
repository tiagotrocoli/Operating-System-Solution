#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

class Barrier{
    
    private:
        int number;
        mutex mtx1, mtx2;
    
    public:
    
        void init(int n){
            number = n;    
        }
        
        void barrier_point(){
            
            mtx1.lock();
            --number;
            mtx1.unlock();
            
            while(number != 0)
                sleep(1);

        }
    
};

void task(Barrier *B){
    
    int count = 0;
    
    cout << "Thread executing..." << endl;
    
    while(count != 200)
        ++count;
    
    B->barrier_point();
    
    cout << "Thread exiting..." << endl;
}

int main(){
    
    int n;
    
    cout << "Provide the number of threads :";
    cin >> n;
    
    Barrier *B = new Barrier();
    B->init(n);
    
    thread t1(task, B), t2(task, B);
    
    sleep(1);
    
    thread t3(task, B);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
