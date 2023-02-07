#ifndef PROP_H
#define PROP_H

namespace PropertyA
{
    bool Property(int a[], int n)
    {
        for (int i = 0; i < n - 2; i += 1)
        {
            if (a[i] == a[i+1] && a[i] == a[i+2])
            {
                return true;
            }
        }
        
        return false;
    }
}

namespace PropertyB
{
    bool Property(int a[], int n)
    {
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (a[i] == a[i+1])
            {
                j += 1;
            }

            if (j == 3)
            {
                return true;
            }

            i += 1;
        }
        return false;
    }
}

namespace PropertyC
{
    bool Property(int a[], int n)
    {
        for (int i = 0; i < n; i += 1)
        {
            if (a[i] >= a[i+1])
            // I figured I would check by making sure value 1 isn't bigger than value 2. Which didn't work.
            {
                return false;
            }
        }
        return true;
    }
}

#endif