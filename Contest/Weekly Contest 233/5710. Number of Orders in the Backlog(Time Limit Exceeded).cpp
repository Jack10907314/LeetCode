class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        /*multiset<pair<int, long>> sell;
        multiset<pair<int, long>> buy;
        map<int, long> test;
        test.insert(make_pair(2,1));
        test.insert(make_pair(1,1));
        for(auto it = test.begin(); it != test.end() ; ++it)
        {
            it->second = 3;
            cout << it->first << endl;
            cout << it->second << endl;
        }*/
        multimap<int, long> sell;
        multimap<int, long> buy;

        //sell.insert(make_pair(2,1));
        //sell.insert(make_pair(0,1));
        
        for(int i = 0 ; i < orders.size(); ++i)
        {
            if(orders[i][2] == 0)
            {
                for(auto it = sell.begin(); it != sell.end() ; ++it)
                {
                    if(it->first <= orders[i][0])
                    {
                        if(it->second <= orders[i][1])
                        {
                            orders[i][1] -= it->second;
                            it->second = 0;
                        }
                        else
                        {
                            it->second -= orders[i][1];
                            orders[i][1] = 0;
                            break;
                        }
                    }
                }
                
                if(orders[i][1] != 0)
                    buy.insert(make_pair(orders[i][0],orders[i][1]));
            }
            
            else
            {
                for(auto it = buy.rbegin(); it != buy.rend() ; ++it)
                {
                    if(it->first >= orders[i][0])
                    {
                        if(it->second <= orders[i][1])
                        {
                            orders[i][1] -= it->second;
                            it->second = 0;
                        }
                        else
                        {
                            it->second -= orders[i][1];
                            orders[i][1] = 0;
                            break;
                        }
                    }
                }
                
                if(orders[i][1] != 0)
                    sell.insert(make_pair(orders[i][0],orders[i][1]));
            }
        }
        long ans = 0;
        
        //cout << "buy" << endl;
        for(auto it = buy.begin(); it != buy.end() ; ++it)
        {
            //cout << it->first << " " << it->second << endl;
            ans += it->second;
        }
        //cout << "sell" << endl;
        for(auto it = sell.begin(); it != sell.end() ; ++it)
        {
            //cout << it->first << " " << it->second << endl;
            ans += it->second;
        }
        
        return ans%(long)(1e9+7);
    }
};