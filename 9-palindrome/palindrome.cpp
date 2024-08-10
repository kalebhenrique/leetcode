#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        string temp = s;

        reverse(temp.begin(), temp.end());
        if (s == temp)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int x;

    cin >> x;

    Solution solution;
    cout << solution.isPalindrome(x);

    return 0;
}