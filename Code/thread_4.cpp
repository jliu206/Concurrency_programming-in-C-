//mutex(mutal exclusion) in c++ Threading

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
using namespace std::chrono;

int myAmount = 0;
std::mutex m;

void addone(){
    //m.lock();
    this_thread::sleep_for(chrono::seconds(2));
    myAmount++;
    myAmount++;
    myAmount++;
    //m.unlock();
}

int main(){
    thread t1(addone);
    thread t2(addone);

    t1.join();
    t2.join();

    cout<<myAmount<<endl;

    return 0;
}