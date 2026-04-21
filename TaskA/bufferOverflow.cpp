#include <iostream>
#include <cstring>

using namespace std;

// temp = a stored integer that the buffer overflow will leak into causing the value to change
// type a string longer than 8 letters to cause buffer overflow

// check users password when they log in
void login() {
    int temp = 1;
    char password[8];
    
    cout << "Enter password: ";
    cin >> password; 

    // check if temp has changed (buffer overflow occured)
    if (temp != 1) {
        cout << "buffer overflow occured" << endl;
        cout << "current temp value is: " << temp;
    }
    // password correct
    else if (strcmp(password, "password") == 0) {
        cout << "Password Correct";
    }
    // password incorrect
    else {
        cout << "Password Incorrect";
    }
}

int main() {
    login();
}