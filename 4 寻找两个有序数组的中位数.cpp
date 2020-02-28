class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		if (m < n) return findMedianSortedArrays(nums2, nums1);
		int Lm1, Lm2, Rm1, Rm2, c1, c2, lo = 0, hi = 2 * n;
		while (lo<=hi)
		{
			c1 = (lo + hi) / 2;
			c2 = m + n - c1;

			Lm1 = (c1 == 0) ? INT_MIN : nums1[(c1-1)/2];
			Rm1 = (c1 == n  * 2) ? INT_MAX : nums1[c1/2];
			Lm2 = (c2 == 0) ? INT_MIN : nums2[(c2-1)/2];
			Rm2 = (c2 == m * 2) ? INT_MAX : nums2[c2/2];

			if (Lm1 > Rm2)hi = c1 - 1;
			else if (Rm1 < Lm2)lo = c1 + 1;
			else break;
		}
		return (max(Lm1, Lm2) + min(Rm1, Rm2)) / 2.0;
	}
};
