#include <string>
#include <vector>
using namespace std;

template <typename T>
vector<int> KMP(T s) // O(n)  //Prefix Function
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

template <typename T>
vector<int> z_function(T s) // O(n)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = r - i < z[i - l] ? r - i : z[i - l];
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> manachers(string s) // O(n)
{
    // #s2#s3#s4 ....  // even -> d_even // odd -> d_odd
    int n = s.size();
    string modified_string = '&' + s + s + '@';
    for (int i = 0; i < n; i++)
    {
        modified_string[2 * i + 1] = '#';
        modified_string[2 * i + 2] = s[i];
    }
    s = modified_string;
    vector<int> p(n + n, 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n + n; i++)
    {
        if (i > r)
        {
            l = i;
            r = i;
        }
        p[i - 1] = p[l + r - i - 1];
        if (i + p[i - 1] - 1 >= r)
        {
            p[i - 1] = r - i + 1;
            l = 2 * i - r;
        }
        while (s[l - 1] == s[r + 1])
        {
            p[i - 1]++;
            l--;
            r++;
        }
    }
    for (int i = 0; i < n + n; i++)
    {
        if (i & 1)
        {
            p[i] = p[i] - !(p[i] & 1);
        }
        else
        {
            p[i] = (p[i] / 2) * 2;
        }
    }
    return p;
}
