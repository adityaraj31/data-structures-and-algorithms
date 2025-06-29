class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
private:
    // Helper function to count the number of subarrays with sum at most the given goal
    int slidingWindowAtMost(vector<int> &nums, int goal){
        int l=0, r=0, sum=0, count=0;

        while( r < nums.size()) {
            sum = sum + nums[r];
            while(sum > goal && r>=l) {
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
};