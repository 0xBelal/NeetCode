
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid,sum=0;
        // -1,0,3,5,9,12
        //         L   r
        //  0  1 2 3 4 5

        while(l<=r){

            mid = l + (r-l)/2;

            if (mid == target) return mid;
            if(mid > target) r = mid-1;
            else if(mid < target) l = mid+1;

        }

        return -1;
    }
};
