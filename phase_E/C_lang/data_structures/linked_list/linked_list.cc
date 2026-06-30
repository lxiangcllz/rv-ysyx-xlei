#include "linked_list.hh"


Node* LinkedList::make_node(unsigned char item) {
  Node* node = new Node{item};
  return node;
}

void LinkedList::free_node(Node* p) {
  if (this->head == nullptr)
    return;
  if (this->head == p) {
    Node* to_be_deleted = this->head;
    this->head = this->head->next;
    delete(to_be_deleted);
  } else {
    Node* tmp = this->head;
    while (tmp->next != nullptr) {
      if (tmp->next == p) {
        Node* to_be_deleted = tmp->next;
        tmp->next = tmp->next->next;
        delete(to_be_deleted);
      } else {
        tmp = tmp->next;
      }
    }
  }
}

Node* LinkedList::search(unsigned char key) {
  if (this->head == nullptr) {
    return nullptr;
  } else {
    Node* tmp = this->head;
    while (tmp != nullptr) {
      if (tmp->item == key) 
        return tmp;
      tmp = tmp->next;
    }
    return nullptr;
  }
}

void LinkedList::insert(Node* p) {
  p->next = this->head;
  this->head = p;
}

void LinkedList::remove(Node* p) {
  this->free_node(p);
}

void LinkedList::traverse(void (*visit)(Node*)) {
  Node* p = this->head;
  while (p != nullptr) {
    visit(p);
    p = p->next;
  }
}

void LinkedList::destroy(void) {
  while (this->head != nullptr) {
    Node* to_be_deleted = this->head;
    this->head = this->head->next;
    delete(to_be_deleted);
  }
}

void LinkedList::push(Node* p) {
  if (this->head == nullptr) {
    this->head = p;
  } else {
    Node* node = this->head;
    while (node->next != nullptr) {
      node = node->next;
    }
    node->next = p;
  }
}

Node* LinkedList::pop(void) {
  if (this->head == nullptr) {
    return nullptr;
  } else {
    Node* popped = this->head;
    this->head = this->head->next;
    return popped;
  }
}

void LinkedList::reverse(void) {
  Node* pre = nullptr;
  Node* p = this->head;
  Node* pnext;
  while (p != nullptr) {
    pnext = p->next;
    p->next = pre;
    pre = p;
    p = pnext;
  }
  this->head = pre;
}


void DLinkedList::insert(DNode* p) {
  p->next = this->head;
  if (this->head) {
    this->head->prev = p;
  }
  this->head = p;
  p->prev = nullptr;
}

void DLinkedList::remove(DNode* p) {
  if (p->prev)
    p->prev->next = p->next;
  else
    this->head = p->next;
  if (p->next)
    p->next->prev = p->prev;
  delete(p);
}











