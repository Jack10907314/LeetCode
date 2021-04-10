class Solution {
public:
    
    //Disjoint Sets
    struct point
    {
        point* parent;
        int value = 0;
        point(int value) : value(value), parent(NULL) {}
        bool operator == (const int v) const
        {
            return value == v;
        }
    };
    
    point* Find(point* p)
    {
        while(p->parent != NULL)
        {
            p = p->parent;
        }
        return p;
    }
    
    void Union(point* a, point* b)
    {
        Find(b)->parent = Find(a);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int> array;
        int ans = 0;
        for(vector<int> a : intervals)
            for(int b : a)
            {
                if(find(array.begin(), array.end(), b) == array.end())
                    array.push_back(b);
            }
        vector<point> vector_p;
        for(int a : array)
        {
            point p(a);
            vector_p.push_back(p);
        }

        for(vector<int> a : intervals)
        {
            auto it1 = find(vector_p.begin(), vector_p.end(), a[0]);
            auto it2 = find(vector_p.begin(), vector_p.end(), a[1]);
            if(Find(&*it1) == NULL && Find(&*it1) == NULL)
                Union(&*it1, &*it2);
            if(Find(&*it1) == Find(&*it2))
                ++ans;
            else
                Union(&*it1, &*it2);
        }
        return ans;
    }
};