#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<vector<int>> v;
// map<string, int>mp;
map<vector<int>, int>mp;
void helper(vector<int>& nums, int index, int prev_val, vector<int>&k)
{
    if (index == nums.size())
    {
        // string  str = "";
        // for (auto a : k)
        //     str += to_string(a);

        if (mp.find(k) == mp.end())
        {
            mp[k]++;
            if (k.size() > 1)
                v.push_back(k);
        }

        return;
    }
    if (nums[index] < prev_val )
    {
        // k.push_back(nums[index]);
        helper(nums, index + 1, prev_val, k);
        return;
    }
    k.push_back(nums[index]);
    //add
    helper(nums, index + 1, nums[index], k);

    // not add
    k.pop_back();
    helper(nums, index + 1, prev_val , k);
}
vector<vector<int>> findSubsequences_rec(vector<int>& nums)
{
    vector<int>k;
    int index = 0;
    helper(nums, index, INT_MIN, k);
    return v;
}

// void helper1(vector<int>& nums, int index, int prev_val, int**arr, vector<int>k)
// {
//     if (index == nums.size())
//     {
//         string  str = "";
//         for (auto a : k)
//             str += to_string(a);

//         if (mp.find(str) == mp.end())
//         {
//             mp[str]++;
//             v.push_back(k);
//         }
//         return;
//     }
// }
// vector<vector<int>> findSubsequences(vector<int>& nums)
// {
//     int n = nums.size();
//     int **arr = new int*[n];
//     for (int i = 0; i < n; ++i)
//     {
//         arr[i] = new int[n + 1];
//         for (int j = 0; j < n + 1; j++)
//             arr[i][j] = -1;
//     }
//     int index = 0;
//     vector<int>k;
//     helper1(nums, index, -1, arr, k);
// }
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int>nums;
    while (n--)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }

    clock_t start, end;

    double time_taken;
    /* Recording the starting clock tick.*/
    start = clock();
    vector<vector<int>> v = findSubsequences_rec(nums);
    end = clock();

    time_taken = double(end - start) ;
    // cout << "Time taken by program is  using recursion: " << fixed
    // << time_taken << setprecision(5);
    // cout << " msec " << endl;

    cout << endl << endl;

    // vector<vector<int>> v = findSubsequences(nums);

    sort(v.begin(), v.end());
    // for (int i = 0; i < v.size(); ++i)
    // {
    //     for (auto val : v[i])
    //         cout << val << " ";
    //     cout << endl;
    // }
    cout << v.size() << endl;

    return 0;
}