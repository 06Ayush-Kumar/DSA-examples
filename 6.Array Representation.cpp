                                                                                        // array representation

// increasing array size example by creating new array in heap

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int *p=new int [5];   // dynamic array
    int *q=new int[10];   // creating a new larger array to transfer array of p
    for(int i=0;i<5;i++){
        cin>>p[i];      // for demo input is 1,2,3,4,5
    }
    for(int j=0;j<5;j++){
        cout<<p[j];          // output is 1,2,3,4,5
    }
     for(int i=0;i<5;i++){
        q[i]=p[i];            // copying element of p into q
    }
    p=q;       // now by this p pointer will point to q
    q=NULL;    // now q will be null so wont be pointing to anyone
    for(int j=0;j<10;j++){
        cout<<p[j];        // output :1,2,3,4,5,0,0,0,0,0
    }
    delete[] p;         // deleting memory
    delete[] q;
    
    return 0;
}
