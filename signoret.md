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

## 8: Check if the Sentence Is Pangram | 17/05/24 | _.
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

FACTS:
- PARAMS:
    - string with the possible pangram
- RETURN:
    - bool, true if it is a pangram
- USING:
    - a size int to know the size of the string.
    - an unordered_set of chars
- SOLVE IT:
    -First we validate that the string size is smaller than the alphabet size, if it is then we just return false.
    otherwise, we add all the characters to the unordered set, but we avoid adding duplicates, so we check if we find the element already in
    the hash before adding it. At the end, we validate that the size of the hash is not smaller than the size of the alphabet, this meaning
    that if it is bigger, then we have found a pangram.


class Solution {
public:
    bool checkIfPangram(string sentence) {
        int size=sentence.size();
        if (size<26){
            return false;
        }
        unordered_set<char> seen;
        for (char c: sentence) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
            }
        }
        if (seen.size()<26){
            return false;
        }   
        return true;
    }
};

## 9: Missing Number | 17/05/24 | _.

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

FACTS:
- PARAMS:
    - vector of integers
- RETURN:
    - an int with the missing number on the vector based on its size
- USING:
    - a size int to know the size of the string.
    - an unordered_set of integers.
- SOLVE IT:
    -First, we already know that the numbers inside the vector are not repeated, so we can add them without worrying about duplicates,
    We do a for loop and we add all the vector integers into the unordered_set. After this, we do another for loop from 0 to the vector size,
    on each iteration we see if the number is also in the unordered_set, if it is not, then we have already gotten our answer.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen;
        for (int i: nums) {
                seen.insert(i);
        }
        for (int i=0;i<=n;i++){
            if (seen.find(i) == seen.end()) {
                return i;
            }
        }
        return -1;
    }
};

## 10:  Counting Elements | 17/05/24 | _.

Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> seen;
        int ans=0;
        for(int i: arr){
            seen.insert(i);
        }
        for(int i: arr){
            if(seen.find(i+1) != seen.end()){
                ans++;
            }
        }
        return ans;
    }
};

# COUNTING EXAMPLES:
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (vector<int>& arr: nums) {
            for (int x: arr) {
                counts[x]++;
            }
        }
        
        int n = int(nums.size());
        vector<int> ans;
        for (auto [key, val]: counts) {
            if (val == n) {
                ans.push_back(key);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int findLongestSubstring(string s, int k) {
    unordered_map<char, int> counts;
    int left = 0, ans = 0;
    
    for (int right = 0; right < s.size(); right++) {
        counts[s[right]]++;
        while (counts.size() > k) {
            counts[s[left]]--;
            if (counts[s[left]] == 0) {
                counts.erase(s[left]);
            }
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> counts;
        for (char c: s) {
            counts[c]++;
        }
        
        unordered_set<int> frequencies;
        for (auto [key, val]: counts) {
            frequencies.insert(val);
        }
        
        return frequencies.size() == 1;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        
        for (int num: nums) {
            curr += num;
            ans += counts[curr - k];
            counts[curr]++;
        }
        
        return ans;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        
        for (int num: nums) {
            curr += num % 2;
            ans += counts[curr - k];
            counts[curr] += 1;
        }
        
        return ans;
    }
};

[[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
winner: 
one
more

## 11: Find Players With Zero or One Losses | 21/05/24 | _.


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // 1: make a list of the seen numbers
        // 2: make a hashmap of the looses of each seen number
        // 3: for each seen player, assign to the corresponding list by loses count

        unordered_set<int> seen;
        unordered_map<int, int> lossesCount;
        
        for (auto& match:matches) {
            seen.insert(match[0]);
            seen.insert(match[1]);
            lossesCount[match[1]]++;
        }

        vector<vector<int>> ans(2, vector<int>());
        for (auto player:seen) {
            if (lossesCount.find(player) == lossesCount.end()){
                ans[0].push_back(player);
            } else if (lossesCount[player] == 1) {
                ans[1].push_back(player);
            }
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};

## 12: Largest Unique Number | 21/05/24 | _.

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_map<int,int> repetition;
        for (int num:nums){
            seen.insert(num);
            repetition[num]++;
        }
        int ans = -1;
        for (int s:seen){
            if (repetition[s] == 1 && s>ans){
                ans = s;
            }
        }
        return ans;
    }
};

## 13: Maximum Number of Balloons | 21/05/24 | _.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_set<char> seen;
        unordered_map<char,int> repetition;
        int ans = text.size();
        string s1 = "ban";
        string s2 = "lo";
        for (char c:text){
            seen.insert(c);
            repetition[c]++;
        }
        for (char c:s1){
            if (seen.find(c) == seen.end()){
                ans = 0;
                return ans;
            }
            else if (seen.find(c) != seen.end() && ans>repetition[c]) {
                ans=repetition[c];
            }
        }
        for (char c:s2){
            if (seen.find(c) == seen.end() || repetition[c] == 1){
                ans = 0;
                return ans;
            }
            else if (seen.find(c) != seen.end() && ans>repetition[c]/2) {
                ans=repetition[c]/2;
            }
        }
        return ans;
    }
};

## 15: Ransom Note | 24/05/24 | _.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size()<ransomNote.size()){
            return false;
        }
        unordered_set<char> need;
        unordered_map<char,int> ran;
        unordered_map<char,int> mag;
        for(auto c:ransomNote){
            need.insert(c);
            ran[c]++;
        }
        for(auto c:magazine){
            mag[c]++;
        }
        for(auto c:need){
            if(mag[c]<ran[c]){
                return false;
            }
        }
        return true;
    }
};

## 16: Longest Substring Without Repeating Characters | 24/05/24 | _.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> sub;
        int ans=0;
        int actual=0;
        int p=0;
        for(auto c:s){
            while(sub.find(c)!= sub.end()){
                sub.erase(s[p]);
                p++;
                actual--;
            }
            sub[c]++;
            actual++;
            if (actual>ans){
                ans=actual;
            }
        }
        return ans;
    }
};

## 17: Middle of the Linked List | 26/05/24 | _.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

## 18: Remove Duplicates from Sorted List | 26/05/24 | _.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=head;
        ListNode* prev=nullptr;
        while(dummy != nullptr){
            if (prev!=nullptr && dummy->val==prev->val){
                prev->next=dummy->next;
                dummy=dummy->next;
            } else {
                prev=dummy;
                dummy=dummy->next;
            }
        }
        return head;
    }
};