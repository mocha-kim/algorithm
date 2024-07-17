#include <iostream>
#include <queue>
#include <string>
using namespace std;
	
int main() {
	int n, m;
	cin >> n >> m;
	
	string str;
	priority_queue<string, vector<string>, greater<string>> not_heard;
	for (int i = 0; i < n; i++) {
		cin >> str;
		not_heard.push(str);
	}
	priority_queue<string, vector<string>, greater<string>> not_seen;
	for (int i = 0; i < n; i++) {
		cin >> str;
		not_seen.push(str);
	}

	vector<string> not_seen_heard;
	while(!not_heard.empty() && !not_seen.empty()) {
		string nh_name = not_heard.top();
		string ns_name = not_seen.top();
		if (nh_name == ns_name) {
			not_seen_heard.push_back(nh_name);
			not_heard.pop();
			not_seen.pop();
		} else if (nh_name < ns_name) {
			not_heard.pop();
		} else {
			not_seen.pop();
		}
	}
	
    cout << not_seen_heard.size() << "\n";
	for (string name : not_seen_heard)
		cout << name << "\n";
	
    return 0;
}