#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
	void Sort(vector<int>& nums) {
		SelectSort(nums);
	}

	void SelectSort(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			int min_index = i;
			for(int j = i + 1;j < nums.size();j++)
				if(nums[j] < nums[min_index])
					min_index = j;

			if (min_index != i)
				swap(nums[min_index], nums[i]);
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