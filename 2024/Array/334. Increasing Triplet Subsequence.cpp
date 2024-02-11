class Solution
{
public:
    // easy way
    // if else bss

    bool increasingTriplet(vector<int> &nums)
    {
        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            // equal to for case nums=[1,1,1] toh num1 ko hi 1 assign hote rhega and
            // loop se out return false;
            if (nums[i] <= num1)
                num1 = nums[i];
            else if (nums[i] <= num2)
                num2 = nums[i];
            else
                return true;
        }
        return false;
    }
};