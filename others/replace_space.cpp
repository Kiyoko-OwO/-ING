#include <cstring>
#include <algorithm>
#include <iostream>



class Solution {
public:
	void replaceSpace(std::string s,int length) {
        int i = 0;
        while((i = s.find(' ',i))>-1){
            s.erase(i,1);
            s.insert(i,"%20");
             
        }
        std::cout << s << std::endl;
	}
};

auto main() -> int {
    std::string s;
    auto test = Solution();
    getline(std::cin, s);
    test.replaceSpace(s, s.length());

    return 0;
}