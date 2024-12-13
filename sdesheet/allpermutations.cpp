#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds); // pushing every permutation from ds to ans one by one
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i]) // if it is not 1/not marked then only we will consider it adding to our datastructure(ds)
            {
                ds.push_back(nums[i]);
                freq[i] = 1; // marking the position in freq/map as it is now pushed in the ds
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;   // removing the mark
                ds.pop_back(); // removing the element that was last added
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()]; // map
        for (int i = 0; i < nums.size(); i++)
        {
            freq[i] = 0; // marking all initially as 0
        }
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> sum = obj.permute(v);
    cout << "All permutations are" << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}