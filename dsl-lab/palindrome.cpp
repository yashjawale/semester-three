#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> stack;
    string str;
    cout << "----- Palindrome Checker -----" << endl;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "Entered string is: \n" << str << endl;
    string fstring;

    // PUSHING TO STACK & FSTRING
    for (int i=0; i<str.length(); i++) {
        if (str[i] != ' ') {
            stack.push(str[i]);
            fstring.push_back(str[i]);
        }
    }
    cout << "Reversed String: " << endl;
    int stackSize = stack.size();
    bool isPalindrome = true;

    // PALINDROME CHECK 
    for (int i=0; i<stackSize; i++) {
        cout << stack.top();
        if (fstring[i] != stack.top()) {
            isPalindrome = false;
        }
        stack.pop();
    }
    cout << endl;
    if (isPalindrome) {
        cout << "The string is a Palindrome" << endl;
    } else {
        cout << "The string is not a Palindrome" << endl;
    }
}
