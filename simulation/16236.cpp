// 16236: 아기상어
// 그래프 문제(BFS)와 범주가 겹치지만 개인적으로 구현쪽에 더 무게가 있다고 생각하여 여기에 추가한다

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.second < b.second) 
	{
		return true;
	}
	else if(a.second == b.second) 
	{
		if (a.first.first < b.first.first) return true;
		else if (a.first.first == b.first.first)
		{
			if (a.first.second < b.first.second) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}


queue<pair<pair<int, int>, int>> qe;
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1};
vector<pair<pair<int, int>, int>> fish;
// 후보군 벡터
// 마음에 안들지만 먹을 수 있는 모든 물고기를 벡터에 삽입하고 정렬하는 방식으로 해결함
// 가장 앞에 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> vc(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int cx =0, cy=0; // 현재 위치
	int cs = 2; // 현재 크기
	int cnt = 0; // 먹은 수
	int move = 0; // 이동 시간
	bool chk = true;
	for (size_t i = 0; i < vc.size(); i++)
	{
		for (size_t j = 0; j < vc[i].size(); j++)
		{
			cin >> vc[i][j];
			if (vc[i][j] == 9)
			{
				cy = i, cx = j;
			}
		}
	}

	while (chk != false) // 먹을 물고기가 없는 경우 탈출함
	{

		qe.push({{ cy, cx }, 0});	// 현재 위치 삽입
		visited[cy][cx] = true;		// 현재 위치를 방문했다 표시한다
		vc[cy][cx] = 0;				// 현재 위치를 지운다(물고기가 있든 없든)
		chk = false;				
		while (qe.empty() != true)	// BFS 수행
		{
			int y = qe.front().first.first;
			int x = qe.front().first.second;
			int ct = qe.front().second;

			if (vc[y][x] != 0 && vc[y][x] < cs) // 물고기를 찾아낸 경우
			{
				chk = true;
        // 먹을 물고기가 있다고 표시한다.
        // 시간을 더 소모하는 것을 방지하기 위한 변수
				fish.push_back({ { y,x }, ct });
			}
			qe.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (visited[ny][nx] == true) continue;
				if (vc[ny][nx] > cs) continue;
				visited[ny][nx] = true;
				qe.push({ {ny, nx}, ct + 1 });
			}
		}
		if (fish.empty() != true)
		{
			while (qe.empty() != true) qe.pop();		// 큐를 비운다.
			visited.assign(n, vector<bool>(n, false));	// 방문 기록을 초기화한다.
			cnt++;										// 먹은 횟수를 증가시킨다
			if (cnt == cs)								// 만약 먹은 횟수가 현재 크기랑 동일하다면
			{
				cs++;; cnt = 0;							// 크기를 키우고 먹은 횟수를 초기화한다.
			}
			sort(fish.begin(), fish.end(), cmp);		// 거리가 가깝고, 상단, 좌측에 가까운 물고기 순으로 정렬한다
			cy = fish[0].first.first, cx = fish[0].first.second;
			move += fish[0].second;
			fish.clear();
		}
	}
	cout << move << '\n';
}
