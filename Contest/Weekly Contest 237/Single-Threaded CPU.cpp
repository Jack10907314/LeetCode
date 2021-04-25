class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<p, vector<p>, greater<p> > map;
        vector<size_t> idx = sort_indexes(tasks);
        sort(tasks.begin(), tasks.end());

        int index = 0;
        long long nowtime = tasks[0][0];
        vector<int> ans;
        
        while(index < tasks.size() || !map.empty()){
            /*cout << "nowtime: " << nowtime << endl;
            if(index < tasks.size())
            cout << "next tasks: " <<tasks[index][0]<<endl;*/
            if(index < tasks.size() && nowtime < tasks[index][0] && map.empty()){
                nowtime = tasks[index][0];
            }
            //cout << "nowtime: " << nowtime << endl;
            while(index < tasks.size() && tasks[index][0] <= nowtime){
                map.push(make_pair(tasks[index][1], idx[index]));
                index++;
                //cout << "index: "<< index << endl;
            }
            if(!map.empty()){
                auto pp = map.top();
                map.pop();
                ans.push_back(pp.second);
                nowtime += pp.first;
                //cout << "add: "<< nowtime << endl;
            }
        }
        
        
        return ans;
    }
    
    template <typename T>
    vector<size_t> sort_indexes(const vector<T> &v) {

      // initialize original index locations
      vector<size_t> idx(v.size());
      iota(idx.begin(), idx.end(), 0);

      // sort indexes based on comparing values in v
      sort(idx.begin(), idx.end(),
           [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

      return idx;
    }
};