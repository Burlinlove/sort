#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void Sort(vector<int>& nums) {
		InsertSort(nums);
	}

	void InsertSort(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				int t = nums[i];

				int j = i - 1;
				for (; j >= 0; j--) {
					nums[j + 1] = nums[j];
					if (nums[j] < t) break;
				}

				nums[j + 1] = t;
			}
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

	Solution ss;
	ss.Sort(nums);
	for (const auto num : nums)
		cout << num << ' ';
	cout << endl;

	return 0;
}