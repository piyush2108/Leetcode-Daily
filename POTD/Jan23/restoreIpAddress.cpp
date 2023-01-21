Date: 21th Jan, 2023

Problem: https://leetcode.com/problems/restore-ip-addresses/

Solution -->
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;

        for(int i=1; i<4 && i<n; i++){
            for(int j=i+1; j<i+4 && j<n; j++){
                for(int k=j+1; k<j+4 && k<n; k++){

                    string segment1 = s.substr(0, i);
                    string segment2 = s.substr(i, j-i);
                    string segment3 = s.substr(j, k-j);
                    string segment4 = s.substr(k);

                    if(check(segment1) && check(segment2) && check(segment3) && check(segment4)){
                        ans.push_back(segment1 + '.' + segment2 + '.' + segment3 + '.' + segment4);
                    }
                }
            }
        }

        return ans;
    }

    bool check(string segment){
        if(segment.size() > 3 || segment.size() == 0 || (segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255){
            return false;
        }

        return true;
    }
};