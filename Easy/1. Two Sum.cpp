class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> map_nums;


        for(int i=0;i<nums.size();i++){
            int  diff = target - nums[i];
            if(map_nums.count(diff) ){
                return {map_nums[diff],i};
            }else {
                map_nums[nums[i]] = i;
            }
        }
        return {};
    }
};
// 2,3,4
    // use hash map to solve