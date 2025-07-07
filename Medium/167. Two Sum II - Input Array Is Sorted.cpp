#include <iostream>


using namespace std;

int Ppartition(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low , j=high;

    while ( i < j) {

        do {
            i++;
        }while ( arr[i] <= pivot);

        do {
            j--;
        }while ( arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    //swap(arr[i], arr[j]);

    return j;
}

void quickSort(int arr[], int l, int r) {

    if(l > r) return;

    int pivot = Ppartition(arr, l, r);
    //left sort
    quickSort(arr, l, pivot);
    //right sort
    quickSort(arr, pivot+1, r);
}

int main()
{

    int arr[4] = {2,4,6,3};

    int test[] = {50,20,60,10,30,40};

    quickSort(test,0,5);

    for (int i = 0; i < 6; i++)
        cout << test[i] << ", ";

    /*
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";

        quickSort(arr, 0,n-1);

    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
        */

    /*vector<Student> students  { {"Belal",3.80} , {"Amr",4.00 } , {"Ahmed" ,3.90}};
    StudentManager student_manager(students);

    StudentsSorter students_sorter(student_manager.sts);
    student_manager.sts = students_sorter.sortByGPA();
    student_manager.Print();
    */


    return 0;
}



// O(n)
/*class Solution {
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
*/
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
