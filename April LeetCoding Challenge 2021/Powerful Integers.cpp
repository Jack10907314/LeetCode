class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        set<int> set_x;
        set<int> set_y;
        int i = 0;
        int pow_x = 0;
        int pow_y = 0;
        
        if(x == 1){
            set_x.insert(1);
        }
        else{
            while(i <= bound){
                i = pow(x, pow_x);
                set_x.insert(i);
                pow_x++;
            }
        }
        i = 0;
        if(y == 1){
            set_y.insert(1);
        }
        else{
            while(i <= bound){
                i = pow(y, pow_y);
                set_y.insert(i);
                pow_y++;
            }
        }
        
        /*for(auto it_x = set_x.begin(); it_x != set_x.end(); ++it_x){
            cout << *it_x << " ";
        }
        cout << endl;
        for(auto it_y = set_y.begin(); it_y != set_y.end(); ++it_y){
            cout << *it_y << " ";
        }
        cout << endl;*/
        
        for(auto it_x = set_x.begin(); it_x != set_x.end(); ++it_x){
            for(auto it_y = set_y.begin(); it_y != set_y.end(); ++it_y){
                if(*it_x+*it_y <= bound)
                    if( find(ans.begin(), ans.end(), *it_x+*it_y) == ans.end())
                        ans.push_back(*it_x+*it_y);
            }
        }
        
        return ans;
    }
};