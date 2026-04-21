#include <iostream>

using namespace std;

void securePointerTest() {
    // create a pointer and store the value 1234
    int* secretKey = new int(1234);
    
    // free the memory
    delete secretKey;    

    // make pointer null
    secretKey = nullptr;

    // when pointer is accessed now it returns nothing
    cout << *secretKey;

}

int main() {
    securePointerTest();
}