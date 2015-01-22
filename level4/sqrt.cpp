//sqrt

constexpr int bigroot = std::sqrt(INT_MAX);

int sqrt(int x) {
	int start = 0, end;
	end = x /2 < bigroot? x/2+1 : bigroot;
	while(start <= end){
		int mid = (start + end) /2;
		int sqr = mid*mid;
		if(sqr == x){
			return min;
		} else if (sqr < x){
			start = mid + 1
		} else {
			end = mid - 1;
		}

	}
	return (start + end)/2;; 
}

int sqrt_newton(int x) {
	
}