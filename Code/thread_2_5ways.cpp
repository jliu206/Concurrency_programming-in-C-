#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

// //first way function pointer

// void func1(int x){
//     while(x-- > 0){
//         cout<<x<<endl;
//     }
// }



// int main(){
//     thread t1(func1,10);
//     t1.join();
// }

// //second way lambda function (a)

// int main(){
//     auto func1 = [](int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     };
//     //thread t2(func1,10);
//     thread t3([](int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     },10);
//     //t2.join();
//     t3.join();

// }

//third way functor (function object)
// class Base{
// public:
//     void operator ()(int x){
//         while(x-- > 0){
//             cout<<x<<endl;
//         }
//     }
// };

// int main(){
//     thread t1((Base()),10);
//     t1.join();
    
// }

// // 4th way: Non static member function
// class Base{
// public:
//     void func1(int x){
//         while(x-- > 0){
//              cout<<x<<endl;
//         }
//     }
// };

// int main(){

//     Base b;
//     thread t1(&Base::func1,&b,10);
//     t1.join();

// }

// 5th static member function
class Base{
public:
    static void func1(int x){
        while(x-- >0){
            cout<<x<<endl;
        }
    }
};

int main(){
    thread t1(&Base::func1,10);
    t1.join();
}