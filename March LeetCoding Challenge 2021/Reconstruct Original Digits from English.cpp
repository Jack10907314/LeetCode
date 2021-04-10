/*
zero
one
two
three
four
five
six
seven
eight
nine
*/
static constexpr pair<char, int> digChars[10] = {{'z', 0}, {'w', 2}, {'x', 6}, {'s', 7}, {'g', 8}, {'h', 3}, {'v', 5}, {'f', 4}, {'o', 1}, {'e', 9}};

static string digWord[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

class Solution {
public:
    string originalDigits(string s) {
        string ans = "";
        unordered_map<char, int> total;
        for(char& c : s){
            total[c]++;
        }
        for(auto p : digChars){
            
            int count  = total[p.first];

            if(total[p.first] > 0){
                for(char& c : digWord[p.second]){
                    total[c] -= count;
                }
                
                string add = to_string(p.second);
                for(int i = 0 ; i < count ; ++i){
                    ans.push_back(add[0]);
                }
            }
            /*cout << count << endl;
            for(auto it = total.begin(); it != total.end(); ++it){
                cout << it->first << " " << it->second << endl;
            }   
            cout << endl;*/
        }
        /*for(auto it = total.begin(); it != total.end(); ++it){
            cout << it->first << " " << it->second << endl;
        }*/
        sort(ans.begin(), ans.end());
        return ans;
    }
};