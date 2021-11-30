#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<bool> visited(100001, false);
queue<pair<int,int>> qe;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	qe.push({ N, 0 });
	visited[N] = true;
	while (qe.empty() != true)
	{
		int cr = qe.front().first;
		int t = qe.front().second;
		qe.pop();

		if (cr == K)
		{
			cout << t << '\n';
			break;
		}
		
		if (cr - 1 >= 0 && visited[cr - 1] != true)
		{
			qe.push({ cr - 1, t + 1 });
			visited[cr - 1] = true;
		}
		if (cr + 1 <= 100000 && visited[cr + 1] != true)
		{
			qe.push({ cr + 1, t + 1 });
			visited[cr + 1] = true;
		}
		if (cr * 2 <= 100000 && visited[cr * 2] != true)
		{
			qe.push({ cr * 2, t + 1 });
			visited[cr * 2] = true;
		}
	}
	return 0;
}
