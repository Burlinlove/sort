#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
	void Sort(vector<int>& nums) {
		ShellSort(nums);
	}

	void ShellSort(vector<int>& nums) {
		int t = log(nums.size()-1) / log(2);
		vector<int> delta;
		for (int k = 0; k <= t; k++) {
			int value = pow(2, t - k) + 1;
			delta.push_back(value);
		}
		delta.push_back(1);

		for (int k = 0; k < delta.size(); k++)
			ShellInsert(nums, delta[k]);
	}

	void ShellInsert(vector<int>& nums, int dk) {
		for (int i = dk + 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - dk]) {
				int t = nums[i];

				int j = i - dk;
				for (; j >= 0; j -= dk) {
					nums[j + dk] = nums[j];
					if (nums[j] < t) break;
				}
					
				nums[j + dk] = t;
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
	ss.ShellSort(nums);

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	cout << endl;

	return 0;
}