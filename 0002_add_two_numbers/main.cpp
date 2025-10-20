#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0); // Dummy head to simplify result list creation
    ListNode *current = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int sum = carry;

      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
    }
    return dummy.next;
  }
};

ListNode *createList(int arr[], int n) {
  ListNode *head = new ListNode(arr[0]);
  ListNode *current = head;
  for (int i = 1; i < n; i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}

void printList(ListNode *head) {
  while (head != nullptr) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int arr1[] = {2, 4, 3};
  int arr2[] = {5, 6, 4};

  ListNode *l1 = createList(arr1, 3);
  ListNode *l2 = createList(arr2, 3);

  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);

  cout << "Result: ";
  printList(result);

  return 0;
}
