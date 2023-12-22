#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<char> stack;
    string str;
    cout << "Enter expression: ";
    cin >> str;
    cout << "Entered expression: " <<endl << str << endl;

    // PUSHING LEFT BRACKETS
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(' || i == '{' || i == '[') {
            stack.push(str[i]);
        }
    }
    // CHECKING RIGHT BRACKETS
    int stacklength = stack.size();
    cout << "SLEN: " << stacklength << endl;
    for (int i=0; i<str.length(); i++) {
        if (stacklength > 0) {
            if (str[i] == ')' && stack.top() == '(') {
                stack.pop();
                cout << "LEN: " << stacklength << endl;
            } else if (str[i] == '}' && stack.top() == '{') {
                stack.pop();
                --stacklength;
            } else if (str[i] == ']' && stack.top() == '[') {
                stack.pop();
                --stacklength;
            }
        } else {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                stacklength--;
            }
        }
    }
    cout << "STACKLENGTH: " << stacklength;
    return 0;
}
