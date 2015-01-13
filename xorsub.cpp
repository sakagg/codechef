#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		sort(a, a+n);
		reverse(a, a+n);
		int i=15, lnum = 0;
		while((a[0]&(1<<i)) == 0)
			i--;
		for(; i>=0; i--, lnum++)
		{
			if((a[lnum]&(1<<i)) == 0)
			{
				int j;
				for(j=lnum+1; j<n; j++)
					if((a[j]&(1<<i)) != 0)
					{
						swap(a[lnum], a[j]);
						break;
					}
				if(j == n)
					continue;
			}
			for(int j=lnum+1; j<n; j++)
				a[j] = min(a[j], a[j]^a[lnum]);
		}
		int ans = k;
		for(int i=0; i<n; i++)
			ans = max(ans, ans^a[i]);
		printf("%d\n", ans);
	}
	return 0;
}
