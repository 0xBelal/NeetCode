// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l=0,r=numbers.size()-1,sum = target -1;

        while( sum != target && l < r){
            sum = numbers[l] + numbers[r];

            if(sum > target) r--;
            else if(sum < target)  l++;

        }

        return {l+1,r+1};
    }
};

/*
O(n)
- Time Complexity: O(n)
- Space Complexity: O(n) – needs extra hash map
- Doesn’t take advantage of the sorted array
- May return wrong results if the same number is used twice


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int,int> num_index;
        for(int i=0;i<numbers.size();i++){
            num_index[numbers[i]] = i;
        }
        int start = 0,find_ = target -1;

        while( start < numbers.size() ){

            find_ = target - numbers[start];

            if(num_index.count(find_)) break;

            start++;
        }

        return {start+1,num_index[find_]+1};
    }
};
 */