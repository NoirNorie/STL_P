#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v(20000002, 0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int card; cin >> card;
		v[10000000 + card]++;
	}
	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int sel; cin >> sel;
		cout << v[10000000 + sel] << " ";
	}

	return 0;
}