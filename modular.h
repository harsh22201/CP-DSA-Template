long long mod_mul(long long a, long long b, long long mod)
{
    a = a % mod;
    b = b % mod;
    long long product = (a * b) % mod;
    return product;
}

long long mod_add(long long a, long long b, long long mod)
{
    a = a % mod;
    b = b % mod;
    long long sum = (a + b) % mod;
    return sum;
}

long long mod_sub(long long a, long long b, long long mod)
{
    a = a % mod;
    b = b % mod;
    a = a - b;
    if (a < 0)
        return a + mod;
    return a;
}

long long mod_pow(long long a, long long b, long long mod) // O log2(b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Modular multiplicative inverse of A under mod M exist if coprime or gcd(A, M)=1:

long long mod_inverse(long long a, long long mod) // O log2(mod-2)
{
    return mod_pow(a, mod - 2, mod);
}

long long mod_div(long long a, long long b, long long mod) //(a / b) mod m = (a x (inverse of b if exists)) mod m
{
    a = a % mod;
    long long b_inv = mod_inverse(b, mod);
    long long div = (a * b_inv) % mod;
    return div;
}
