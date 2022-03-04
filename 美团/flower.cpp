#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
    public:
    auto flowers(int m, int n) -> void {
        auto exist = false;
    	for (int counter = m; counter <= n; counter ++) {
            int three = counter / 100;
            int remain = counter - three * 100;
            int two = remain / 10;
            remain = remain - two * 10;
            int one = remain;
            if ((pow(three, 3) + pow(two, 3) + pow(one, 3)) == counter) {
                std::cout << counter << std::endl;
                if (! exist)	exist = true;
            }
        }
        if (! exist) std::cout << "no" << std::endl;
    }
    
};


auto main() -> int {
    int m, n;
    auto test = Solution();
    while (std::cin >> m >> n) {
        test.flowers(m, n);
    }
    
    return 0;
}