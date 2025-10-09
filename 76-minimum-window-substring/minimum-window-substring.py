class Solution:
    def minWindow(self, s: str, t: str) -> str:
        stringT = defaultdict(int)

        for i in range(len(t)):
            stringT[t[i]] += 1
        
        have = 0
        need = len(stringT)
        minLen = float('inf')
        left = 0
        minstart = 0

        window = defaultdict(int)

        for right in range(len(s)):
            c = s[right]
            window[c] += 1

            if c in stringT and stringT[c] == window[c]:
                have += 1
            
            while have == need:
                if minLen > (right - left + 1):
                    minLen = (right - left + 1)
                    minstart = left
                    
                remove = s[left]
                window[remove] -= 1
                if remove in stringT and window[remove] < stringT[remove]:
                    have -= 1
                left += 1
        
        return "" if minLen == float('inf') else s[minstart: minLen+minstart]