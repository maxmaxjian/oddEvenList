#include <iostream>
#include <memory>

class ListNode {
    public:
        int val;
        std::shared_ptr<ListNode> next;

        ListNode(int a_val, const std::shared_ptr<ListNode> & node = nullptr) : val(a_val), next(node)
        {
        }
};

using pNode = std::shared_ptr<ListNode>;

class solution {
    public:
        pNode oddEvenList(const pNode & head) {
            
        }
};