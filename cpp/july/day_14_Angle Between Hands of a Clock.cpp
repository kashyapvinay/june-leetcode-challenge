class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12){
            hour = 0;
        }
        double angle_h, angle_m, ans;
        angle_h = hour * 30.0 + minutes / 2.0;
        angle_m = minutes * 6.0;
        ans = abs(angle_h - angle_m);
        return 360.0 - ans > ans ? ans : 360.0 - ans;
    }
};
