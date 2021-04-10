class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char a = coordinates[0];
        char b = coordinates[1];
        if((a-'a'+b-'1')%2 == 0 )
            return false;
        return true;
    }
};