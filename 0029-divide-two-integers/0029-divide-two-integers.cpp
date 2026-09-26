class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            //temp = divisor ka kitna bada chunk subtract kar rahe hain
            long long temp = d;
            //cnt = us chunk mein divisor kitni baar hai
            long long cnt = 1;

            while (n >= (temp << 1)) {//<< 1 means multiply by 2.
                temp <<= 1;
                cnt <<= 1;
            }

            n -= temp;
            ans += cnt;
        }

        if ((dividend < 0) ^ (divisor < 0))//Agar exactly ek number negative hai, answer negative hoga.
            ans = -ans;

        if (ans > INT_MAX)
            return INT_MAX;

        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};