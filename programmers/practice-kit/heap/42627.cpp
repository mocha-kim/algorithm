#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct s_job
{
	int index;
	int start_time;
	int required_time;

	s_job(int i, int s, int r)
	: index(i), start_time(s), required_time(r) {}
} t_job;

struct compare_required
{
	bool operator()(t_job j1, t_job j2)
	{ return j1.required_time > j2.required_time; }
};

struct compare_start
{
	bool operator()(t_job j1, t_job j2)
	{ return j1.start_time > j2.start_time; }
};

int solution(vector<vector<int>> jobs)
{
	int size = jobs.size();
	priority_queue<t_job, vector<t_job>, compare_start> wait;
	priority_queue<t_job, vector<t_job>, compare_required> queued;
	for (int i = 0; i < size; i++)
	{
		t_job job(i, jobs[i][0], jobs[i][1]);
		wait.push(job);
	}
	int elapsed_time = 0, sum = 0;
	while (!(wait.empty() && queued.empty()))
	{
		if (!wait.empty() && wait.top().start_time <= elapsed_time)
		{
			queued.push(wait.top());
			wait.pop();
		}
		else
		{
			if (!queued.empty())
			{
				elapsed_time += queued.top().required_time;
				sum += elapsed_time - queued.top().start_time;
				queued.pop();
			}
			else
				elapsed_time = wait.top().start_time;
		}
	}
	return sum / size;
}