#include <vector>
#include <queue>

using namespace std;

typedef struct s_truck
{
    int weight;
    int position = 0;
} t_truck;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int truck_count = 0, bridge_count = 0, total_weight = 0;
    queue<int> trucks;
    for (int i : truck_weights)
        trucks.push(i);
    queue<t_truck> bridge;
    while (truck_count < truck_weights.size())
    {
        answer++;
        if (!bridge.empty())
        {
            for (int i = 0; i < bridge_count; i++)
            {
                t_truck tmp = bridge.front();
                bridge.pop();
                tmp.position++;
                bridge.push(tmp);
            }
            t_truck front = bridge.front();
            if (front.position == bridge_length)
            {
                bridge.pop();
                total_weight -= front.weight;
                bridge_count--;
                truck_count++;
            }
        }
        if (!trucks.empty())
        {
            int next = trucks.front();
            if (total_weight + next <= weight && bridge_count <= bridge_length)
            {
                trucks.pop();
                t_truck tmp;
                tmp.weight = next;
                bridge.push(tmp);
                total_weight += tmp.weight;
                bridge_count++;
            }
        }
    }
    return answer;
}