
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

char a[100100];

void flip(char &num)
{
	num = '0' + '1' - num;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		SI(n); SI(k);
		scanf("%s", a);
		if(k!=1)
		{
			int cnt = 1;
			int ans = 0;
			for(int i=1; i<n; i++)
			{
				if(a[i]==a[i-1])
				{
					cnt++;
					if(cnt == k+1)
					{
						if(i<n-1 && a[i+1]==a[i])
							flip(a[i]);
						else
							flip(a[i-1]);
						ans++;
						cnt = 0;
					}
				}
				else
				{
					cnt = 1;
				}
			}
			printf("%d\n", ans);
			for(int i=0; i<n; i++)
				printf("%c", a[i]);
			cout<<endl;
		}
		else
		{
			int cnt = 0; //Starts with 0
			for(int i=0; i<n; i++)
				if(a[i] != (i%2)+'0')
					cnt++;
			if(cnt <= n-cnt)
			{
				printf("%d\n", cnt);
				for(int i=0; i<n; i++)
					printf("%d", i%2);
				cout<<endl;
			}
			else
			{
				printf("%d\n", n-cnt);
				for(int i=1; i<=n; i++)
					printf("%d", i%2);
				cout<<endl;
			}
		}
	}
	return 0;
}
