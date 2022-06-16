#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct user_log
{
	int id = -1;
	vector<string> reported_user;
	int reported_count = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
	map<string, struct user_log> users;
    
    for (int i = 0; i < id_list.size(); i++)
    {
		struct user_log log;
		log.id = i;
        users[id_list[i]] = log;
		answer.push_back(0);
    }

    sort(report.begin(), report.end());
	report.erase(unique(report.begin(), report.end()), report.end());
    
	for (int i = 0; i < report.size(); i++)
	{
		string reporter = report[i].substr(0, report[i].find(' '));
		string reported = report[i].substr(report[i].find(' ') + 1);
		users[reported].reported_user.push_back(reporter);
		users[reported].reported_count++;
	}
	
	for (int i = 0; i < id_list.size(); i++)
	{
		struct user_log log = users[id_list[i]];
		if (log.reported_count >= k)
		{
			for (int j = 0; j < log.reported_user.size(); j++)
			{
                if (users[log.reported_user[j]].id == -1)
                    continue;
				answer[users[log.reported_user[j]].id]++;
			}
		}
	}

    return answer;
}