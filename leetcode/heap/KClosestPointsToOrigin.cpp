struct Point
{
    int x;
    int y;
    double distance;
    
    Point(int x, int y) : x(x), y(y)
    {
        distance = (double)x * x + (double)y * y;
    }
    
    bool operator>(const Point& p) const
    {
        return distance > p.distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, greater<Point>> pq;
        int size = (int)points.size();
        
        for (int i = 0; i < size; i++)
        {
            pq.emplace(points[i][0], points[i][1]);
        }
        
        vector<vector<int>> ans(K, vector<int>(2));
        for (int i = 0; i < K; i++)
        {
            ans[i][0] = pq.top().x;
            ans[i][1] = pq.top().y;
            pq.pop();
        }
        
        return ans;
    }
};
