// doing timepass with array
// will mention the topic no worry
// trying to insert elem at any postiton in an array with no fixed size 

// just use vector to be honest than i will use array for concept
// let's see:

#include<iostream>
#include<vector>
using namespace std;

//using vec=vector;   // wrong cannot do this
int main(){
vector<int>a={1,2,3,4,55,6};
//a.insert(3,2);  // cannot do this wrong again lol
a.insert(a.begin()+2,3); //sytnax: v.insert(v.begin() + index value, value to insert);
for(int x:a){
cout<<x<<"\t";
}
cout<<"\n";
return 0;
}
 
// ouput:1       2       3       3       4       55      6


// now using array for this shit:

/*
int main(){

int* a=new int();  // wrong as it will allocate heap memory to just one elemnet
                    // *(a+i) will not work as memeory for only element has been allocate in heap   
                   
int i=0;
int elem;
while(cin>>elem){
*(a+i)=elem;
i++;
cout<<"enter a non number to break";
}

while(true){
cout<<*(a+i);
delete(a+i);
i++;

}

return 0;
}
*/

// change in strategy: now will use fixed size array


int main(){
int size;
cout<<"enter the size of array\n";
cin>>size;
int* a=new int[size];
//delete(a+i);
for(int i=0;i<size;i++){
int elem;
cout<<"enter the elem at "<<i<<"th posiiton\n";
cin>>elem;
a[i]=elem;
}
for(int i=0;i<size;i++){
cout<<a[i]<<"\t";

}
cout<<"\n";
delete [] a;
return 0;
}


// now the problem with the above one was that u can't insert a new elem beacause size if fixed 
// well let me try once to change the size 
// well let me try normal pointer

/*
int main(){
int dummy_elem=0;
int*a=&dummy_elem;
int elem;
int i=0;
cout<<"enter the elem \n";
while(cin>>elem){
*(a+i)=elem;    // ani't happening as (a+i) is not allocated at all lol 
i++;
cout<<"enter a non number to break\n";

}

//cout<<i;    // the value of i is 4(i entered 3elem) we can use it to check the size of array 
             // so size of array is i-1;

for(int j=0;j<i-1;j++){
cout<<*(a+j)<<"\n";
}
return 0;
}
*/

// new way  lol:
// not working
/*
#define MAX_SIZE 100;
int main(){
int dummy_elem=0;
int*a=&dummy_elem;
int elem;
int i=0;
cout<<"enter the elem \n";
while(cin>>elem){
*(a+i)=elem;    // ani't happening as (a+i) is not allocated at all lol
i++;
cout<<"enter a non number to break\n";

}

//cout<<i;    // the value of i is 4(i entered 3elem) we can use it to check the size of array
             // so size of array is i-1;

for(int j=0;j<i-1;j++){
cout<<*(a+j)<<"\n";
}

return 0;
}// not doing lol  /// hehe guess who is back
*/

// trying again
/*
int* temp=nullptr;
int i=0;
void insert(int*& a,int elem){
int* a=&elem;
}
void display(int* temp,int* a){
while(temp!=a){
cout<<*(temp+i);
i++;
}

}
int main(){
int elem;
cout<<"enter a element\n";
cin>>elem;
int* temp=&elem;// idea is that this will point to the first elem while the a will point to new elem that will be added to array
int* a=nullptr;
insert(a,elem);
cout<<"enter a element again\n";
cin>>elem;
insert(a,elem);
display(temp,a);
return 0;
}

// again failed as elem inside insert is an local variable and will not be accessable in other function
*/



// for array u have to use an fixed size thing 
// well i am providing a chatgpt soln for the problem
// modify:
//1. i made insert and display function  and the most imprtant insert_at_position


#include <limits>  // Include this header for numeric_limits
void insert(int&size,int& capacity,int*&array){
    cout << "Enter numbers (enter a non-number to stop):\n";

    int elem;
    while (cin >> elem) {
        if (size == capacity) {
            // Resize the array when it is full
            capacity *= 2; // Double the capacity
            int* new_array = new int[capacity];

            // Copy elements to the new array
            for (int i = 0; i < size; i++) {
                new_array[i] = array[i];
            }

            delete[] array; // Free the old array memory
            array =new_array; // Point to the new array
        }

        array[size] = elem; // Add the new element
        size++;
    }

   // Clear cin and ignore any remaining characters in the input buffer
    cin.clear();  // resets the state of the input stream after an invalid input.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   //clears any leftover input from the buffer to prepare for the next valid input.
// because after displaying printing statement of wanna enter a new lem in main() there is segmation fault because cin is not clear
// becuase we gave a character that's why i guess 


}
void display(int size,int*array){
cout << "\nYou entered:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
cout<<"\n";
}
void insert_new_elem_at_position(int&size,int&capacity,int*&array,int elem,int index){
 
//      if user has just given two value then it can be a prpblem as for this capacity==size which is 2 so we need capacity++ for that
 // Resize the array when it's full
    if (size == capacity) {
        capacity *= 2; // Double the capacity
        int* new_array = new int[capacity];

        // Copy elements to the new array
        for (int i = 0; i < size; i++) {
            new_array[i] = array[i];
        }

        delete[] array; // Free the old array memory
        array = new_array; // Point to the new array
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new element at the specified index
    array[index] = elem;

    // Increment the size of the array
    size++;
}

int main() {
int capacity = 2;       // Initial capacity
    int size = 0;           // Current number of elements
    int* array = new int[capacity]; // Dynamically allocated array
    int new_elem;
    int index,elem;
   // int* new_array=nullptr   // writing here so diplay function can access this 
   // no need as array will point to new_array and we can access array
    insert(size,capacity,array);
    display(size,array);
    
    cout<<"wanna enter a new number ?\t"<<"tell its value and at what position u want it to add\n";
    cin>>elem;
    cin>>index;
    insert_new_elem_at_position(size,capacity,array,elem,index);
    display(size,array);
    delete[] array; // Free the allocated memory
    return 0;
}


/* output:
Enter numbers (enter a non-number to stop):
1
2
a

You entered:
1 2 wanna enter a new number ?  tell its value and at what position u want it to add
99
1

You entered:
1 99 2
*/

// finally completed

