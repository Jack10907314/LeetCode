class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<string> content;
        vector<vector<string>> tmp_ans;
        vector<vector<string>> ans;
        
        for(string& s : paths){
            int space = 0;
            bool left = false;
            bool right = false;
            int index = 0;
            string path = "";
            string file = "";
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == ' '){
                    if(space == 0){
                        space++;
                        path = s.substr(0, i);
                        //cout << "path: " << path <<endl;
                        index = i+1;
                    }
                    else{
                        index = i+1;
                    }
                }
                if(s[i] == '('){
                    file = s.substr(index, i - index);
                    index = i+1;
                }
                if(s[i] == ')'){
                    string tmp_content = s.substr(index, i-index);
                    auto it = find(content.begin(), content.end(), tmp_content);
                    if(it == content.end())
                    {
                        content.push_back(s.substr(index, i-index));
                        tmp_ans.push_back({path+"/"+file});
                        //cout << path+"/"+file << endl;
                    }
                    else{
                        int where = it - content.begin();
                        tmp_ans[where].push_back(path+"/"+file);
                    }
                    //cout << "content: " << s.substr(index, i-index) << endl;
                }
            }
        }
        
        for(auto& v : tmp_ans){
            if(v.size()>1){
                ans.push_back(v);
            }
        }
        return ans;
    }
};