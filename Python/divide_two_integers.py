# https://leetcode.com/problems/divide-two-integers/

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        rt =int(dividend /divisor)
        return rt if -2147483648 <= rt and rt<= 2147483647 else 2147483647