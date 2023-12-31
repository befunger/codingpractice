# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*Given an unsorted array, there exists some shortest subarray which if sorted results in the whole array being sorted
        Return the length of the shortest such subarray (length 0 if array is sorted)
        
        Approach: Find the smallest value that is out of order, as well as the largest. 
        These two values will be the furthest apart in the solved state and span the whole subarray that needs to be sorted*/
        int lowest_unsorted = 1000000;

        // Find lowest unsorted value
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                lowest_unsorted = nums[i] < lowest_unsorted ? nums[i] : lowest_unsorted;
            }
        }

        // Terminate early if whole array is already sorted.
        if(lowest_unsorted == 1000000){
            return 0;
        }

        // Find index where lowest unsorted should go
        int lowest_index;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>lowest_unsorted){
                lowest_index = i;
                break;
            }
        }

        // Find highest unsorted
        int highest_unsorted = -1000000;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                highest_unsorted = nums[i] > highest_unsorted ? nums[i] : highest_unsorted;
            }
        }

        // Find index where highest unsorted needs to go
        int highest_index;
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i]<highest_unsorted){
                highest_index = i;
                break;
            }
        }

        // Return size of sorting region
        return highest_index - lowest_index + 1;
    }
};