#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

class solution {
public:
	void Sort(vector<int>& nums) {
		HeapSort(nums);
	}
	void HeapSort(vector<int>& nums) {
		for (int i = (nums.size() - 1) / 2; i >= 0; i--) 
			HeapAdjust(nums, i, nums.size() - 1);

		for (int i = nums.size() - 1; i >= 0; i--) {
			swap(nums[0], nums[i]);
			HeapAdjust(nums, 0, i - 1);
		}
	}

	void HeapAdjust(vector<int>& nums, int s, int m) {
		int rc = nums[s];

		for (int j = s == 0 ? 1 : 2 * s; j <= m; j *= 2) {
			if (j < m && nums[j] < nums[j + 1]) j++;
			if (nums[j] < rc ) break;

			nums[s] = nums[j];
			s = j;
		}
		nums[s] = rc;
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

	solution ss;
	ss.Sort(nums);

	for (int i = 0; i < nums.size(); i++) 
		cout << nums[i] << ' ';
	cout << endl;

	return 0;
}