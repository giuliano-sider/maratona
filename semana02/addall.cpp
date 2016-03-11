// g++ -lm -lcrypt -O2 -std=c++11 

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	//vector< vector<int> > nums;

	vector<int> nums;

	while(1) {
		int N;
		scanf("%i ", &N);
		if(N == 0)
			break;
		nums.resize(N);
		for(int i = 0; i < N; i++) {
			int a;
			scanf("%i ", &a);
			nums[i] = a;
		}


		/*
		for(int i = 0; i < N; i++) {
			nums.push_back( vector<int>() );
			nums[i].resize(N); // columns
			int a;
			scanf("%i ", &a);
			nums[i] = a;
		}

		// now move bottom-up, right-left
		for(int i = N-1; i >= 0; i--) {
			for
		}
		*/


		
		sort(nums.begin(), nums.end(), [](int b, int c) -> bool { return b < c; });

		int cost = (N - 1) * (nums[0] + nums[1]); // running total of cost
		for(int j = 2; j < N; j++) {
			cost += (N - j) * nums[j];
		}
		/*
		int accumulant = nums[0]; // running total of sum
		for(int i = 1; i < N; i++) {
			cost = cost + accumulant + nums[i];
			accumulant = accumulant + nums[i];
		}
		*/

		nums.resize(0);
		

		printf("%i\n", cost);
	}






	return 0;
}