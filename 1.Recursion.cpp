                                                                             // examples of recursion by me

                                                                           // basic recursion
 
#include <bits/stdc++.h>
using namespace std;
int factorial(int a){
    if(a>0){
        return a*factorial(a-1);
    }
    return 1;
}
int summation(int a){
    if(a>0){
        return a+summation(a-1);     
    }
    return 0;
    
}
void fun1(int a){
    if(a>0){
    cout<<a;
    fun1(a-1);  // this is called tail recursion because after function there is nothing to execute  , fun1(a-1)+a will not be tail as +a is after function call which will execute
    }
}
void fun2(int a){
    if(a>0){
    fun2(a-1);    // this is called head recursion because function calling is at top
     cout<<a;
    
    }
}

int main() {
	
cout<<	factorial(5)<<"\n"<<summation(5)<<"\n";  // output :120 and  15
fun1(5);   //output :54321
cout<<"\n";
fun2(5);   // output : 12345

}
