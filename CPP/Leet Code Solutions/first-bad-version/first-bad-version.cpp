bool isBadVersion(int version);
class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long l = 1, r = n, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int checkbad = isBadVersion(mid);
            if (checkbad == true && isBadVersion(mid - 1) == false)
            {
                return mid;
            }
            else if (checkbad == false)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return 0;
    }
};