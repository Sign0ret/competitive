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