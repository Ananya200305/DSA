class Solution:
    def beauty(self, freq: List[int]) -> int:
        minFreq = float('inf')
        maxFreq = float('-inf')

        for i in range(len(freq)):
            if freq[i] > 0:
                if freq[i] < minFreq:
                    minFreq = freq[i]
                if freq[i] > maxFreq:
                    maxFreq = freq[i]
        
        return maxFreq - minFreq

    def beautySum(self, s: str) -> int:
        total = 0
        for i in range(len(s)):
            freq = [0]*26
            for j in range(i, len(s)):
                freq[ord(s[j]) - ord('a')] += 1
                total += self.beauty(freq)

        return total
