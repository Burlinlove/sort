#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
	void Sort(vector<int>& nums) {
		BubblellSort(nums);
	}

	void BubblellSort(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			bool swapped = false;
			for (int j = 0; j < nums.size() - i - 1; j++)
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
					swapped = true;
				}
			if (!swapped)
				break;
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

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	cout << endl;

	return 0;
}