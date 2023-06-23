#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<time.h>
#include<math.h>
using namespace std;

int recursive(long position) {
	int uoc = 2;
	if (position < 3) {
		return 0;
	}
	int h;
	for (h = 2; h < sqrt(position); h++) {
		if (position % h == 0) {
			uoc+=2;
		}
	}
	if (h == sqrt(position)) {
		uoc++;
	}
	
	if (uoc % 2 == 0) {
		return recursive(--position);
	}
	else {
		return (1 + recursive(--position));
	}
}
int main() {
	int count=1;
	long N;
	cin >> N;

	clock_t start, end;
	double time_use;
	start = clock();
	count += recursive( N);
	cout << count <<endl;
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay: " << setprecision(30) << fixed << time_use;
	return 0;
	// this will be appear inly on normal branch
}