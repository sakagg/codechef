#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int ispalin(char *s, int i, int j)
{
	while(i<j)
		if(s[i++]!=s[j--])
			return 0;
	return 1;
}

int main()
{
	int T;
	char s[100100];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int i;
		int n = strlen(s);
		for(i=0; i<n/2 && s[i]==s[n-i-1]; i++);
		if(i==n/2 || ispalin(s, i, n-i-2) || ispalin(s, i+1, n-i-1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

