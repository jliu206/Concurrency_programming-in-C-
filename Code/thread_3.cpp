#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;
//For join
// void pause_thread(int n) 
// {
//   std::this_thread::sleep_for (std::chrono::seconds(n));
//   std::cout << "pause of " << n << " seconds ended\n";
// }
// //for join: when create the thread, it will execute but wont return anything until use join() 
// //also after join the thread will no longer exist, so that means we can not join a thread more than once
// //what we should do is before join a thread, we should try if the thread is joinable like:
// // if (t1.joinable())
// //      t1.join();
// int main() 
// {
//   std::cout << "Spawning 3 threads...\n";
//   std::thread t1 (pause_thread,1);
//   std::thread t2 (pause_thread,2);
//   std::thread t3 (pause_thread,3);
//   std::cout << "Done spawning threads. Now waiting for them to join:\n";
//   t1.join();
//   t2.join();
//   t3.join();
//   std::cout << "All threads joined!\n";

//   return 0;
// }


//For detach
//The main thread will not wait for thread t1 to finish, instead it continue running the rest of the main thread;
//So deteach is to detach a newly created thread from the main one, if main finish running and returned, and the t1 
//is not finish yet, t1 wont have any output, and will be suspended.
//but if you make the main thread to sleep for enough time, then it will wait for the t1 thread to finish and get all outputs.
void run(int x){
    while(x-- > 0)
        cout << x << "hello" <<endl;
    
    cout<<"thread finished"<<endl;
    //
    //this_thread::sleep_for(chrono::seconds(5)); 
}

int main(){
    thread t1(run,5);
    cout<<"main running"<<endl;
    t1.detach();
    cout<<"main running2"<<endl;
    this_thread::sleep_for(chrono::seconds(5)); 
    return 0;
}