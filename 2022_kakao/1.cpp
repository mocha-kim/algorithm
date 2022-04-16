#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct user_log
{
	int id = -1;
	vector<string> reported_user;
	int reported_count = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
	map<string, struct user_log> users;
    
    for (int i = 0; i < id_list.size(); i++)
    {
		struct user_log log;
		log.id = i;
        users[id_list[i]] = log;
		answer.push_back(0);
    }

	report.erase(unique(report.begin(), report.end()), report.end());
    
	for (int i = 0; i < report.size(); i++)
	{
        cout << report[i] << "\n";
		string reporter = report[i].substr(0, report[i].find(' '));
		string reported = report[i].substr(report[i].find(' ') + 1);
		users[reported].reported_user.push_back(reporter);
		users[reported].reported_count++;
	}
	
	for (int i = 0; i < id_list.size(); i++)
	{
		struct user_log log = users[id_list[i]];
        cout << log.id << ": " << log.reported_count << "\n";
		if (log.reported_count >= k)
		{
			for (int j = 0; j < log.reported_user.size(); j++)
			{
                cout << ">> " <<log.reported_user[j] << ": " << users[log.reported_user[j]].id << "\n";
                if (users[log.reported_user[j]].id == -1)
                    continue;
				answer[users[log.reported_user[j]].id]++;
			}
		}
	}

    return answer;
}