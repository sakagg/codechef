
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

int isopening(char c)
{
	if(c=='{' || c=='[' || c=='(' || c=='<')
		return 1;
	return 0;
}

int getInt(char c)
{
	if(c=='{' || c == '}')
		return 1;
	else if(c=='[' || c==']')
		return 2;
	else if(c=='(' || c==')')
		return 3;
	else if(c=='<' || c=='>')
		return 4;

	return -1;
}

char a[100100];
int open[100100];
LL b[100100], dp[100100];

stack<int> s;	

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		memset(open, -1, (n+2)*sizeof(int));
		scanf("%s", a+1);
		b[0] = 0;
		for(int i=1; i<=n; i++)
		{
			SLL(b[i]);
			b[i] += b[i-1];
		}
		s = stack<int>();
		for(int i=1; i<=n; i++)
		{
			if(isopening(a[i]))
				s.push(i);
			else if(!s.empty())
			{
				int ind = s.top(); s.pop();
				if(getInt(a[ind]) == getInt(a[i]))
					open[i] = ind;
				else
					while(!s.empty())
						s.pop();
			}
		}
		LL mx = 0;
		dp[0] = 0;
		for(int i=1; i<=n; i++)
			if(open[i] != -1)
			{
				dp[i] = max(0LL, dp[open[i]-1]);
				dp[i] += (b[i] - b[open[i]-1]);
				mx = max(mx, dp[i]);
			}
			else
				dp[i] = 0;
		printf("%lld\n", mx);
	}
	return 0;
}
