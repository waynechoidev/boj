#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string str;
        getline(cin, str);

        stack<char> stk;

        if (str == ".")
            break;

        bool balance = true;

        for (char c : str)
        {
            if (c == '(' || c == '[')
                stk.push(c);
            if (c == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    balance = false;
                    break;
                }
                stk.pop();
            }
            if (c == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    balance = false;
                    break;
                }
                stk.pop();
            }
        }

        if (!stk.empty())
            balance = false;

        if (balance)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}