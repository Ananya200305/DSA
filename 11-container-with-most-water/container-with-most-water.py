class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        water = 0

        while left < right:
            h = min(height[left], height[right])
            w = right - left
            area = h*w
            water = max(water, area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return water