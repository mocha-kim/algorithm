#include <iostream>
#include <cstring>
using namespace std;

void PrintStars(int star_count, int n);
	
int main()
{
    int n;
    cin >> n;
    
    PrintStars(0, n);
    return 0;
}

void PrintStars(int line, int n)
{
	char star[line + n + 1];
	memset(star, '*', sizeof(star));
	memset(star, ' ', n - line - 1);
	star[line + n] = '\0';
	cout << star << "\n";
	
	if (line == n - 1)
		return;

	PrintStars(line + 1, n);
	cout << star << "\n";
}