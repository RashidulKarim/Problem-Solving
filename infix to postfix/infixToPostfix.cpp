#include<bits/stdc++.h>

using namespace std;

int checkPrecedence(char x)
{
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> op;
    string postfix = "";

    for(int i = 0; i < infix.size(); i++)
    {
        char topValue = infix[i];
        if(isdigit(topValue))
            postfix += topValue;
        else
        {
            if(topValue  == '(')
            {
                op.push(topValue);
            }
            else if(topValue == ')')
            {
                while(op.top() != '(')
                {
                    postfix += op.top();
                    op.pop();
                }
                op.pop();
            }
            else
            {
                while(op.size() != 0 && checkPrecedence(op.top()) >= checkPrecedence(topValue))
                {
                    postfix += op.top();
                    op.pop();
                }
                op.push(topValue);
            }
        }
    }

    while(op.size() != 0)
    {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;
    for(int i = 0; i < postfix.size(); i++)
    {
        char val = postfix[i];
        if(isdigit(val))
            st.push(val - '0');
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch(val)
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string infix;
    cin>>infix;
    string postfix = infixToPostfix(infix);
    int result = evaluatePostfix(postfix);
    cout<<result;
    return 0;
}
