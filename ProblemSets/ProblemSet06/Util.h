#ifndef UTIL_H
#define UTIL_H

namespace PS6
{
	int GCD(int n,int m)
	{
		if(n < 0)
		{
			n *= -1;
		}

		if(m < 0)
		{
			m *= -1;
		}

		int r;

		while(n != 0)
		{
			r = m % n;
			m = n;
			n = r;
		}
		return m;
	}
}
#endif
