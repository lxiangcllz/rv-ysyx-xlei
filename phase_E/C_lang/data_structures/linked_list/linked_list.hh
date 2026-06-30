#ifndef _LINKED_LIST_HH
#define _LINKED_LIST_HH

struct Node {
  unsigned char item;
  Node* next;

  Node(unsigned char i) : item(i), next(nullptr) {}

};

class LinkedList {
public:
  Node* make_node(unsigned char item);
  void free_node(Node* p);
  Node* search(unsigned char key);
  void insert(Node* p);
  void remove(Node* p); // delete
  void traverse(void (*visit)(Node*));
  void destroy(void);
  void push(Node* p);
  Node* pop(void);
  void reverse(void);

private:
  Node* head = nullptr;
};


struct DNode {
  unsigned char item;
  DNode *prev, *next;
};

class DLinkedList {
public:
  void insert(DNode* p);
  void remove(DNode* p);

private:
  DNode* head = nullptr; 
};


#endif
