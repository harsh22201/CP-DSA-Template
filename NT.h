#include <vector>
using namespace std;
#define int long long

template <typename T>
vector<T> prefix_sum(vector<T> array)
{
    int n = array.size();
    vector<T> prefix_sum_array;
    prefix_sum_array.push_back(0);
    for (int i = 0; i < n; i++)
        prefix_sum_array.push_back(array[i] + prefix_sum_array[i]);
    return prefix_sum_array;
}

vector<int> prime_numbers(int n) // returns list of prime numbers till n //O((n/2)loglog(n/2))
{
    vector<int> prime_list;
    if (n < 2)
        return prime_list;
    prime_list.emplace_back(2);
    vector<bool> seive_of_eratosthenes(n / 2 + 1, true); // space - n/2
    seive_of_eratosthenes[0] = false;
    int soe_size = seive_of_eratosthenes.size();
    for (int i = 1; i < soe_size; i++)
    {
        if (seive_of_eratosthenes[i])
        {
            int prime = 2 * i + 1;
            if (prime > n) // edge case where last prime exceed n
                break;
            prime_list.emplace_back(prime);
            for (int j = (prime * prime) / 2; j < soe_size; j += prime) // SIGMA(1/prime) ~ loglog(n)
                seive_of_eratosthenes[j] = false;
        }
    }
    return prime_list; // space log(n)/n //there are apprx. this many prime no.s till n
}