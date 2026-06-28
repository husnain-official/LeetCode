class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = "".join(char.lower() for char in s if char.isalnum())
        length = len(s) -1 
        for i in range (length):
            if((s[i]!= s[length-i])):
                return False
        return True