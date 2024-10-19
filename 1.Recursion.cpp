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

                                                                                         // solving taylor series using recursion


#include<iostream>
using namespace std;


int pow(int x, int n) {     // Power function using integers for exponentiation
    if (n == 0) {
        return 1;
    }
    else {
        return pow(x, n - 1) * x;
    }
}


int fact(int n) {     // Factorial function using integers
    if (n == 0) {
        return 1;
    }
    else {
        return fact(n - 1) * n;
    }
}


float taylor(int x, int n) {   // Taylor series for e^x approximation
    float sum = 0.0;  // Initialize sum for accumulating terms
    for (int i = 0; i <= n; i++) {
        sum += (float) pow(x, i) / fact(i);  // Accumulate each term in the series
    }
    return sum;  // Return the accumulated value of the Taylor series
}

int main() {
    cout << taylor(1, 2);  // Call Taylor function for e^1 with 2 terms      taylor=summation of n(0 to inf)[power(x,n)/fact(n)]
    return 0;
}  // output 2.5

