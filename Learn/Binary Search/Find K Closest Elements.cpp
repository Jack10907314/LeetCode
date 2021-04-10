class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
		if (x <= arr[0]) 
        {
            for(int i = 0 ; i < k ; ++i)
                ans.push_back(arr[i]);
            return ans;
        }
        if (arr[n-1] <= x) 
		{
            for(int i = n-k ; i < n ; ++i)
                ans.push_back(arr[i]);
            return ans;
        }
        
        //find arr.indexOf(x)
        long long left = 0;
        long long right = arr.size()-1;
        while(left+1 < right)
        {
            long long middle = (right+left)/2;
            if(arr[middle] == x)
            {
                left = middle;
                break;
            }
            if(arr[middle] < x)
                left = middle;
            else
                right = middle;
        }
        
        long long index = left;
        left = index;
        right = index+1;
        for(int i = 0; i < k;++i)
        {
            if(left == -1)
                ++right;
            else if(right == n)
                --left;
            else if(abs(arr[left]-x) <= abs(arr[right]-x))
                --left;
            else
                ++right;
        }
        for(int i = left+1 ; i < right ; ++i)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};