#include <iostream>
#include <cmath>
using namespace std;

long long get_toka_distance(long long t, long long b, long long k);
long long get_doldol_distance(long long t, long long c, long long d);

int main() 
{
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    
	long long end = ceil(float(a + c) / d);
	long long start = 1;
	
	long long arrived_time = end + 1, catched_time = end;
	
	long long t;
    while(start <= end)
    {
        t = (end + start) / 2;
        if (b <= k * (t - 1)) // toka cannot move
        {
            end = t - 1;
            continue;
        }

        long long toka =  get_toka_distance(t, b, k);
        long long doldol = get_doldol_distance(t, c, d);
        if (toka >= a) // arrived
        {
            end = t - 1;
            arrived_time = min(t, arrived_time);
            continue;
        }

        start = t + 1;
        if (doldol >= toka) // catched
        {
            catched_time = min(t, catched_time);
            continue;
        }
	}
	
	cout << (arrived_time < catched_time ? arrived_time : -1);
	return 0;
}

long long get_toka_distance(long long t, long long b, long long k)
{
    if (k == 0)
    {
        return t * b;
    }
	return t * b - (t - 1) * t / 2 * k;
}

long long get_doldol_distance(long long t, long long c, long long d)
{
	return t * d - c;
}