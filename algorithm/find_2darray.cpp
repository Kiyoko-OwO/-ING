#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>


class Solution {
    public:
        auto find(int v, std::vector<std::vector<int>> array) -> bool {
            auto row = array.size();
            if (row == 0)  return false;
            auto col = array[0].size();
            if (col == 0) return false;
            if (row == 1 && col == 1)    return array[0][0] == v;

            int i = 0;
            int j = col - 1;
            while (i < row && j >= 0) {
                if (array[i][j] > v) {
                    j--;
                } else if (array[i][j] < v) {
                    i++;
                } else {
                    return true;
                }
            }

            return false;
        }

        auto test () -> void {
            auto test = std::vector<std::vector<int>>();
            auto in1 = std::vector<int>{1, 2, 3, 4};
            auto in2 = std::vector<int>{2, 3, 4, 5};
            auto in3 = std::vector<int>{3, 4, 5, 6};
            auto in4 = std::vector<int>{4, 5, 6, 7};

            test.emplace_back(in1);
            test.emplace_back(in2);
            test.emplace_back(in3);
            test.emplace_back(in4);

            assert(find(1, test) == true);
            assert(find(11, test) == true);

            auto test2 = std::vector<std::vector<int>>();
            assert(find(0, test2) == false);
            test2.emplace_back(std::vector<int>());
            assert(find(0, test2) == false);

            test2.emplace_back(std::vector<int>{1});
            assert(find(0, test2) == false);
            assert(find(1, test2) == true);

        }
};

auto main() -> int {
    auto ans = Solution();
    ans.test();

    return 0;
}