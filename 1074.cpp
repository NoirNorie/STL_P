#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ���� ��ȣ: 1074(Z)
// ������ �������� �޸� �ʰ��� ������� ����

vector<vector<int>> v;
int nums = 0;

void func(int s, int i, int j)
{
	if (s == 2) // ���� ���¿� ������ ���
	{
		v[i][j] = nums++;
		v[i][j+1] = nums++;
		v[i+1][j] = nums++;
		v[i + 1][j + 1] = nums++;
		return; // ��ȣ�� �Է��ϰ� ��ȯ
	}
	else
	{
		int ns = s / 2; // ���� ũ��
		func(ns, i, j);
		func(ns, i , j + ns);
		func(ns, i + ns, j );
		func(ns, i + ns, j + ns);
	}
}



int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	int s = pow(2, n);

	v.assign(s, vector<int>(s, 0));
	func(s, 0, 0);

	cout << v[r][c] << '\n';

	return 0;
}