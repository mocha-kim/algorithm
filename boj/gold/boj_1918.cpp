#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    string answer = "";
    stack<char> operators;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            answer += c;
        } else {
            switch(c) {
                case '(':
                    operators.push(c);
                    break;
                case ')':
                    while (!operators.empty() && operators.top() != '(')
                    {
                        answer += operators.top();
                        operators.pop();
                    }
                    operators.pop();
                    break;
                case '*':
                case '/':
                    while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                        answer += operators.top();
                        operators.pop();
                    }
                    operators.push(c);
                    break;
                case '+':
                case '-':
                    while (!operators.empty() && operators.top() != '(')
                    {
                        answer += operators.top();
                        operators.pop();
                    }
                    operators.push(c);
                    break;
            }
        }
    }
    while(!operators.empty()) {
        answer += operators.top();
        operators.pop();
    }
    cout << answer;
    return 0;
}