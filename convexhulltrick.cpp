struct line {
	int m, c;
};
long double intersectX(line X, line Y)
{
	if (X.m == Y.m)
		return inf;
	return (double)(X.c - Y.c) / (double)(Y.m - X.m);
}

int eval(int x, line X)
{
	return X.m * x + X.c;
}

deque<line> st;
vector<long double> points;

void addline (line X)
{
	if (st.empty())
	{
		st.push_back(X);
		return;
	}
	if (st.size() == 1)
	{
		points.push_back(intersectX(X, st.back()));
		st.push_back(X);
		return;
	}
	while (points.size())
	{
		line l2 = st.back();
		st.pop_back();
		line l1 = st.back();

		if (intersectX(X, l1) > points.back()) {
			st.pb(l2);
			break;
		}
		else
		{
			points.pop_back();
		}
	}
	points.push_back(intersectX(X, st.back()));
	st.push_back(X);
}

int findbest(int x) {
	int idx = lower_bound(points.begin(), points.end(), x) - points.begin();
	return eval(x, st[idx]);
}