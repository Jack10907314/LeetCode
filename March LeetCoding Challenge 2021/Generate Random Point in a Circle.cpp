class Solution {
public:
    double r;
    double x;
    double y;
    const double PI = 3.14159265358979732384626433832795;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while(1)
        {
            double rand_x = (double(rand())/RAND_MAX-0.5)*2*r;
            double rand_y = (double(rand())/RAND_MAX-0.5)*2*r;
            
            if (rand_x * rand_x + rand_y * rand_y < r * r)
                    return {x+rand_x, y+rand_y};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */