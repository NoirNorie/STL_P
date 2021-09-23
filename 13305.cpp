#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 13305(주유소)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; // 도시의 개수 입력
	vector<long long int> road(N - 1, 0);// 도로의 길이
	vector<long long int> price(N, 0); // 기름 가격
	
	long long int price_sum = 0;

	for (int i = 0; i < N-1; i++)
	{
		cin >> road[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
	}

	// 일단 뭐가 되었든 다음 도시로 이동할 기름은 넣어야 함
	int p = 0; int move = 0;
	price_sum += road[p] * price[p];

	while ((++move) < N-1)
	{
		if (price[p] > price[move]) // 현재 도시보다 다음 도시의 기름 가격이 더 싼가?
		{
			// 기름 값이 싼 곳으로 이동한다.		
			p = move;
		}
		// 현재 도시의 기름 가격이 더 싸거나 같다면
		// 현재 도시에서 기름을 더 추가한다.
		price_sum += road[move] * price[p];
	}

	cout << price_sum << '\n';

	return 0;
}