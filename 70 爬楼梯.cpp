class Solution {
public:
	int climbStairs(int n) {
		int curr = 1 , onestep = 1, twostep = 1, i = 2;
		while (i++ <= n){
			curr = onestep + twostep;
			twostep = onestep;
			onestep = curr;
		}
		return curr;
	}
}; 
