int crossProduct(vector<int> vect_A, vector<int> vect_B)       		//return the cross product of two vectors
{
	vector<int> cross_P(3, 0);
	cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
	cross_P[1] = vect_A[2] * vect_B[0] - vect_A[0] * vect_B[2];
	cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
	return cross_P[2];												//we only need the sign of z coordinate
}

vector<pair<int, int>> convex_hull(vector<pair<int, int>> &points)	//returns vector of points of convex hull
{
	int n = points.size();
	sort(points.begin(), points.end());
	vector<pll> upper_half, bottom_half;

	upper_half.pb(points[0]);
	bottom_half.pb(points[0]);


	for (int i = 1; i < n; i++)
	{
		int cp = crossProduct({points[n - 1].F - points[0].F, points[n - 1].S - points[0].S, 0}, {points[i].F - points[0].F, points[i].S - points[0].S, 0});
		if (cp > 0 || i == n - 1)
		{
			while (upper_half.size() >= 2)
			{
				if (crossProduct({upper_half[upper_half.size() - 1].F - upper_half[upper_half.size() - 2].F, upper_half[upper_half.size() - 1].S - upper_half[upper_half.size() - 2].S, 0}, {points[i].F - upper_half[upper_half.size() - 1].F, points[i].S - upper_half[upper_half.size() - 1].S, 0}) < 0)
					break;
				upper_half.pop_back();
			}
			upper_half.pb(points[i]);
		}
		if (cp < 0 || i == n - 1)
		{
			while (bottom_half.size() >= 2)
			{
				if (crossProduct({bottom_half[bottom_half.size() - 1].F - bottom_half[bottom_half.size() - 2].F, bottom_half[bottom_half.size() - 1].S - bottom_half[bottom_half.size() - 2].S, 0}, {points[i].F - bottom_half[bottom_half.size() - 1].F, points[i].S - bottom_half[bottom_half.size() - 1].S, 0}) > 0)
					break;
				bottom_half.pop_back();
			}
			bottom_half.pb(points[i]);
		}
	}
	vector<pll> convex_hull_points;
	for (auto it : upper_half) {
		convex_hull_points.pb(it);
	}
	for (auto it : bottom_half) {
		convex_hull_points.pb(it);
	}

	sort(convex_hull_points.begin(), convex_hull_points.end());

	convex_hull_points.resize(unique(convex_hull_points.begin(), convex_hull_points.end()) - convex_hull_points.begin());	//removes duplicates
	return convex_hull_points;
}