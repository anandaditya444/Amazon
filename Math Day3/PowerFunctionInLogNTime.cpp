Time - LogN as we divide the problem in 2 halves at
every step


#define ll long long int
class Solution {
public:
    double myPow(double x, ll n) {
        if (x == 0)
            return x;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        if (n & 1)
            return x * myPow(x * x, n / 2);
        else
            return myPow(x * x, n / 2);
    }
};