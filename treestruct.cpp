struct Tree {
	int n;															//number of nodes
	int LOG;														//height of tree <= 2^LOG
	vector<int> parent;												//direct parent
	vector<vector<int>> adjlist;									//adjacency list
	vector<int> depth;												//depth of node (root is 0)

	// vector<vector<int>>up; 										//for binary lifting


	// vector<int> bigchild;										//largest subtree, -1 if leaf
	// vector<int> top;												//topmost node of the heavy path

	// vector<int> euler_tour;										//euler tour
	// int tour_iterator;
	// vector<pll> tour_indexes;

	int dfs(int src, int par)
	{
		// tour_indexes[src].first = tour_iterator;     			//EULER TOUR
		// euler_tour.push_back(src);
		// tour_iterator++;

		if (par == -1) depth[src] = 0;
		else depth[src] = depth[par] + 1;

		parent[src] = par;

		int big = -1; int subtree_size = 1;
		for (auto neighbour : adjlist[src])
		{
			if (neighbour != par) {
				int sz = dfs(neighbour, src);

				// if (sz > big)									//HLD
				// {
				// 	big = sz;
				// 	bigchild[src] = neighbour;
				// }

				subtree_size += sz;
			}
		}

		// tour_indexes[src].second = tour_iterator - 1;			//EULER TOUR

		return subtree_size;
	}

	// void dfsHLD(int src, int par, int Top)						//HLD
	// {

	// 	//If you need to build a segment tree, then keep a vector and push it here
	// 	// Build segment tree on that vector

	// 	top[src] = Top;
	// 	if (bigchild[src] != -1)
	// 		dfsHLD(bigchild[src], src, Top);

	// 	for (auto neighbour : adjlist[src])
	// 	{
	// 		if (neighbour != bigchild[src] && neighbour != par)
	// 			dfsHLD(neighbour, src, neighbour);
	// 	}
	// }

	// void binary_lifting()										//LCA Binary Lifting
	// {
	// 	for (int i = 1; i <= n; i++)
	// 		up[i][0] = parent[i];

	// 	for (int l = 1; l < LOG; l++)
	// 	{
	// 		for (int i = 1; i <= n; i++)
	// 		{
	// 			if (up[i][l - 1] != -1)
	// 				up[i][l] = up[up[i][l - 1]][l - 1];
	// 		}
	// 	}
	// }

	// int walk(int node, int k)
	// {
	// 	int i = 0;
	// 	while (k > 0)
	// 	{
	// 		if (k & 1)
	// 			node = up[node][i];
	// 		i++; k >>= 1;
	// 		if (node == -1) break;
	// 	}
	// 	return node;
	// }

	// int lca(int a, int b)
	// {
	// 	int da = depth[a], db = depth[b];
	// 	int diff = abs(da - db);

	// 	if (da > db) a = walk(a, diff);
	// 	else b = walk(b, diff);

	// 	if (a == b)
	// 		return a;

	// 	for (int i = LOG - 1; i >= 0; i--)
	// 	{
	// 		int pa = walk(a, (1 << i));
	// 		int pb = walk(b, (1 << i));
	// 		if (pa != pb)
	// 		{
	// 			a = pa; b = pb;
	// 		}
	// 	}
	// 	return up[a][0];
	// }

	Tree(int n, int LOG = 21)
	{
		this->LOG = LOG;
		this->n = n;
		parent = vector<int>(n + 1);
		adjlist = vector<vector<int>>(n + 1);
		depth = vector<int>(n + 1);

		// for Binary Lifting
		// up = vector<vector<int>>(n + 1, vector<int>(LOG, -1));

		// for Heavy Light Decomposition
		// top = vector<int>(n + 1);
		// bigchild = vector<int>(n + 1, -1);

		//for Euler Tours
		// tour_indexes = vector<pll>(n + 1);
	}

	void _init(int root = 1)
	{
		dfs(root, -1);

		// dfsHLD(root,-1,root);

		// binary_lifting();
	}

	void addedge(int a, int b)
	{
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
};