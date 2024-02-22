#include <vector>

using namespace std;

template <typename T>
vector<T> prefix_sum(vector<T> array)
{
    int n = array.size();
    vector<T> prefix_sum_array(n);
    prefix_sum_array[0] = array[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum_array[i] = prefix_sum_array[i - 1] + array[i];
    }
    return prefix_sum_array;
}