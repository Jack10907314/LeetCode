class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int binary = pow(2,S.size())-1;
        vector<string> ans;
        ans.push_back(S);
        while(binary >= 0)
        {
            bool change = false;
            for(int i = 0 ; i < S.size() ; ++i)
            {
                int S_index = S.size() - i - 1;
                if( (binary>>i) & 1 == 1 )
                {
                    if( S[S_index] >= 'a' && S[S_index] <= 'z')
                    {
                        S[S_index] = S[S_index] - 'a' + 'A';
                        change = true;
                    }
                }
                else
                {
                    if( S[S_index] >= 'A' && S[S_index] <= 'Z')
                    {
                        S[S_index] = S[S_index] - 'A' + 'a';
                        change = true;
                    }
                }
            }
            if(change && find(ans.begin(),ans.end(),S)==ans.end())
                ans.push_back(S);

            --binary;
        }
        return ans;
    }
};