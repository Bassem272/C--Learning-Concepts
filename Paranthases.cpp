#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        stack<char> st;
bool ok = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (!st.empty() &&((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')))
            {
                st.pop();
            }
            else
            {
                
                ok = false;
                break;
            }
        }

        if ( ok && st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
