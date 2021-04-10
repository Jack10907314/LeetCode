class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> ratio1(n, 0);
        vector<double> ratio2(n, 0);
        for(int i = 0 ; i < n; ++i)
        {
            ratio1[i] = (double)classes[i][0] / (double)classes[i][1];
            ratio2[i] = (double)(classes[i][0]+1) / (double)(classes[i][1]+1);
        }
        
        for(int i = 0; i < extraStudents; ++i)
        {
            
            double reduce = -1;
            int where = -1;
            for(int j = 0 ; j < n ; ++j)
            {
                //cout << ratio1[j] << " ";
                //cout << ratio2[j] << " ";
                if(ratio2[j]-ratio1[j] > reduce)
                {
                    where = j;
                    reduce = ratio2[j]-ratio1[j];
                }
            }
            ratio1[where] = ratio2[where];
            classes[where][0]++;
            classes[where][1]++;
            ratio2[where] = (double)(classes[where][0]+1) / (double)(classes[where][1]+1);
        }
        
        double ans = 0;
        for(int i = 0 ; i < n; ++i)
        {
            ans += ratio1[i];
            //cout << ratio2[i] << endl;
            //cout << classes[i][0] << " " << classes[i][1]<<endl;
        }
        ans = rounding(ans/n, 5);
        //int change = ans/n * pow(10,5);
        //ans = (double)change / pow(10,5);
        return ans;
    }
    // 四捨五入 取到 小數點第 X 位 
    double rounding(double num, int index)
    {
        bool isNegative = false; // whether is negative number or not

        if(num < 0) // if this number is negative, then convert to positive number
        {
            isNegative = true;	
            num = -num;
        }

        if(index >= 0)
        {
            int multiplier;
            multiplier = pow(10, index);
            num = (int)(num * multiplier + 0.5) / (multiplier * 1.0);
        }

        if(isNegative) // if this number is negative, then convert to negative number
        {
            num = -num;
        }

        return num;
    }
};