#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};
node *head = NULL;

void insertNode(int value);        // insert at end
void printAllNodes();              // print all the nodes data
void deleteNode(int value);        // to delete node
void insertAtbeginning(int value); // insert at beginning
void del_at_beg();                 // delete at the beginning
void del_at_end();                 // delete at end

int main() {
  insertNode(1);
  insertNode(2);
  insertNode(3);
  printAllNodes();

  return 0;
}

void insertNode(int value) {
  node *new_node, *last;
  new_node = new node;
  new_node->data = value;
  if (head == NULL) {
    head = new_node;
    new_node->next = NULL;
  } else {
    last = head;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = new_node;
    new_node->next = NULL;
  }
}

void printAllNodes() {
  node *current_node;
  if (head == NULL) {
    cout << "Linked list is empty..." << endl;
  } else {
    current_node = head;
    while (current_node != NULL) {
      cout << current_node->data << "\t";
      current_node = current_node->next;
    }
  }
  cout << endl;
}

void deleteNode(int value) {
  node *current, *prev;
  current = head;
  prev = head;
  if (current->data == value) {
    head = current->next;
    free(current);
    return;
  }

  while (current->data != value) {
    prev = current;
    current = current->next;
  }
  prev->next = current->next;
  free(current);
}

void insertAtbeginning(int value) {
  node *new_node;
  new_node = new node;
  new_node->data = value;
  new_node->next = head;
  head = new_node;
}

void del_at_beg() {
  node *first_node;
  first_node = head;
  if (head == NULL) {
    cout << "Linked list is empty..." << endl;
  } else {
    head = first_node->next;
    delete (first_node); // or use  << free(first_node); >> it's the same.
  }
}

void del_at_end() {
  if (head == NULL) {
    cout << "Linked list is empty..." << endl;
  } else if (head->next == NULL) {
    delete (head);
    head = NULL;
  } else {
    node *ptr = head;
    while (ptr->next->next != NULL) {
      ptr = ptr->next;
    }
    delete (ptr->next);
    ptr->next = NULL;
  }
}
