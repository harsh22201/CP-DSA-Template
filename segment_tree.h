class SegmentTree
{
private:
    // Time complexity: O(n)
    // Space complexity: O(4n)
    void build_segment_tree(int i, int low, int high)
    {
        if (low == high)
        {
            segtree[i] = array[low]; // Operation
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int mid = (low + high) / 2;

        build_segment_tree(l, low, mid);
        build_segment_tree(r, mid + 1, high);

        segtree[i] = segtree[l] + segtree[r]; // Operation
    }

    // Time complexity: O(log(n))
    int query_segment_tree(int i, int low, int high, int a, int b)
    {
        if (a <= low && high <= b)
            return segtree[i];
        if (b < low || high < a)
            return 0; // Operation

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int mid = (high + low) / 2;

        int lq = query_segment_tree(l, low, mid, a, b);
        int rq = query_segment_tree(r, mid + 1, high, a, b);

        return lq + rq; // Operation
    }

    // Update a single element in the segment tree
    // Time complexity: O(log(n))
    void update_segment_tree(int i, int low, int high, int index, int val)
    {
        if (low == high)
            segtree[i] = val; // Operation
        else
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int mid = (low + high) / 2;

            if (index <= mid)
                update_segment_tree(l, low, mid, index, val);
            else
                update_segment_tree(r, mid + 1, high, index, val);

            segtree[i] = segtree[l] + segtree[r]; // Operation
        }
    }

public:
    vector<int> segtree;
    vector<int> array;

    SegmentTree(vector<int> &array)
    {
        this->array = array;
        int n = array.size();
        segtree.resize(4 * n);
        build_segment_tree(0, 0, n - 1);
    }

    int query(int l, int r) // 0 <= l <= r <= n-1
    {
        return query_segment_tree(0, 0, array.size() - 1, l, r);
    }

    void update(int index, int val) // 0 <= i <= n-1
    {
        array[index] = val;
        update_segment_tree(0, 0, array.size() - 1, index, val);
    }
};