#include <iostream>
#include "stack1.h"
#include <math.h>
using namespace std;

int prefix_evaluation()
{
    string str;
    cout << "Enter Prefix Expretion : ";
    cin >> str;
    stack st(str.length());
    // for (str-len)-1 to 0 ( reverse the string )
    for (int i = (str.length() - 1); i >= 0; i--)
    {
        // if string character is digit then push in the stack
        if (isalnum(str[i]))
        {
            st.push(str[i] - '0');
        }
        else
        {
            // if string character isn't digit then it must be opreter
            // first poped oprand is opt1 and second oprant is opt2
            int opt1 = st.gettop();
            st.pop();
            int opt2 = st.gettop();
            st.pop();
            // preform the opration besded on opreter
            if (str[i] == '+')
            {
                st.push(opt1 + opt2);
            }
            else if (str[i] == '-')
            {
                st.push(opt1 - opt2);
            }
            else if (str[i] == '*')
            {
                st.push(opt1 * opt2);
            }
            else if (str[i] == '/')
            {
                st.push(opt1 / opt2);
            }
            else if (str[i] == '^' || str[i] == '$')
            {
                int result = pow(opt1, opt2);
                st.push(result);
            }
            else if (str[i] == '%')
            {
                st.push(opt1 % opt2);
            }
        }
    }

    // return top of the stack
    return st.gettop();
}

int postfix_evaluation()
{
    string str;
    cout << "Enter Postfix Expretion : ";
    cin >> str;
    stack st(str.length());
    for (int i = 0; i < str.length(); i++)
    {
        // if string character is digit then push in the stack
        if (isalnum(str[i]))
        {
            st.push(str[i] - '0');
        }
        else
        {
            // if string character isn't digit then it must be opreter
            // first poped oprand is opt2 and second oprant is opt1
            int opt2 = st.gettop();
            st.pop();
            int opt1 = st.gettop();
            st.pop();
            // preform the opration besded on opreter
            if (str[i] == '+')
            {
                st.push(opt1 + opt2);
            }
            else if (str[i] == '-')
            {
                st.push(opt1 - opt2);
            }
            else if (str[i] == '*')
            {
                st.push(opt1 * opt2);
            }
            else if (str[i] == '/')
            {
                st.push(opt1 / opt2);
            }
            else if (str[i] == '^' || str[i] == '$')
            {
                int result = pow(opt1, opt2);
                st.push(result);
            }
            else if (str[i] == '%')
            {
                st.push(opt1 % opt2);
            }
        }
    }
    // return top of the stack
    return st.gettop();
}

int precedence(char element)
{

    if (element == '^' || element == '$')
    {
        return 4;
    }
    else if (element == '*' || element == '/')
    {
        return 3;
    }
    else if (element == '+' || element == '-')
    {
        return 2;
    }
    else if (element == '(')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostfix(string str)
{
    stack st(str.length());
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        char element = str[i];
        if (element == ' ')
        {
            continue;
        }
        else if (isalnum(element))
        {
            result += element;
        }
        else if (element == '(')
        {
            st.push(element);
        }
        else if (element == ')')
        {
            element = st.pop();
            while (element != '(')
            {
                result += element;
                element = st.pop();
            }
        }
        else
        {
            while ((!st.isEmpty()) && (precedence(st.gettop()) >= precedence(element)))
            {
                result += st.pop();
            }
            st.push(element);
        }
    }

    while (!st.isEmpty())
    {
        result += st.pop();
    }

    cout <<"Postfix Expretion : "<<result << endl;
}

void infixToPrefix(string str)
{
    stack st(str.length());
    string result;
    for (int i = (str.length() - 1); i >= 0; i--)
    {
        char element = str[i];
        if (element == ' ')
        {
            continue;
        }
        else if (isalnum(element))
        {
            result += element;
        }
        else if (element == '(')
        {
            element = st.pop();
            while (element != ')')
            {
                result += element;
                element = st.pop();
            }
        }
        else if (element == ')')
        {
            st.push(element);
        }
        else
        {

            while ((!st.isEmpty()) && (precedence(st.gettop()) > precedence(element)))
            {
                result += st.pop();
            }
            st.push(element);
        }
    }

    while (!st.isEmpty())
    {
        result += st.pop();
    }
    
    cout<<"Prefix Expretion : " ;
    for (int i = (result.length() - 1); i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    int ch;
    string str;
    do
    {
        cout << "1. Infix to Prefix \n2. Infix to Postfix \n3. Prefix Evaluation \n4. Postfix Evaluation \n5. Exit";
        cout << "\nEnter your choise : ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter infix Expression : ";
            cin >> str;
            infixToPrefix(str);
        }
        else if (ch == 2)
        {
            cout << "Enter infix Expression : ";
            cin >> str;
            infixToPostfix(str);
        }
        if (ch == 3)
        {
            cout <<"Prefix result : "<< prefix_evaluation() << endl;
        }
        else if (ch == 4)
        {
            cout <<"Postfix result : "<< postfix_evaluation() << endl;
        }
    } while (ch != 5);

    // INFIX EXPRETION ->
    // string str="a+(b*c-(d/e^f)*g)*h" ;
    // string str="4$2*3-3+8/4/(1+1)" ;
    // string str="a+b*c" ;

    return 0;
}

/*
OUTPUT ->

1. Infix to Prefix 
2. Infix to Postfix 
3. Prefix Evaluation 
4. Postfix Evaluation 
5. Exit
Enter your choise : 1
Enter infix Expression : 4$2*3-3+8/4/(1+1)
Prefix Expretion : +-*$4233//84+11
1. Infix to Prefix
2. Infix to Postfix
3. Prefix Evaluation
4. Postfix Evaluation
5. Exit
Enter your choise : 2
Enter infix Expression : 4$2*3-3+8/4/(1+1)
Postfix Expretion : 42$3*3-84/11+/+
1. Infix to Prefix
2. Infix to Postfix
3. Prefix Evaluation
4. Postfix Evaluation
5. Exit
Enter your choise : 3
Enter Prefix Expretion : +-*$4233//84+11
Prefix result : 46
1. Infix to Prefix
2. Infix to Postfix
3. Prefix Evaluation
4. Postfix Evaluation
5. Exit
Enter your choise : 4
Enter Postfix Expretion : 42$3*3-84/11+/+
Postfix result : 46
1. Infix to Prefix
2. Infix to Postfix
3. Prefix Evaluation
4. Postfix Evaluation
5. Exit
Enter your choise : 5

*/

