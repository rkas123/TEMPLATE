struct BIT {
	vector<int> tree;
	int n;

	BIT(vector<int> &v)   //v must be 1 based
	{
		n = v.size();
		tree = vector<int>(n, 0);
		for (int i = 1; i < n; i++)
		{
			update(i, v[i]);
		}
	}
	int query(int idx)
	{
		int ans = 0;
		while (idx > 0)
		{
			ans += tree[idx];
			idx -= (idx & (-idx));
		}
		return ans;
	}

	void update(int idx, int val)
	{
		while (idx <= n)
		{
			tree[idx] += val;
			idx += (idx & (-idx));
		}
	}
};