/*You are given n  tasks labeled from 0 to n - 1 represented by
 a 2D integer array tasks, where

 tasks[i] = [enqueueTimei, processingTimei]


  means that the i th  task will be available to process at
   enqueueTimei and will take processingTimeito finish processing.

You have a single-threaded CPU that can process at most one
task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process,
the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will
choose the one with the shortest processing time. If multiple tasks
 have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.



Example 1:

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing
task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing
task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

 tasks[i] = [enqueueTimei, processingTimei]

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int



vector<int> getOrder(vector<vector<int>>& tasks)
{
	vector <int> v;
	//  0:arrivalTime, 1:burstTime, 2:index
	int n = tasks.size();
	for (int i = 0; i < n; ++i)
		tasks[i].push_back(i);
	sort(tasks.begin() , tasks.end());
	int index;
	int arrivalTime;
	int BurstTime;


	// priority_queue < sjf, vector<sjf>, decltype(compare)>pq(compare);
	priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq; // burstTime , index
	int cur_time = 0;
	int i = 0;
	while (i < n || pq.size() )
	{

		if (pq.empty())
		{
			cur_time =  cur_time > tasks[i][0] ? cur_time : tasks[i][0];
		}

		while (i < n && cur_time >= tasks[i][0])
		{
			BurstTime = tasks[i][1];
			index = tasks[i][2];
			pq.push(make_pair(BurstTime , index));
			i++;
		}

		pair<int, int>s = pq.top();
		pq.pop();
		BurstTime = s.first;
		index = s.second;
		cur_time += BurstTime;
		v.push_back(index);

	}

	return v;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int num_tasks;
	cin >> num_tasks;
	vector < vector<int>>tasks;

	for (int i = 0; i < num_tasks; ++i)
	{
		int enq_time , BurstTime;
		cin >> enq_time >> BurstTime;
		vector<int>v;
		v.push_back(enq_time);
		v.push_back(BurstTime);
		tasks.push_back(v);
	}
	vector<int> v = getOrder(tasks);
	for (auto val : v)
		cout << val << " ";


	return 0;
}