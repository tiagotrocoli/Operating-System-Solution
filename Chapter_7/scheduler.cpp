#include <iostream>
#include <vector> 

using namespace std;

class Task{
    
    private:
        string name;
        int priority;
        int burst;
    
    public:
        
        Task(const string&name, int priority, int burst){
            
            this->name       = name;
            this->priority   = priority;
            this->burst      = burst;
        }
    
        const string& getName(){
            return name;
        }
        
        int getPriority(){
            return priority;
        }
        
        int getBurst(){
            return burst;
        }
        
};       

class ListOfTask{
    
    private:
        vector<Task*> vc;
    
    public:
        ListOfTask(){}
        
        void addTask(const string &name, int priority, int burst){
            vc.push_back(new Task(name, priority, burst));
        }
        
        void listQueue(){
            
            for(int i=0;i<vc.size();i++){
                cout << vc[i]->getName() << " " << vc[i]->getPriority() << " " << vc[i]->getBurst() << endl;
            }
                
        }
};

int main(){
    
    ListOfTask *T = new ListOfTask();
    
    for(int i=0;i<10;i++)
        T->addTask("Nada", i, 10+i);
    
    T->listQueue();
    
    return 0;
}
