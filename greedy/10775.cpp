// 10775: 공항
// 유니온 파인드 알고리즘을 사용하는 그리디 문제

#include <iostream>
#include <vector>
using namespace std;

// int Parent[100001];
vector<int> Parent;
// int Rank[100001];

int Find(int x)
{
	if (x == Parent[x]) return x;
	else
	{
		int y = Find(Parent[x]);
		Parent[x] = y;
		return y;
	}
}

void Union(int x, int y)
{
	x = Find(x), y = Find(y);
	Parent[y] = x;


	// 문제 조건으로 인해 Rank를 쓰면 안된다

	//if (x == y) return;
	
	//if (Rank[x] > Rank[y])
	//{
	//	Parent[y] = x;
	//	Rank[x] += Rank[y];
	//}
	//else
	//{
	//	Parent[x] = y;
	//	Rank[y] += Rank[x];
	//}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int g; cin >> g;
	for (int i = 0; i <= g; i++) Parent.push_back(i);
	int p; cin >> p;
	vector<int> gi(p);
	for (size_t i = 0; i < gi.size(); i++) cin >> gi[i];

	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		int k = Find(gi[i]);
		if (k == 0) break;
		Union(k - 1, k);
		cnt++;
	}

	cout << cnt << '\n';
	// for (int i = 0; i < 100001; i++) Parent[i] = i;
	// for (int i = 0; i < 100001; i++) Rank[i] = 1;


}
