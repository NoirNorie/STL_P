#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 1003(피보나치 함수)

vector<int> memo; // Memoization Vector

int cnt0 = 0; int cnt1 = 0;

int Memoization_fibo(int n);

int main()
{
    vector<pair<int, int>> Result_V; // 결과를 담을 벡터

    int Trial, N;
    cin >> Trial; // 횟수를 입력받음

    for (int i = 0; i < Trial; i++)
    {
        cin >> N; // 테스트 케이스 입력


        memo = { 0, 1 }; // 초기화

        Memoization_fibo(N);
        Result_V.push_back(make_pair(cnt0, cnt1)); // 결과 저장

        memo.clear();
        cnt0 = 0; cnt1 = 0; // 전역변수 초기화
    }

    vector<pair<int, int>>::iterator iter; // 테스트 케이스 출력
    for (iter = Result_V.begin(); iter != Result_V.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

int Memoization_fibo(int n)
{
    int result;

    if (n == 0)
    {
        cnt0++;
        result = n;
    }
    else if (n == 1)
    {
        cnt1++;
        result = n;
    }
    else // 2 이상의 경우
    {
        int index = n;
        if (index >= memo.size()) // 벡터의 크기보다 반복 횟수가 큰 경우
        {
            memo.push_back(Memoization_fibo(index - 1) + Memoization_fibo(index - 2)); // 새롭게 값을 기억한다.
            result = memo[index];
        }     
        else // 아닌 경우 값을 넘겨준다.
        {
            result = memo[index];
        }
    }
    return result;
}

