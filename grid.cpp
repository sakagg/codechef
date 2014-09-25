#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	
	int T;
	int n;
	int count;
	char s[1010][1010];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		vector<int> hlast(1010, -1), vlast(1010, -1);
		for(int i=0; i<n; i++)
			scanf("%s", s[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(s[i][j] == '#')
				{
					hlast[i] = j;
					vlast[j] = i;
				}
		for(int i=0; i<n; i++)
		{
//			cout<<hlast[i] << "    "<<vlast[i] <<endl;
		}
		count = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i>vlast[j] && j>hlast[i])
					count++;
		cout<<count<<endl;
	}
	return 0;
}

