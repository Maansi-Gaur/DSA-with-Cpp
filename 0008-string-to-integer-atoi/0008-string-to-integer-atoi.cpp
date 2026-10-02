class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
 
        // 1. Skip spaces jo ki starting mein h
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;//i++ isliye kyunki sign ko process karne ke baad next character digit hoga.so ab number bnana padega
        }

        // 3. Build number
        long long num = 0;

        while (i < n && isdigit(s[i])) {

            num = num * 10 + (s[i] - '0');

            // 4. Check overflow
            if (num * sign > INT_MAX) {
                return INT_MAX;
            }

            if (num * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return num * sign;
    }
};