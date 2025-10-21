class Solution:
    def reverseWords(self, s: str) -> str:
        # ans = s[::-1]
        # res = ""

        # i = 0

        # while i < len(ans):
        #     while i < len(ans) and ans[i] == " ":
        #         i += 1
            
        #     word = ""
        #     j = i

        #     while j < len(ans) and ans[j] != " ":
        #         j += 1

        #     word += ans[i:j]
        #     word = word[::-1]
        #     res += " " + word
        #     i = j+1

        # return res.strip()

        return " ".join(s.split()[::-1])