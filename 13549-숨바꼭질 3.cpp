0-1 BFS는 덱을 써서 풉니다.
상한선 범위 설정할때 좀 주의

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>
#include <string>
#include <stack>
#include <list>
#include <unordered_set>
#include <set>
#include <deque>

using namespace std;

int N, K;

int dp[200001];
deque<int> q;


int main()
{
	cin >> N >> K;
	int maxLength = 100000;

	for (int i = 0; i < maxLength * 2; i++)
	{
		dp[i] = maxLength;
	}

	q.push_back(N);
	dp[N] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();

		if (cur - 1 >= 0 && dp[cur - 1] > dp[cur] + 1 )
		{
			dp[cur - 1] = dp[cur] + 1;
			q.push_back(cur - 1);
		}
		if (cur + 1 <= maxLength && dp[cur + 1] > dp[cur] + 1)
		{
			dp[cur + 1] = dp[cur] + 1;
			q.push_back(cur + 1);
		}
		if(cur * 2 <= maxLength * 2 && dp[cur * 2] > dp[cur])
		{
			dp[cur * 2] = dp[cur];
			q.push_front(cur * 2);
		}
	}

	cout << dp[K] << '\n';

	return 0;
}
