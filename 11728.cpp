#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 11728(배열 합치기)
// 벡터로도 해보고 배열로도 해봄

int n, m;
//int A[1000001], B[1000001], C[2000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 처리
	cin >> n >> m;
	vector<int> A(n);
	vector<int> B(m);
	vector<int> C(n + m);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int Ai = 0, Bi = 0;

	for (int i = 0; i < n + m; i++)
	{
		if (Ai == n) C[i] = B[Bi++];
		else if (Bi == m) C[i] = A[Ai++];
		else if (A[Ai] > B[Bi]) C[i] = B[Bi++];
		else C[i] = A[Ai++];
	}
	
	for (int i = 0; i < n + m; i++)
	{
		cout << C[i] << " ";
	}

	return 0;
}