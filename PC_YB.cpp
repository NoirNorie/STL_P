#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	deque<int> droplist(N);
	deque<int> wishlist(N);
	
	int answer = 0;

	for (int i = 0; i < N; i++) // 내놓을 수업
	{
		cin >> droplist[i];
	}
	for (int i = 0; i < N; i++) // 원하는 수업
	{
		cin >> wishlist[i];
	}

	sort(droplist.begin(), droplist.end());
	sort(wishlist.begin(), wishlist.end());

	int i = 0;
	deque<int>::iterator iter = wishlist.begin();
	while (iter != wishlist.end())
	{
		if (i >= droplist.size()) // 끝까지 순회했는데 원하는 강의가 없다면
		{
			iter++; // 이번 학기에는 못들음
			i = 0;
		}

		if (iter == wishlist.end()) break;

		if ((*iter) == droplist[i])
		{
			droplist.erase(droplist.begin() + i);
			iter++; i = 0;
			continue;
		}
		
		i++;
	}

	cout << droplist.size() << '\n';

	return 0;
}