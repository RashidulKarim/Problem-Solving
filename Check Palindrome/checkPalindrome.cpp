#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(string str)
{
    deque<char> dq;

    for(int i =0; i< str.size(); i++)
        dq.push_back(str[i]);

    while(dq.size() > 1)
    {
        if(dq.back() != dq.front())
            return false;

        dq.pop_back();
        dq.pop_front();
    }
    return true;
}

int main()
{
    string str;
    cin>>str;
    if(checkPalindrome(str))
        cout<<str<<" is a palindrome\n";
    else
        cout<<str<<" is not a palindrome\n";

    return 0;
}
