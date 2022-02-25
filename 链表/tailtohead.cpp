
#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

class Solution {
public:
    auto printAns(std::vector<int> ans) -> void {
        for(const int& k : ans) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
        
    }
    auto printListFromTailToHead(Node *head) -> std::vector<int> {
        auto ans = std::vector<int>();
        if (head == nullptr)    return ans;
        if (head->next == nullptr) {
            ans.emplace_back(head->val);
            return ans;
        }
        

        auto curr = head;
        Node* prev = nullptr;
        auto next = head; 
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;  
            prev = curr;
            curr = next;
        }

        while (prev != NULL) {
            ans.emplace_back(prev->val);
            prev = prev->next;
        }
        return ans;
    }

    auto test() -> void {
        auto one = new Node;
        one->val = 1;
        printAns(printListFromTailToHead(one));
        auto two = new Node;
        two->val = 2;
        two->next = one;
        printAns(printListFromTailToHead(two));
        auto three = new Node;
        three->val = 3;
        three->next = one;
        printAns(printListFromTailToHead(three));


        printAns(printListFromTailToHead(nullptr));

        delete(one);
        delete(two);
        delete(three);
    }
};

auto main() -> int {
    auto ans = Solution();

    ans.test();
    return 0;
}