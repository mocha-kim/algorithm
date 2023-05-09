#include <string>
#include <vector>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    
    node(int d, node *p, node *n)
    {
        data = d;
        prev = p;
        next = n;
    }
};

string solution(int n, int k, vector<string> cmd) {
    node *cur = new node(0, NULL, NULL);
    node *first = cur;
    for (int i = 1; i < n; i++)
    {
        cur->next = new node(i, cur, NULL);
        cur = cur->next;
    }
    stack<node*> deleted;
    
    cur = first;
    for (int i = 0; i < k; i++)
        cur = cur->next;
    int value;
    for (string s : cmd) {
        switch(s[0]) {
            case 'U':
                value = stoi(s.substr(2));
                for (int i = 0; i < value; i++)
                {
                    if (cur->prev == NULL)
                        break;
                    cur = cur->prev;
                }
                break;
            case 'D':
                value = stoi(s.substr(2));
                for (int i = 0; i < value; i++)
                {
                    if (cur->next == NULL)
                        break;
                    cur = cur->next;
                }
                break;
            case 'C':
                deleted.push(cur);
                if (cur->prev != NULL)
                    cur->prev->next = cur->next;
                if (cur->next != NULL)
                    cur->next->prev = cur->prev;
                cur = (cur->next != NULL) ? cur->next : cur->prev;
                break;
            case 'Z':
                if (deleted.empty())
                    break;
                node *tmp = deleted.top();
                deleted.pop();
                if (tmp->prev != NULL)
                    tmp->prev->next = tmp;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp;
                break;
        }
    }
    string answer(n, 'O');
    while(!deleted.empty())
    {
        answer[deleted.top()->data] = 'X';
        deleted.pop();
    }
    return answer;
}