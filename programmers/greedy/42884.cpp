#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> route1, vector<int> route2) {
    return route1[1] < route2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = -30001;
    sort(routes.begin(), routes.end(), compare);
    for (vector<int> route : routes) {
        if (camera < route[0]) {
            camera = route[1];
            answer++;
        }
    }
    return answer;
}

/* 고속도로의 앞부분부터 순서대로 카메라를 설치한다고 하자. */
/* 진출 시점이 빠른 차량 순으로 정렬해야 앞부분부터 설치가 가능하다. */
/* 가장 최근에 설치된 카메라가 들어오는 차량의 진입 지점보다 앞에 있으면 추가로 카메라를 설치해야 한다. */