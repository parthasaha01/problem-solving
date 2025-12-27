#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1005][1005];
char s[1005];
int main()
{
	int T; scanf("%d%*c", &T);
	while(T--)
    {
		gets(s);
		int n = strlen(s);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (s[i-1] == s[n-j])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
		printf("%d\n", dp[n][n]);
	}
	return 0;
}
