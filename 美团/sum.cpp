#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>


class Solution {
    public:
    auto outputSum(int m, int n) -> void {
		double sum = m;
        double prev = m;
        for(int counter = 1; counter < n; counter++) {
            prev = sqrt(prev);
            sum+=prev;
        }
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(2) << sum << std::endl;
    }

};






auto main()-> int {
    int m, n;
    auto test = Solution();
    while (std::cin >> m >> n) {
        test.outputSum(m, n);
    }

    return 0;
}