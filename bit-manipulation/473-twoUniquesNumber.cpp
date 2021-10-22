vector<int> singleNumber(vector<int> nums)
{
    int xorResult = nums[0];

    for (int i = 1; i < nums.size(); i++)
        xorResult ^= nums[i];

    int positionOfRightMost1 = 0;

    while ((xorResult & (1 << positionOfRightMost1)) != (1 << positionOfRightMost1))
        positionOfRightMost1++;

    // now positionOfRightMost1 has a position of right most 1 in our result 'xorResult'
    // 1 bit in xorResult implies that both nums has opposite bit at this position.
    // Lets assume that num1 has setBit at this position while num2 has 0 bit.

    // now do the xor of all array elements with our xorResult who has setBit at
    // positionOfRightMost1. In this way, those elements are repeated will get vanished
    // and we will get our first num i.e, num1

    // now to get num2, just do the xor of num1 with our previous result 'xorResult'

    int num1 = xorResult;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & (1 << positionOfRightMost1)) == (1 << positionOfRightMost1))
            num1 ^= nums[i];
    }

    int num2 = num1 ^ xorResult;

    vector<int> ans;

    ans.push_back(min(num1, num2));
    ans.push_back(max(num1, num2));

    return ans;
}