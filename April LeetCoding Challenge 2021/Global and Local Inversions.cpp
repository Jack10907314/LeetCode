class Solution {
public:
    vector<int> tmp;
    bool isIdealPermutation(vector<int>& A) {
        tmp = A;
        int local = 0;
        for(int i = 0 ; i < A.size()-1; ++i){
            if(A[i]>A[i+1]){
                ++local;
            }
        }
        
        int global = mergesort(A, 0, A.size()-1);
        /*for(int i = 0; i < tmp.size(); ++i){
            cout << tmp[i] << " " ;
        }*/
        return global==local;
    }
    int mergesort(vector<int>& A, int l, int r){
        if(l == r) return 0;
        int m = (r-l)/2 + l;
        //cout << l << " " << r << endl;
        int inv_l = mergesort(A, l, m);
        int inv_r = mergesort(A, m+1, r);

        int inv_c = 0;
        int index_l = l;
        int index_r = m+1;
        int tmp_index = l;
        int A_size = m-l+1;
        while(index_l<=m || index_r<=r){
            if(index_l > m){
                tmp[tmp_index] = A[index_r];
                ++index_r;
            }
            else if(index_r > r){
                tmp[tmp_index] = A[index_l];
                ++index_l;
            }
            else{
                if(A[index_l]<=A[index_r]){
                    tmp[tmp_index] = A[index_l];
                    ++index_l;
                }
                else{
                    tmp[tmp_index] = A[index_r];
                    ++index_r;
                    inv_c += A_size - (index_l-l);
                }
            }
            
            ++tmp_index;
        }
        std::copy(tmp.begin()+l, tmp.begin()+r+1, A.begin()+l);
        /*for(int i = 0; i < A.size(); ++i){
            cout << A[i] << " " ;
        }
        cout << endl;*/
        return inv_l + inv_r + inv_c;
    }
};