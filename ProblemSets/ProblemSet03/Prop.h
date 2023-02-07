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
        return true;
    }
}

namespace PropertyC
{
    bool Property(int a[], int n)
    {
        return true;
    }
}

#endif