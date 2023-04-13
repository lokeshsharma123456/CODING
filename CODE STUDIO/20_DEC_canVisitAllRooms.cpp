class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        n = rooms.size();
        int isVisted[n];
        for (int i = 0; i < n; ++i)
        {
            isVisted[i] = 0;
            if (rooms[i].size() == 0)
                isVisted[i] = 1;
        }

        queue<int>q;
        q.push(0);
        while (q.size())
        {
            int f = q.front();
            q.pop();
            if (!isVisted[f])
            {
                isVisted[f] = 1;
                for (auto val : rooms[f])
                {
                    if (isVisted[val])
                        q.push(val);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (isVisted[i] == 0)
                return false;
        }
        for (int i = 0; i < n; ++i)
            cout << isVisted[i] << " ";
        return true;
    }
};