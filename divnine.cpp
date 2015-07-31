#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int t;
	scanf("%d", &t);
	char s[111111];
	while (t--)
	{
		scanf("%s", s);
		LL sum = 0;
		for (int i = 0; s[i]; i++)
			sum += s[i] - '0';
		LL mod = sum % 9;
		LL ans;
		if (mod == 0)
			ans = 0;
		else
		{
			LL toRem = mod, foo = mod;
			LL toAdd = 9 - mod, bar = 9 - mod;
			bool a = false, b = false;
			for (int i = 1; s[i]; i++)
			{
				LL canRemove = min((int) toRem, s[i] - '0');
				toRem -= canRemove;
				if (toRem == 0)
				{
					a = true;
					break;
				}
			}
			for (int i = 0; s[i]; i++)
			{
				LL canAdd = min((int) toAdd, 9 - (s[i] - '0'));
				toAdd -= canAdd;
				if (toAdd == 0)
				{
					b = true;
					break;
				}
			}
			if (a and b)
				ans = min(foo, bar);
			else if (a)
				ans = foo;
			else
				ans = bar;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
