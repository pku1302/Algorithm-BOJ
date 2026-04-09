#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

int dp[1001][1001];

string l1;
string l2;

int main()
{
	cin >> l1;
	cin >> l2;
	
	if (l1[0] == l2[0])
		dp[1][1] = 1;

	for (int i = 1; i <= l1.length(); i++)
	{
		for (int j = 1; j <= l2.length(); j++)
		{
			if (l1[i - 1] == l2[j - 1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
			}
		}
	}	

	cout << dp[l1.length()][l2.length()] << '\n';

	return 0;
}
