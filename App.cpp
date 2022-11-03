#include <iostream>
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        // the head node has the val
        // we must update the head node
        while (head != NULL && head->val == val) 
        {
            head = head->next;
        }

        ListNode* current_node = head;

        // check for null at current node and next node
        // we want to make sure next node is not null before 
        // we check for the val
        while (current_node != NULL && current_node->next != NULL) 
        {

            if (current_node->next->val == val) 
            {

                // skip over node with val
                current_node->next = current_node->next->next;
            }
            // if the next node.val is NOT equal to val
            // keep traversing normally
            else 
            {
                current_node = current_node->next;
            }
        }

        // return head of new list
        return head;
    }
};

int main()
{
    Solution solution;

    ListNode four(4);
    ListNode second_two(2, &four);
    ListNode three(3, &second_two);
    ListNode first_two(2, &three);
    ListNode head(1, &first_two);

    ListNode *example_one = solution.removeElements(&head, 2);

    cout << "Example One : ";
    while (true) {
        cout << example_one->val << " ";

        if (example_one->next != NULL) {
            example_one = example_one->next;
        }
        else {
            break;
        }
    }
        cout << endl;
	return 0;
}

