
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>

#define MIN_PID 300
#define MAX_PID 5000

using namespace std;

class PID{

  public:
    static PID* instance();
    void allocate_map();
    void release_pid(int);
    void allocate_pid();

  private:
    static PID *singleton;
    vector<int> aloc;
    vector<int> vfree;
    PID(){};
    ~PID(){};
    void inicialize_map();
    int binary_search(int);
};

PID* PID::singleton = NULL;

void PID::allocate_map(){

  for(int i = MIN_PID;i<=MAX_PID;i++)
    vfree.push_back(i);

}

void PID::allocate_pid(){

  int size  = vfree.size();

  if(size == 0)
    printf("There is no free pid to allocate.\n" );
  else{
    aloc.push_back(vfree[size-1]);
    vfree.erase(vfree.begin() + (size-1));
  }

}

PID* PID::instance(){

  if(singleton == NULL){
    singleton = new PID();
  }
  return singleton;
}

void PID::release_pid(int pid){

  sort(aloc.begin(), aloc.end());

  int index = binary_search(pid);

  if(index == -1)
    printf("Pid doesn't exist in the map.\n" );
  else{
    aloc.erase(aloc.begin() + index);
    printf("Pid was erased.\n");
    vfree.push_back(pid);
  }

}

int PID::binary_search(int x){

  int l = 0;
  int r = aloc.size()-1;

  while (l <= r){
        int m = l + (r-l)/2;

        if (aloc[m] == x)
            return m;

        if (aloc[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main(){

    PID *novo = PID::instance();

    novo->allocate_map();
    novo->allocate_pid();

    novo->release_pid(10);
    novo->release_pid(5000);

    novo->allocate_pid();
    novo->allocate_pid();
    novo->allocate_pid();

    novo->release_pid(4999);

    return 0;

}
