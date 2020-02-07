class Solution 
	{
	public:
		int findKthLargest(vector<int>& nums, int k) 
		{
			vector<int> temp(nums.size());
			mergeSort(nums, temp, 0, nums.size() - 1);
			return nums[k-1];

		}

		void mergeSort(vector<int> &v1, vector<int> &v2, int left, int right)
		{
			if (left < right)
			{
				int mid = left + (right - left) / 2;
				mergeSort(v1, v2, left, mid);
				mergeSort(v1, v2, mid + 1, right);
				merge(v1, v2, left, right, mid);
			}

		}

		void merge(vector<int> &v1, vector<int> &v2, int left, int right, int mid)
		{
			int l = left, r = right, m = mid + 1;
			int i = 0;
			while (l <= mid && m <= r)
			{
				if (v1[l] >= v1[m])
					v2[i++] = v1[l++];
				else
					v2[i++] = v1[m++];
			}
			while (l <= mid)
				v2[i++] = v1[l++];
			while (m <= r)
				v2[i++] = v1[m++];
			//将temp数组中排好序的元素赋值进原数组
			i = 0;
			while (left <= right)
				v1[left++] = v2[i++];
		}

	};
