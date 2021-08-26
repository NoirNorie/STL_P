#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> memo; // Memorization Vector
pair<int, int> Memoization_fibo(int n);

int main()
{
    vector<pair<int, int>> Result_V; // ����� ���� ����

    int Trial, N;
    cin >> Trial;

    memo.push_back(make_pair(0, 1));
    memo.push_back(make_pair(1, 0));

    for (int i = 0; i < Trial; i++)
    {
        cin >> N;
        Result_V.push_back(Memoization_fibo(N));
    }
    vector<pair<int, int>>::iterator iter;
    for (iter = Result_V.begin(); iter != Result_V.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

pair<int, int> Memoization_fibo(int n)
{
    pair<int, int> result;

    if (n == 0)
    {
        result = make_pair(1, 0);
    }
    else if (n == 1)
    {
        result = make_pair(0, 1);
    }
    else // 2 �̻��� ���
    {
        int index = n;
        if (index >= memo.size()) // ������ ũ�⺸�� �ݺ� Ƚ���� ū ���
        {
            memo.push_back(
                make_pair(
                    (Memoization_fibo(n - 2).first + Memoization_fibo(n - 1).first),
                    (Memoization_fibo(n - 2).second + Memoization_fibo(n - 1).second))
            ); // ���Ӱ� ���� ����Ѵ�.
            result = memo[index];
        }
        else // �ƴ� ��� ���� �Ѱ��ش�.
        {
            result = memo[index];
        }
    }
    return result;
}