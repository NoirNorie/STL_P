// 13300: 방 배정
// 맵을 이용해서 풀이했다

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> male;
map<int, int> female;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int rooms = 0;
    int n, k; cin >> n >> k;
    while (n--)
    {
        int s, y; cin >> s >> y;
        if (s == 0) // 여학생에 대해서
        {
            auto iter = female.find(y);
            // find 연산을 매번 할 경우 그만큼 메모리와 시간을 낭비할 것 같아서 이터레이터를 사용해서 푼다.
            if (iter != female.end())
            {
                iter->second++;
                if (iter->second > k) // 방 인원을 초과한 경우
                {
                    rooms++;          // 방을 하나 추가한다
                    iter->second = 1; // 다음 방으로 인원을 넘긴다
                }
            }
            else // 같은 학년이 없다면
            {
                rooms++;                 // 방을 하나 추가한다
                female.insert({ y, 1 }); // 인원을 넣고 기록해놓는다
            }
        }
        else // 남학생에 대해서도 동일한 작업
        {
            auto iter = male.find(y);
            if (iter != male.end())
            {
                iter->second++;
                if (iter->second > k)
                {
                    iter->second = 1;
                    rooms++;
                }
            }
            else
            {
                male.insert({ y, 1 });
                rooms++;
            }
        }
    }
    cout << rooms << '\n';
}
