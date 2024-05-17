## 1: Reverse String | 13/05/24 | COMPLETED in 16min.

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Facts:
- PARAMS:
    - input string as an array of characters
- RULES:
    - solve it with O(1) extra memory, this means we should not use a new array but modify the given one.
- USING:
    - left pointer at the beginning of the array.
    - right pointer at the end of the array.
- SOLVE IT:
    - since we want to make it like a mirror, we only need to swap it until the half. This way now we swipe 
    the character where the pointerleft points to the one on the right pointer. After this, we add 1 to the left pointer and
    substract 1 from the right pointer, This way we can now invert the following characters. We repeat this but, until when?
    Imagine you need to look to the other side, to do this you should do half a lap. If you do a full lap, you will end up seeing the same side you started looking. That is why we only go until before the left and the right match or the left one passes the right one.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right){
            char tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--;
        }
    }
};

## 2: Squares of a Sorted Array | 13/05/24 | COMPLETED WITH HELP

Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Facts:
- PARAMS: 
    - integer array sorted from small to big.

- RETURN:
    - square of each number keeping the sort of small to big.

- USING:
    - Utilize 2 pointers, one at each corner of the array.
    - Utilize another int vector to store the results, it should be the same size as the received one since it will store the same numbers but squared 
    and rearranged.

- SOLVE IT:
    - Since on both ends, the values are the biggest (biggest of the signed and biggest of the unsigned),
    then we know that when we square them, they are all going to be unsigned, then we can now access the only 2 
    possible options of the biggest number. By comparing te absolutes of them, we now know which one will be bigger when squared,
    and we can now square it and add it to our new answer vector. But where?, well we need the answer to be sorted from smallest to biggest,
    and we know the biggest, so we add it at the end. Then we move the pointer depending on which one was the biggest, the one at the left or the one at the right. If it was the left one we add 1 to it so it now points to the following biggest signed number. If it was the right one, we substract
    one to point to the following biggest unsigned number. We repeat this until there are no more places to fill on the answer vector.

- Solution using c++:

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ans(nums.size());
        for (int i=ans.size()-1; i>=0; i--){
            if (abs(nums[left])>abs(nums[right])){
                ans[i]=nums[left]*nums[left];
                left++;
            } else {
                ans[i]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};

## 3: Maximum Average Subarray 1 | 14/05/24 | _.

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

FACTS:
- PARAMS: 
    - array of nums.
    - integer k which is the ammount of numbers that should be considered to take the average.
- RETURN:
    - double number with the max average.
- USING:
    - a prefix sum instead of the original vector
    - a double ans to track the max answer.
    - a left pointer.
    - a right pointer.
- SOLVE IT:
    - first we do a prefix sum using the same memory that the nums vector uses,
    then we initialize the answer to be at least the kth value in this prefixed vector.
    then we initialize the pointers, the right one to the next max value that is gonna be read 
    and the left pointer pointing to the value that is before the window considered, this is used to be 
    able to delete a value to the right pointer, this way obtaining the total sum at this point.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int used = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[right]==0){
                if (used < k){
                    used++;
                } else {
                    while(nums[left]==1 && left<right){
                        left++;
                    }
                    left++;
                }
            }
            if (right-left+1>ans){
                ans = right-left+1;
            }
            right++;
        }
        return ans;
    }
};

## 4: Max Consecutive Ones 111 | 14/05/24 | _.

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

FACTS:
- PARAMS:
    - array of binary numbers
    - int k which indicates the ammount of 0s that can be flipped.
- RETURN:
    - a int value that shows the max amount of numbers that are 1s or 1s and 2 flipped 0s.
- USING:
    - a left pointer initialized at the beginning.
    - a right pointer initialized at the beginning.
    - an ans int to store the actual max ammount.
    - a used int variable to store the actual used or flipped 0s.
- SOLVE IT:
    - after initializing the variables, all at 0. (left ptr, right ptr, ans, used), we do a for loop 
    on which, if the number on the right pointer is a 1, it compares if the ammount of numbers used is bigger than ans, if it is, it replaces it and move the right pointer to the next place.
    Otherwise if the number on the right pointer is a 0, it checks if the 0s available are already in use, if they are not, we just add 1 to the used variable and continue with the normal process of comparing if the used numbers are the max, and moving the right pointer to the next one. But finally, we have another option, if it is a 0 on the right pointer, but the available flippable 0s are already in use, we have to make room for one more, so we iterate and 
    advance the left pointer in order to find and free 1 0 position.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int used = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[right]==0){
                if (used < k){
                    used++;
                } else {
                    while(nums[left]==1 && left<right){
                        left++;
                    }
                    left++;
                }
            }
            if (right-left+1>ans){
                ans = right-left+1;
            }
            right++;
        }
        return ans;
    }
};

## 5: Running Sum of 1d Array | 14/05/24 | _.

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

FACTS:
- PARAMS:
    - array of numbers
- RETURN:
    - array of numbers with the prefix sum.
- USING:
    - the array of numbers given.
- SOLVE IT:
    -we just do a for loop, but we initialize i at 1, this way we can always add to each position in the array, the actual ammount plus
    the accumulation from the previous number.

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};


## 6: Minimum value to get Positive Step by Step Sum | 16/05/24 | _.
Given an array of integers nums, you start with an initial positive value startValue.
In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
Return the minimum positive value of startValue such that the step by step sum is never less than 1.

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min=1;
        if(nums[0]<min){
            min=nums[0];
        }
        for (int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
            if (nums[i]<min){
                min=nums[i];
            }
        }
        if (min<1){
            return min*-1+1;
        }
        return min;
    }
};

## 7: K Radius Subarray Averages | 16/05/24 | _.
You are given a 0-indexed array nums of n integers, and an integer k.
The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.
Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.
The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.
    For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.



class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // When a single element is considered then its average will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.size();
        vector<int> averages(n, -1);

        // Any index will not have 'k' elements in it's left and right.
        if (windowSize > n) {
            return averages;
        }

        // Generate 'prefix' array for 'nums'.
        // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // We iterate only on those indices which have atleast 'k' elements in their left and right.
        // i.e. indices from 'k' to 'n - k'
        for (int i = k; i < (n - k); ++i) {
            int leftBound = i - k, rightBound = i + k;
            long long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int average = subArraySum / windowSize;
            averages[i] = average;
        }

        return averages;
    }
};