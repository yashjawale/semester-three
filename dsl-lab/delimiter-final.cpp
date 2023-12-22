#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main ()
{
    stack <char> stack;
    string equation;
    char ch;
    int i = 0;

    cout << "Enter a Equation : ";
    cin >> equation;

    cout << "\nEntered Equation is : " << equation << endl;

    if (equation[0] == '}' || equation[0] == ']' || equation[0] == ')')
    {   
        cout << "Incorrect Equation" << endl;
        stack.push(')');
    }
    else
    {
        while (i < equation.length())
        {

            ch = equation[i];

            switch (ch)
            {
            case '(':stack.push('(');break;

            case '[':stack.push('[');break;

            case '{':stack.push('{');break;

            case ')':stack.pop();break;

            case ']':stack.pop();break;
            
            case '}':stack.pop();break;
            }

            i++;
        }
    }

    if (stack.empty())
    {
        cout << "Equation is Balanced" << endl;
    }
    else
    {
        cout << "Equation is Unbalanced" << endl;
    }

    return 0;

}