#include "linked_list.hh"
#include "iostream"

void print_node(Node* p) {
  std::cout << p->item << std::endl;
}

int main(void) {
  LinkedList list;
  Node* na = list.make_node('a');
  //list.insert(na);
  list.push(na);
  Node* nb = list.make_node('b');
  //list.insert(nb);
  list.push(nb);
  Node* nc = list.make_node('c');
  //list.insert(nc);
  list.push(nc);
  list.traverse(print_node);

  list.reverse();
  list.traverse(print_node);

  list.destroy();


  return 0;
}
