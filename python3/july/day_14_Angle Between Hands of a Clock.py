class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        if(hour == 12):
            hour = 0

        angle_h = hour * 30.0 + minutes / 2.0
        angle_m = minutes * 6.0
        ans = abs(angle_h - angle_m)
        return ans if 360.0 - ans > ans  else 360.0 - ans
