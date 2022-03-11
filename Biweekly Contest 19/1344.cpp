class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min=minutes*6;
        // for 1 minutes (min) pin moves by 6 degree.
        double hr=hour*30+(double)minutes/2.0;
        // for 1 minutes (hour) pin moves by 0.5 degree.
        // for 1 hours {hour} pin moves by 30 degree.
        double diff=abs(hr-min);
            if(diff>360-diff)
                diff=360-diff;
        return diff;
    }
};