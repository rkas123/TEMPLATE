struct Data {
	int num;
	Data()
	{
		num = 0;
	}
	Data(int n)
	{
		num = n;
	}
};


struct Segment_Tree {
	vector<Data> segtree;
	vector<int> lazy;
	Segment_Tree(int n) {
		segtree = vector<Data>(4 * n);
	}
	Segment_Tree(vector<int> &a) {
		int n = a.size();
		segtree = vector<Data>(4 * n);
		lazy = vector<int>(4 * n, 0);
		build(a, 0, n - 1, 1);
	}


	void propagate(int root, int s, int e)
	{
		if (lazy[root] != 0)
		{
			//make updates on the current node

			if (s != e)
			{
				lazy[2 * root] += lazy[root];
				lazy[2 * root + 1] += lazy[root];
			}
			lazy[root] = 0;
		}
	}

	Data f(Data a, Data b) {
		//Just change this for a different segment tree
		return a;
	}

	void build(vector<int> &a, int s, int e, int root) {
		// base case
		if (s == e) {
			segtree[root] = Data(a[s]);
			return;
		}

		int mid = (s + e) / 2;
		build(a, s, mid, 2 * root);
		build(a, mid + 1, e, 2 * root + 1);

		// self work
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	void point_update(int s, int e, int root, int idx, int val) {
		// base case
		if (s == e) {
			segtree[root] = Data(val);
			return;
		}

		int mid = (s + e) / 2;
		if (mid >= idx) {
			point_update(s, mid, 2 * root, idx, val);
		}
		else {
			point_update(mid + 1, e, 2 * root + 1, idx, val);
		}

		// self work
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	void point_update(vector<int> &a, int s, int e, int root, int idx, int val) {
		// base case
		if (s == e) {
			segtree[root] = Data(val);
			a[idx] = val;
			return;
		}

		int mid = (s + e) / 2;
		if (mid >= idx) {
			point_update(a, s, mid, 2 * root, idx, val);
		}
		else {
			point_update(a, mid + 1, e, 2 * root + 1, idx, val);
		}

		// self work
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	void rupd(int s, int e, int root, int l, int r, int val)
	{
		propagate(root, s, e);

		if (s > r || e < l)
			return;

		if (s >= l && e <= r)
		{
			//make updates in the current node

			if (s != e) //lazy updates
			{
				lazy[2 * root] += val;
				lazy[2 * root + 1] += val;
			}
			return;
		}

		int mid = (s + e) / 2;

		rupd(s, mid, 2 * root, l, r, val);
		rupd(mid + 1, e, 2 * root + 1, l, r, val);
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	Data query(int s, int e, int root, int l, int r) {  //query with root index set to 1
		// completely out of range
		propagate(root, s, e);
		if (s > r || e < l) {
			return 0;
		}
		// completely in range
		if (s >= l && e <= r) {
			return segtree[root];
		}
		// partial overlap
		int mid = (s + e) / 2;
		Data x = query(s, mid, 2 * root, l, r);
		Data y = query(mid + 1, e, 2 * root + 1, l, r);
		return f(x, y);
	}
};