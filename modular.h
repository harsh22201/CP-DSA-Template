#define MOD 1000000007
long long mod_mul(long long a, long long b, long long modulo = MOD)
{
    a = a % modulo;
    b = b % modulo;
    long long product = (a * b) % modulo;
    return product;
}

long long mod_add(long long a, long long b, long long modulo = MOD)
{
    a = a % modulo;
    b = b % modulo;
    long long sum = (a + b) % modulo;
    return sum;
}

long long mod_sub(long long a, long long b, long long modulo = MOD)
{
    a = a % modulo;
    b = b % modulo;
    a = a - b;
    if (a < 0)
        return a + modulo;
    return a;
}

long long mod_pow(long long a, long long b, long long modulo = MOD) // O log2(b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mod_mul(res, a, modulo);
        a = mod_mul(a, a, modulo);
        b >>= 1;
    }
    return res;
}

// Modular multiplicative inverse of A under modulo M exist if coprime or gcd(A, M)=1:

long long mod_inverse(long long a, long long modulo = MOD) // O log2(modulo-2)
{
    return mod_pow(a, modulo - 2, modulo);
}

long long mod_div(long long a, long long b, long long modulo = MOD) //(a / b) modulo m = (a x (inverse of b if exists)) modulo m
{
    a = a % modulo;
    long long b_inv = mod_inverse(b, modulo);
    long long div = (a * b_inv) % modulo;
    return div;
}
