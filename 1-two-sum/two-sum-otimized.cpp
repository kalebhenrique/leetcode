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
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement))
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
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