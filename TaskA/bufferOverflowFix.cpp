#include <iostream>
using namespace std;

// temp = a stored integer that the buffer overflow will leak into causing the value to change
// type a string longer than 8 letters to cause buffer overflow

// check users password when they log in
void secureLogin() {
    int temp = 1;
    string password;
    
    cout << "Enter password: ";
    cin >> password; 

    // check if temp has changed (buffer overflow occured)
    if (temp != 1) {
        cout << "buffer overflow occured\n";
        cout << "current temp value is: " << temp;
    }
    // password correct
    else if (password == "password") {
        cout << "Password Correct";
    }
    // password incorrect
    else {
        cout << "Password Incorrect";
    }
}

int main() {
    secureLogin();
}