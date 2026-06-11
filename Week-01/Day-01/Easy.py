# Two-Sum 
class Solution: 
    # --------------- Two Sum ---------------
    def twoSum(self, nums: list[int], target: int) -> list[int]:  # Time Complexity: O(n^2) Space Complexity: O(1)
        sum = 0
        start = end = -1  
        for i in range(len(nums)):
            start = i 
            for j in range( i+1 ,len(nums)):
                sum = nums[i]
                sum += nums[j]
                print(f"i = {i}, j = {j}, sum = {sum}\n")
                if(sum == target):
                    end = j
                    return [start,end]

    #   --------------- Contains Duplicate ---------------
    def containsDuplicate(self, nums: list[int]) -> bool: #  Time Complexity: O(n^2) Space Complexity: O(1)
        count = 0 
        target = 0
        for i in range(len(nums)):
            target = nums[i]
            count = 0
            for j in range(i,len(nums)):
                if nums[j] == target:
                    count += 1
                    if (count == 2):
                        return True
        return False
    def containsDuplicate(self, nums: list[int]) -> bool: # Time Complexity: O(n) Space Complexity: O(n)
        h_set = set()
        for i in nums:
            if i in h_set:
                return True
            else:
                h_set.add(i)
        return False
    
    # --------------- Valid Anagram ---------------
    def isAnagram(self, s: str, t: str):
        s = s.lower().strip()
        t = t.lower().strip()
        first_word = s.split()
        sec_word = t.split()
        for letter in first_word:
            print(f"Letter is: {letter
            }\n")
            if letter in sec_word:
                # print(f"{letter}\n")
                sec_word.remove(letter)
        if (len(sec_word) == 0) :
            return True
        return False

# --------------- Main ---------------
s1 = Solution()
#  
# nums = [3,2,3]
# target = 15
# print(f"The indices are: {s1.twoSum(nums,target)}")
# 
s = "Is"
t = "si"
print(f"Is anagram? {s1.isAnagram(s,t)}")