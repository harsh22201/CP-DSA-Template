// segtree space 4n //call stack space O(log(n)) //time to build O(n)
// make_segment_tree(segtree,array,0,0,array_size-1);
void make_segment_tree(int segtree[], int array[], int index, int array_low, int array_high)
{
    if (array_low == array_high)
    {
        segtree[index] = array[array_low];
        return;
    }

    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;

    int range_mid = (array_low + array_high) / 2;

    make_segment_tree(segtree, array, left_index, array_low, range_mid);
    make_segment_tree(segtree, array, right_index, range_mid + 1, array_high);

    segtree[index] = segtree[left_index] + segtree[right_index]; // operation
}

// call stack O(log(n)) //time O(log(n))
// query(segtree,0,0,array_size-1,l,r);
int query(int segtree[], int index, int array_low, int array_high, int l, int r)
{ // array low & high represent value of segtree[index] for array range

    if (l <= array_low && array_high <= r)
    {
        return segtree[index];
    }
    if (l > array_high || r < array_low)
    {
        return 0; // operation
    }
    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;

    int array_mid = (array_high + array_low) / 2;

    int left_query = query(segtree, left_index, array_low, array_mid, l, r);
    int right_query = query(segtree, right_index, array_mid + 1, array_high, l, r);

    return left_query + right_query; // operation
}

// call stack O(log(n)) //time O(log(n))
// update(segtree,0,0,array_size-1,update_index,new_val);
void update(int segtree[], int index, int array_low, int array_high, int update_index, int new_val)
{
    if (array_low == array_high)
    {
        segtree[index] = new_val;
    }
    else
    {
        int left_index = 2 * index + 1;
        int right_index = 2 * index + 2;
        int array_mid = (array_low + array_high) / 2;
        if (update_index <= array_mid)
        {
            update(segtree, left_index, array_low, array_mid, update_index, new_val);
        }
        else
        {
            update(segtree, right_index, array_mid + 1, array_high, update_index, new_val);
        }
        segtree[index] = segtree[left_index] + segtree[right_index]; // operation
    }
}