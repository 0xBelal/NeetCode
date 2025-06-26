//
// Created by Belal on 26-Jun-25.
//

class Solution {
public:

    int binary_search(vector<int> arr,int key){
        int l=0,r=arr.size()-1;


        while(l<=r){

            int mid = l + (r-l)/2;

            if(arr[mid] == key ) return mid;
            else{
                if(arr[mid] > key ){
                    r = mid-1;
                } else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* get the target row
           ,then apply binary search on it
        */
        int target_row = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i< m;i++){

            if(matrix[i][0] <= target && matrix[i][n-1] >= target ){
                target_row = i;
                break;
            }

        }
        if(target_row == -1) return false;


        return (binary_search(matrix[target_row],target) != -1);

    }
};