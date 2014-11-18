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

void expo(double a[26][26], int k)
{
	vector< vector<double> > ans(26, vector<double>(26));
	for(int i=0; i<26; i++)
		ans[i][i] = 1;
	while(k)
	{
		if(k&1)
		{
			vector< vector<double> > tmp(26, vector<double>(26));
			for(int i=0; i<26; i++)
				for(int j=0; j<26; j++)
					for(int x=0; x<26; x++)
						tmp[i][j] += a[i][x]*ans[x][j];
			ans = tmp;
		}
//		for(int i=0; i<26; i++)
//			print_array_v(ans[i]);
		k>>=1;
		vector< vector<double> > tmp(26, vector<double>(26));
		for(int i=0; i<26; i++)
			for(int j=0; j<26; j++)
				for(int x=0; x<26; x++)
					tmp[i][j] += a[i][x]*a[x][j];
		for(int i=0; i<26; i++)
			for(int j=0; j<26; j++)
				a[i][j] = tmp[i][j];
//		for(int i=0; i<26; i++)
//			print_array_v(ans[i]);
	}
	for(int i=0; i<26; i++)
		for(int j=0; j<26; j++)
			a[i][j] = ans[i][j];
}

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		double a[26][26];
		char s[10];
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		for(int i=0; i<26; i++)
			for(int j=0; j<26; j++)
				scanf("%lf", a[i]+j);
		expo(a, k);
//		for(int i=0; i<26; i++)
//			print_array(a[i], 26);
		double ans = 0, tmp;
		int len = strlen(s);
		string str;
		map<string, int> mp;
		while(n--)
		{
			cin>>str;
			if(mp[str])
				continue;
			mp[str] = 1;
			if(str.size() != len)
				continue;
			tmp = 1;
			for(int i=0; i<len; i++)
				tmp *= a[s[i]-'a'][str[i]-'a'];
			ans += tmp;
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}

