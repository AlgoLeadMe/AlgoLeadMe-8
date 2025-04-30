#include <vector>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* removeList = new ListNode();
        ListNode* removeHead;
        unordered_map<int, bool> um;

        for (int& val : nums) um[val] = true;

        removeList->next = head;
        removeHead = removeList;

        while (removeHead->next)
        {
            if (um[removeHead->next->val] == true) removeHead->next = removeHead->next->next;
            else removeHead = removeHead->next;
        }

        return removeList->next;
    }
};