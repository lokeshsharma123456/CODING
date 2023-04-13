#include<bits/stdc++.h>
using namespace std;

#define ll long long int
bool possibleBipartition(int n, vector<vector<int>>& dislikes)
{
	int colour[n + 1];
	for (int i = 0; i <= n ; ++i)
		colour[i] = -1;
	//0:red , 1:blue , -1 : uncolour
	vector<int>notlike[n + 1];
	queue<int>q;
	for (int i = 0; i < dislikes.size() ; ++i)
	{
		int u = dislikes[i][0];
		int v = dislikes[i][1];
		notlike[u].push_back(v);
		notlike[v].push_back(u);
	}
	// for (int i = 1; i < n + 1; ++i)
	// {
	// 	cout << i << " :";
	// 	for (auto val : notlike[i])
	// 		cout << val << " ";
	// 	cout << std::endl;
	// }
	for (int i = 1; i < n + 1; ++i)
	{
		if (notlike[i].size() == 0)//kahin bhi ja sakta hai
			continue;
		else
		{
			q.push(i);
			while (q.size())
			{
				int u = q.front();
				//now explore u;

				for (int j = 0; j < notlike[u].size(); ++j)
				{
					int v = notlike[u][j];
					if (colour[v] == -1)
					{
						colour[v] = colour[u] ^ 1;
						q.push(v);
					}
					else if (colour[u] == colour[v])
						return false;
				}
				q.pop();
			}
		}

	}
// cout << endl;
	return true;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, e;
		cin >> n >> e;

		vector < vector<int>>dislikes;
		for (int i = 0; i < e; ++i)
		{
			int u, v;
			cin >> u >> v;
			vector<int>vec;
			vec.push_back(u);
			vec.push_back(v);
			dislikes.push_back(vec);
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << dislikes[i][0] << " ";
		// 	cout << dislikes[i][1] << endl;

		// }

		cout << (possibleBipartition(n, dislikes) ? "true\n" : "false\n");
	}



	return 0;
}