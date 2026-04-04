long long 염두에 두기
DP인가? 를 염두에 두자
단순히 결과를 보고 규칙을 파악한뒤 DP로 가능하다 를 판단하면 되는 문제였다

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long dp[101];
int T;

const int INF = 1e9;

long long P(int n)
{
	if (n == 1 || n == 2 || n == 3)
		return dp[n] = 1;

	if (dp[n] != 0)
		return dp[n];

	return dp[n] = P(n - 2) + P(n - 3);
}


int main()
{
	int n;
	vector<long long> v;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		cin >> n;
		v.push_back(P(n));
	}

	for (int i = 0; i < T; i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}
