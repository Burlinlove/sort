#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void Sort(vector<int>& nums) {
		MergeSortRecursive(nums, 0, nums.size() - 1);       //递归
		//MergeSortNonRecursive(nums);                      //非递归
	}

	void MergeSortRecursive(vector<int>& nums, int left, int right) {  // 递归版本
		if (left < right) {
			int mid = (left + right) / 2;
			MergeSort(nums, left, mid);
			MergeSort(nums, mid + 1, right);
			Merge(nums, left, mid, right);
		}
	}

	void MergeSortNonRecursive(vector<int> &nums) {  // 非递归版本
		int n = nums.size();
		int s = 1;
		while (s <= n){
			int i = 0;
			while (i + 2*s - 1 < n){
				Merge(nums, i, i + s - 1, i + 2*s - 1);
				i += 2*s;
			}
			if (i + s < n)
				Merge(nums, i, i+s-1 , n - 1);
			s *= 2;
		}
	}

	void Merge(vector<int>& nums, int left, int mid, int right) {
		int num_left = mid - left + 1;
		int num_right = right - mid;

		vector<int> L(num_left, 0);
		vector<int> R(num_right, 0);

		for (int i = 0; i < num_left; i++)
			L[i] = nums[left + i];

		for (int i = 0; i < num_right; i++)
			R[i] = nums[mid + 1 + i];

		for (int i = 0, j = 0, k = left; k <= right; k++)
			if (i == num_left || j == num_right)
				nums[k] = i != num_left ? L[i++] : R[j++];
			else
				nums[k] = L[i] < R[j] ? L[i++] : R[j++];
	}
};

int main() {

	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}

	Solution ss;
	ss.Sort(nums);
	for (const auto num : nums)
		cout << num << ' ';
	cout << endl;

	return 0;
}