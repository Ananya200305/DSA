class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and (x % 10) == 0):
            return False

        reverse = 0
        copy = x

        while copy:
            rem = copy % 10
            reverse = reverse * 10 + rem
            copy = copy // 10

        return True if x == reverse else False