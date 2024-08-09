#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    };
};

int main()
{
    vector<int> nums;
    int target;
    string line;

    getline(cin, line);

    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }

    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    return 0;
};