class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = __builtin_popcount(num2);
        int result = 0;

        for (int i = 31; i >= 0 && bits > 0; i--) {
            int index = 1 << i;
            if (num1 & index) {
                result |= index;
                bits--;
            }
        }

        for (int i = 0; i < 32 && bits > 0; i++) {
            int index = 1 << i;
            if (!(result & index)) {
                result |= index;
               bits--;
            }
        }

        return result;
    }
};
