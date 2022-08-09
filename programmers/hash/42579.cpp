#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare1(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

bool compare2(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    int size = genres.size();
    unordered_map<string, int> tmp;
    unordered_map<string, vector<pair<int, int> > > songs;
    for (int i = 0; i < size; i++)
    {
        tmp[genres[i]] += plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int> > genre_count(tmp.begin(), tmp.end());
    sort(genre_count.begin(), genre_count.end(), compare1);
    vector<int> answer;
    answer.reserve(size);
    for (auto p : genre_count)
    {
        vector<pair<int, int> > tmp = songs[p.first];
        sort(tmp.begin(), tmp.end(), compare2);
        for (int i = 0; i < 2 && i < tmp.size(); i++)
            answer.push_back(tmp[i].first);
    }
    return answer;
}