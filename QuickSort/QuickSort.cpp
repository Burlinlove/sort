#include<vector>
#include<iostream>
using namespace std;

class Solution{

public:
	void Sort(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
	}

	void QuickSort(vector<int>& nums, int low, int high) {
		if (low < high) {
			int pivot = nums[high];
			int i = low - 1;
			for (int j = low; j < high; j++)
				if (nums[j] < nums[high])
					swap(nums[++i], nums[j]);

			swap(nums[i + 1], nums[high]);

			QuickSort(nums, low, i);
			QuickSort(nums, i + 2, high);
		}
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
	
	Solution method;
	method.Sort(nums);

	for (const auto num : nums)
		cout << num << ' ';
	cout << endl;
	
	return 0;
}