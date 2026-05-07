class Solution {
public:
    int hammingWeight(int n) {
        int i = 0;
        while (n)
        {
            if(n % 2 == 1){
                i++;
                
            }
            n /= 2;
        }
        return i;
    }
};