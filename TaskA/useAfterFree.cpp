#include <iostream>
using namespace std;

void pointerTest() {
    // create a pointer and store the value 1234
    int* secretKey = new int(1234); 

    // free the memory
    delete secretKey;

    // try to access the pointer after its deleted and seeing data from a different location
    cout << *secretKey << endl; 
}

int main() {
    pointerTest();
}