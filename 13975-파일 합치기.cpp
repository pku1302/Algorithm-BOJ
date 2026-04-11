우선 순위 큐 쓰는 방법 알아둬야 할 듯
long long 에 항상 주의

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

using namespace std;

int T;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main()
{
	cin >> T;
	vector<long long> res;

	for (int i = 0; i < T; i++)
	{
		int K;

		cin >> K;

		for (int i = 0; i < K; i++)
		{
			long long x;
			cin >> x;
			pq.push(x);
		}

		long long answer = 0;

		while (pq.size() != 1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			pq.push(a + b);
			answer += (a + b);
		}
		res.push_back(answer);
		pq.pop();
	}

	for (int i = 0; i < T; i++)
	{
		cout << res[i] << '\n';
	}

	return 0;
}
