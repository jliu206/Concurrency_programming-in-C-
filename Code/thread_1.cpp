#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
ull even_num = 0, odd_num = 0;
void find_even(ull start, ull end){
    for(ull i = start; i <= end; i++){
        if(i % 2 == 0){
            even_num++;
        }
    }
}

void find_odd(ull start, ull end){

    for(ull i = start; i <= end; i++){
        if(i % 2 == 1){
            odd_num++;
        }
    }

}


int main(){
    auto start_time = high_resolution_clock::now();
    find_even(0,1900000000);
    find_odd(0,1900000000);
    // std::thread t1(find_even,0,1900000000);
    // std::thread t2(find_odd,0,1900000000);

    // t1.join();
    // t2.join();
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout<<even_num<<endl<<odd_num<<endl;
    cout<<duration.count()/1000000<<endl;

}