#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string pop_one(string);

class Solution
{
public:
    int romanToInt(string s)
    {
        reverse(s.begin(), s.end());
        int n = s.length();
        int soma = 0;
        string temp = "";
        map<string, int> dic;

        while (s != "")
        {
            temp += s[0];

            if ((s[0] == 'I' && n == 1) || (s[0] == 'I' && s[1] != 'I' && temp[1] != 'I') || (s[0] == 'I' && s[1] != 'I' && temp[0] != 'I' && temp[0] != 'V' && temp[0] != 'X'))
            {
                dic["I"] += 1;
                temp = "";
            }
            else if ((s[0] == 'V' && n == 1) || (s[0] == 'V' && s[1] != 'I'))
            {
                dic["V"] += 5;
                temp = "";
            }
            else if ((s[0] == 'X' && n == 1) || (s[0] == 'X' && s[1] != 'I' && temp[0] != 'L' && temp[0] != 'C') || (s[0] == 'X' && s[1] == 'X'))
            {
                dic["X"] += 10;
                temp = "";
            }
            else if ((s[0] == 'L' && n == 1) || (s[0] == 'L' && s[1] != 'X'))
            {
                dic["L"] += 50;
                temp = "";
            }
            else if ((s[0] == 'C' && n == 1) || (s[0] == 'C' && s[1] != 'X' && temp[0] != 'D' && temp[0] != 'M') || (s[0] == 'C' && s[1] == 'C'))
            {
                dic["C"] += 100;
                temp = "";
            }
            else if ((s[0] == 'D' && n == 1) || (s[0] == 'D' && s[1] != 'C'))
            {
                dic["D"] += 500;
                temp = "";
            }
            else if ((s[0] == 'M' && n == 1) || (s[0] == 'M' && s[1] != 'C'))
            {
                dic["M"] += 1000;
                temp = "";
            }

            if (temp == "III")
            {
                s = pop_one(s);
                dic["III"] = 3;
                temp = "";
            }
            else if (temp == "II")
            {
                s = pop_one(s);
                dic["II"] = 2;
                temp = "";
            }
            else if (temp == "VI")
            {
                s = pop_one(s);
                dic["IV"] = 4;
                temp = "";
            }
            else if (temp == "XI")
            {
                s = pop_one(s);
                dic["IX"] = 9;
                temp = "";
            }
            else if (temp == "LX")
            {
                s = pop_one(s);
                dic["XL"] = 40;
                temp = "";
            }
            else if (temp == "CX")
            {
                s = pop_one(s);
                dic["XC"] = 90;
                temp = "";
            }
            else if (temp == "DC")
            {
                s = pop_one(s);
                dic["CD"] = 400;
                temp = "";
            }
            else if (temp == "MC")
            {
                s = pop_one(s);
                dic["CM"] = 900;
                temp = "";
            }
            else
            {
                s = pop_one(s);
            }
        }

        map<string, int>::iterator it;
        for (it = dic.begin(); it != dic.end(); ++it)
        {
            soma += it->second;
        }

        return soma;
    }
};

int main()
{
    string s;

    cin >> s;

    s = pop_one(s);
    s.pop_back();

    Solution solution;
    cout << solution.romanToInt(s);

    return 0;
}

string pop_one(string s)
{
    string result = "";

    for (int i = 1; i <= s.length() - 1; i++)
    {
        result = result + s[i];
    }

    if (!s.empty())
    {
        return result;
    }

    return "";
}