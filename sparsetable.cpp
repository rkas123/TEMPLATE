struct SparseTable {
	vector<vector<int>> table;
	vector<int> logvalues;
	vector<int> v;
	int n;
	int maxLog;
	SparseTable(vector<int>&a)
	{
		v = a;
		this->n = a.size();
		table.resize(n);
		logvalues.resize(n + 1);
		maxLog = log2(n);
		logvalues[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			logvalues[i] = logvalues[i / 2] + 1;
		}
		for (int i = 0; i < n; i++)
		{
			table[i].resize(maxLog + 1);
			for (int j = 0; j <= maxLog; j++)
				table[i][j] = 0; // 0 is the identity element
		}
		build();
	}
	void build()
	{
		for (int i = 0; i < n; i++)
		{
			table[i][0] =  v[i];
		}
		for (int i = 1; i <= maxLog; i++)
		{
			for (int j = 0; (j + (1 << i)) <= n ; j++)
			{
				table[j][i] = merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	int non_overlap(int left, int right)    	//dont use, instead use seg-tree
	{
		int ans = 0;						//identity answer. for sum = 0 etc.
		for (int j = logvalues[right - left + 1]; j >= 0; j--)
		{
			if ((1 << j) <= right - left + 1)
			{
				ans = merge(ans, table[left][j]);
			}
			left += (1 << j);
		}
		return ans;
	}
	int overlap(int left, int right)			//O(1), min,max,gcd
	{
		int j = logvalues[right - left + 1];
		int ans = merge(table[left][j], table[right - (1 << j) + 1][j]);
		return ans;
	}

	int merge(int a, int b)
	{
		return min(a, b); //change this to min/max/gcd
	}
};