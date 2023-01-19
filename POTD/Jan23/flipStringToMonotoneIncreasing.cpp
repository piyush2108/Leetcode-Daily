Date: 17th Jan, 2023

Problem: https://leetcode.com/problems/flip-string-to-monotone-increasing/

Solution -->
class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int count_1 = 0;
        int count_flip = 0;

        for(auto it: s){
            if(it == '1'){
                count_1++;
            }
            else{
                count_flip++;
                count_flip = min(count_1, count_flip);
            }
        }

        return count_flip;
    }
};