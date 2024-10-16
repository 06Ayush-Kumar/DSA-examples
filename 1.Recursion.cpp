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

int main() {
	// your code goes here
cout<<	factorial(5)<<"\n"<<summation(5);   // output :120 and  15

}
