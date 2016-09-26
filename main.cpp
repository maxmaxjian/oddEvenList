#include <iostream>
#include <memory>
#include <vector>

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
            pNode prev, curr, lastOdd, last;
            prev = head, curr = head->next;
            int count = 2;
            while (curr->next != nullptr) {
                prev = curr;
                curr = prev->next;
                count++;
            }
            lastOdd = count%2 ? curr : prev;
            // std::cout << "lastOdd = " << lastOdd->val << std::endl;
            last = lastOdd;

            prev = head, curr = prev->next;
            while (prev != lastOdd) {
                // std::cout << "curr = " << curr->val << std::endl;
                // std::cout << "lastOdd = " << lastOdd->val << std::endl;
                prev->next = curr->next;
                curr->next = last->next;
                last->next = curr;
                last = last->next;
                prev = prev->next;
                curr = prev->next;
            }
            return head;
        }
};

void print(const pNode &head)
{
    pNode curr = head;
    while (curr->next != nullptr)
    {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << curr->val << std::endl;
}

void addToTail(pNode &head, int xval)
{
    if (head == nullptr)
    {
        head = std::make_shared<ListNode>(xval);
    }
    else
    {
        pNode curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = std::make_shared<ListNode>(xval);
    }
}

int main() {
    // std::vector<int> nums{1,2,3,4,5};
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    pNode head;
    for (auto i : nums) {
        addToTail(head, i);
    }
    std::cout << "Before swapping:\n";
    print(head);

    solution soln;
    soln.oddEvenList(head);
    std::cout << "After swapping:\n";
    print(head);
}