//
// Created by Belal on 06-May-25.
//
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> result(n);

        //  prefix product
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        //  suffix product
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};


// O(n)
/*

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1,2,3,4]
        // []
        int multi = 1;
        vector<int> suffix(nums.size()),res(nums.size(),0);
        int zeros = 0;

        for(int i=0;i<nums.size();i++){
            if (nums[i] == zeros ){
                zeros++;
                if(zeros > 1) return res;
                continue;
            }
            multi *= nums[i];
            suffix[i] = multi;
        }

        for(int i=0;i<nums.size();i++){

            if(!zeros){
                res[i] = suffix[nums.size()-1]/nums[i];
            }else{
                res[i] = (nums[i] == 0) ? suffix[nums.size()-1] : 0;
            }

        }

        return res;
    }
};
 * */