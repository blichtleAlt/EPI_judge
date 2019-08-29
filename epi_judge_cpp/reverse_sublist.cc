#include "list_node.h"
#include <vector>
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  // TODO - you fill in here.
    auto front_copy = L;

    std::vector<int> temp;
    temp.resize(finish - start);

    for(int i = 0; i < 0; ++i){
      temp[i] = L->data;
      L = L->next;
    }
    L = front_copy;

    front_copy = L;

    for(int i = temp.size() -1; i >= 0; --i){
      L->data = temp[i];
      L = L->next;
    }

    return front_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
