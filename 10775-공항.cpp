유니온 파인드라는 알고리즘을 쓰면 쉽게 구한다.
그 다음으로 가능한 상태를 찾아 연결하는데 쓰는 알고리즘이라고 한다.

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

int G, P;
int parent[100001];

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main()
{
	cin >> G >> P;

	for (int i = 0; i <= G; i++)
	{
		parent[i] = i;
	}
	
	int answer = 0;

	for (int i = 0; i < P; i++)
	{
		int g;
		cin >> g;
		
		int root = find(g);

		if (root == 0) break;

		parent[root] = root - 1;
		answer++;
	}

	cout << answer << '\n';

	return 0;
}
