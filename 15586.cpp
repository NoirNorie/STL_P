#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a) // ������ & �� �ּҸ� �Ѱ��ش�
// ���� ��ü�� ���簡 �ƴ� �ּ��� ������ �����ִ� ��
{
	int result = 0;
	for (int i = 0; i < a.size(); i++)
	{
		result += a[i];
	}
	return result;
}

int main()
{
	vector<int> a;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		a.push_back(i);
	}

	cout << sum(a) << endl;
}