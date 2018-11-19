#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Task{

    private:
        string name;
        int priority;
        int burst;

    public:

        Task(const string &name, int priority, int burst){

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

        void showTask(){
            cout << name << " " << priority << " " << burst << endl;
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

            for(unsigned long i=0;i<vc.size();i++){
                cout << vc[i]->getName() << " " << vc[i]->getPriority() << " " << vc[i]->getBurst() << endl;
            }
        }

        bool removeTask(unsigned long id){

            if(id >= vc.size())
                return false;

            vc.erase(vc.begin()+id);

            return true;
        }

        bool acessTask(unsigned long id){

            if(id >= vc.size())
                return false;

            vc[id]->showTask();

            return true;
        }

        bool isEmpty(){
            return vc.empty();
        }

        unsigned long getShortestBurst(){

            unsigned long id = 0;

            for(unsigned long i = 0;i<vc.size();i++){

                if(vc[id]->getBurst() > vc[i]->getBurst())
                    id = i;

            }

            return id;
        }

        unsigned long getShortestPriority(){

            unsigned long id = 0;

            for(unsigned long i = 0;i<vc.size();i++){

                if(vc[id]->getPriority() > vc[i]->getPriority())
                    id = i;

            }

            return id;
        }
};

// Generic Scheduler Class
class Scheduler{
    public:
        virtual void execute(ListOfTask *) = 0;

};

// Fist Come, First Served Scheduler
class FCFS : public Scheduler{
    public:

        void execute(ListOfTask *L){

            unsigned long i = 0;

            while(!L->isEmpty()){

                cout << "Executing: ";
                L->acessTask(i);
                L->removeTask(i);

            }

        }
};

//
class SJF : public Scheduler{
    public:

    void execute(ListOfTask *L){

        while(!L->isEmpty()){

            unsigned long id = L->getShortestBurst();

            cout << "Executing: ";
            L->acessTask(id);
            L->removeTask(id);

        }

    }

};

// Priority First Scheduler
class PF : public Scheduler{
    public:

    void execute(ListOfTask *L){

        while(!L->isEmpty()){

            unsigned long id = L->getShortestPriority();

            cout << "Executing: ";
            L->acessTask(id);
            L->removeTask(id);

        }

    }
};

int main(){

    ListOfTask *T = new ListOfTask();

    for(int i=0;i<10;i++){
        string str = "T" + to_string(i);
        T->addTask(str, rand()%10, rand()%50);
    }

    T->listQueue();

    Scheduler *S = new PF();

    S->execute(T);

    return 0;
}
