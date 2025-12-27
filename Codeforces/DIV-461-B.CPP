#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	while(cin>>n)
	{
		int ans = 0;

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				int x = i^j;
				if(x<=j && j+x>i)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
