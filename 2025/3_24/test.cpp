#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>

#include<unordered_map>

#include<iostream>

using namespace std;



struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    void reverseList(vector<ListNode*>& re)
    {
        re[0]->next = re[re.size() - 1];
        re[1]->next = re[re.size() - 1]->next;
        for (int i = re.size() - 1; i > 1; --i)
        {
            re[i]->next = re[i - 1];
        }
        re[0] = re[re.size() - 1];
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        vector<ListNode*> re(k + 1);
        ListNode* newnode = new ListNode(0, head);
        ListNode* cur = newnode;
        int num = 0;
        while (cur)
        {
            re[num] = cur;
            cur = cur->next;
            if (num == k)
            {
                reverseList(re);
                num = 0;
            }
            ++num;
        }
        return newnode->next;
    }
};

int main()
{
    ListNode* node1 = new ListNode(5, nullptr);
    ListNode* node2 = new ListNode(4, node1);
    ListNode* node3 = new ListNode(3, node2);
    ListNode* node4 = new ListNode(2, node3);
    ListNode* node5 = new ListNode(1, node4);
    Solution().reverseKGroup(node5, 2);
    return 0;
}