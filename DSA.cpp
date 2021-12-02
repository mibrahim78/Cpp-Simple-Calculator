// ******************************----------Singly Linked List----------******************************



#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class SinglyLinkedList {
  public:
    Node * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }

  // 1. CHeck if node exists using key value
  Node * nodeExists(int k) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }

  // 2. Append a node to the list
  void appendNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Appended" << endl;
      }
    }

  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }

  }
  // 6th update node
  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};

int main() {

  SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}





// ******************************----------Doubly Linked List----------******************************



#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;
  Node * previous;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class DoublyLinkedList {

  public:
    Node * head;

  DoublyLinkedList() {
    head = NULL;
  }
  DoublyLinkedList(Node * n) {
    head = n;
  }

  // 1. CHeck if node exists using key value

  Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = head;

    while (ptr != NULL) {
      if (ptr - > key == k) {
        temp = ptr;
      }
      ptr = ptr - > next;
    }

    return temp;
  }

  // 2. Append a node to the list

  void appendNode(Node * n) {
    if (nodeExists(n - > key) != NULL) {
      cout << "Node Already exists with key value : " << n - > key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended as Head Node" << endl;
      } else {
        Node * ptr = head;
        while (ptr - > next != NULL) {
          ptr = ptr - > next;
        }
        ptr - > next = n;
        n - > previous = ptr;
        cout << "Node Appended" << endl;
      }
    }
  }

  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
    if (nodeExists(n - > key) != NULL) {
      cout << "Node Already exists with key value : " << n - > key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Prepended as Head Node" << endl;
      } else {
        head - > previous = n;
        n - > next = head;
        head = n;
        cout << "Node Prepended" << endl;
      }

    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n - > key) != NULL) {
        cout << "Node Already exists with key value : " << n - > key << ". Append another node with different Key value" << endl;
      } else {
        Node * nextNode = ptr - > next;
        // inserting at the end
        if (nextNode == NULL) {
          ptr - > next = n;
          n - > previous = ptr;
          cout << "Node Inserted at the END" << endl;
        }

        //inserting in between
        else {
          n - > next = nextNode;
          nextNode - > previous = n;
          n - > previous = ptr;
          ptr - > next = n;

          cout << "Node Inserted in Between" << endl;

        }

      }
    }
  }

  // 5. Delete node by unique key. Basically De-Link not delete
  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {

      if (head - > key == k) {
        head = head - > next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * nextNode = ptr - > next;
        Node * prevNode = ptr - > previous;
        // deleting at the end
        if (nextNode == NULL) {

          prevNode - > next = NULL;
          cout << "Node Deleted at the END" << endl;
        }

        //deleting in between
        else {
          prevNode - > next = nextNode;
          nextNode - > previous = prevNode;
          cout << "Node Deleted in Between" << endl;

        }
      }
    }
  }

  // 6th update node
  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr - > data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Doubly Linked List";
    } else {
      cout << endl << "Doubly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp - > key << "," << temp - > data << ") <--> ";
        temp = temp - > next;
      }
    }

  }

};

int main() {

  DoublyLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}





// ******************************----------Circular Linked List----------******************************



#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class CircularLinkedList {
  public:
    Node * head;

  CircularLinkedList() {
    head = NULL;
  }

  // 1. CHeck if node exists using key value
  Node * nodeExists(int k) {

    Node * temp = NULL;
    Node * ptr = head;

    if (ptr == NULL) {
      return temp;
    } else {
      do {
        if (ptr - > key == k) {
          temp = ptr;
        }
        ptr = ptr - > next;

      } while (ptr != head);
      return temp;
    }

    //return temp;
  }

  // 2. Append a node to the list
  void appendNode(Node * new_node) {
    if (nodeExists(new_node - > key) != NULL) {
      cout << "Node Already exists with key value : " <<
        new_node - > key <<
        ". Append another node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node - > next = head;
        cout << "Node Appended at first Head position" << endl;
      } else {
        Node * ptr = head;
        while (ptr - > next != head) {
          ptr = ptr - > next;
        }
        ptr - > next = new_node;
        new_node - > next = head;
        cout << "Node Appended" << endl;
      }
    }

  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * new_node) {
    if (nodeExists(new_node - > key) != NULL) {
      cout << "Node Already exists with key value : " <<
        new_node - > key <<
        ". Append another node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node - > next = head;
        cout << "Node Prepended at first Head position" << endl;
      } else {
        Node * ptr = head;
        while (ptr - > next != head) {
          ptr = ptr - > next;
        }

        ptr - > next = new_node;
        new_node - > next = head;
        head = new_node;
        cout << "Node Prepended" << endl;
      }

    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * new_node) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value OF: " << k << endl;
    } else {
      if (nodeExists(new_node - > key) != NULL) {
        cout << "Node Already exists with key value : " <<
          new_node - > key <<
          ". Append another node with different Key value" <<
          endl;
      } else {
        if (ptr - > next == head) {
          new_node - > next = head;
          ptr - > next = new_node;
          cout << "Node Inserted at the End" << endl;
        } else {
          new_node - > next = ptr - > next;
          ptr - > next = new_node;
          cout << "Node Inserted in between" << endl;
        }

      }
    }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value OF : " << k <<
        endl;
    } else {

      if (ptr == head) {
        if (head - > next == NULL) {
          head = NULL;
          cout << "Head node Unlinked... List Empty";
        } else {
          Node * ptr1 = head;
          while (ptr1 - > next != head) {
            ptr1 = ptr1 - > next;
          }
          ptr1 - > next = head - > next;
          head = head - > next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        }
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head - > next;
        while (currentptr != NULL) {
          if (currentptr - > key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr - > next;
            currentptr = currentptr - > next;
          }
        }

        prevptr - > next = temp - > next;
        cout << "Node UNLINKED with keys value : " << k << endl;

      }

    }

  }
  // 6th update node
  void updateNodeByKey(int k, int new_data) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr - > data = new_data;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;

      Node * temp = head;

      do {
        cout << "(" << temp - > key << "," << temp - > data << "," << temp - > next << ") --> ";
        temp = temp - > next;
      } while (temp != head);
    }

  }

};

int main() {

  CircularLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}





// ******************************----------Stack Using Arrays----------******************************



#include<iostream>

#include<string>

using namespace std;

class Stack {
  private:
    int top;
  int arr[5];

  public:
    Stack() {
      top = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }

  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }

  void push(int val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
    }
  }

  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }

  int count() {
    return (top + 1);
  }

  int peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      return arr[pos];
    }
  }

  void change(int pos, int val) {
    arr[pos] = val;
    cout << "value changed at location " << pos << endl;
  }

  void display() {
    cout << "All values in the Stack are " << endl;
    for (int i = 4; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }
};

int main() {
  Stack s1;
  int option, postion, value;

  do {
    cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. peek()" << endl;
    cout << "6. count()" << endl;
    cout << "7. change()" << endl;
    cout << "8. display()" << endl;
    cout << "9. Clear Screen" << endl << endl;

    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter an item to push in the stack" << endl;
      cin >> value;
      s1.push(value);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
      break;
    case 3:
      if (s1.isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (s1.isFull())
        cout << "Stack is Full" << endl;
      else
        cout << "Stack is not Full" << endl;
      break;
    case 5:
      cout << "Enter position of item you want to peek: " << endl;
      cin >> postion;
      cout << "Peek Function Called - Value at position " << postion << " is " << s1.peek(postion) << endl;
      break;
    case 6:
      cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
      break;
    case 7:
      cout << "Change Function Called - " << endl;
      cout << "Enter position of item you want to change : ";
      cin >> postion;
      cout << endl;
      cout << "Enter value of item you want to change : ";
      cin >> value;
      s1.change(postion, value);
      break;
    case 8:
      cout << "Display Function Called - " << endl;
      s1.display();
      break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}





// ******************************----------Stack Using Singly Linked List----------******************************



#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
    next = NULL;
  }
};

class Stack {
  public:
    Node * top;

  Stack() {
    top = NULL;
  }

  bool isEmpty() {
    if (top == NULL) {
      return true;
    } else {
      return false;
    }
  }
  bool checkIfNodeExist(Node * n) {
    Node * temp = top;
    bool exist = false;
    while (temp != NULL) {
      if (temp - > key == n - > key) {
        exist = true;
        break;
      }
      temp = temp - > next;
    }
    return exist;
  }   

  void push(Node * n) {
    if (top == NULL) {
      top = n;
      cout << "Node  PUSHED successfully" << endl;
    } else if (checkIfNodeExist(n)) {
      cout << "Node already exist with this Key value." <<
        "Enter different Key value" << endl;
    } else {
      Node * temp = top;
      top = n;
      n - > next = temp;
      cout << "Node  PUSHED successfully" << endl;
    }

  }

  Node * pop() {
    Node * temp = NULL;
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return temp;
    } else {
      temp = top;
      top = top - > next;
      return temp;
    }
  }
  Node * peek() {
    //Node *temp = NULL;
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return NULL;
    } else {
      return top;
    }
  }
  int count() {
    int count = 0;
    Node * temp = top;
    while (temp != NULL) {
      count++;
      temp = temp - > next;
    }
    return count;
  }
  void display() {
    cout << "All values in the Stack are :" << endl;
    Node * temp = top;
    while (temp != NULL) {
      cout << "(" << temp - > key << "," << temp - > data << ")" << " -> " <<
        endl;
      temp = temp - > next;
    }
    //cout<< "Total no of Nodes in the stack :" <<count()
    //<<endl;
    cout << endl;
  }

};

int main() {
  Stack s1;
  int option, key, data;

  do {
    cout << "What operation do you want to perform?" <<
      "Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. peek()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    cin >> option;

    //Node n1 = new Node();
    Node * new_node = new Node();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter KEY and VALUE of NODE to push in the stack" <<
        endl;
      cin >> key;
      cin >> data;
      new_node - > key = key;
      new_node - > data = data;
      s1.push(new_node);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << endl;
      new_node = s1.pop();
      cout << "TOP of Stack is: (" << new_node - > key << "," << new_node - > data << ")";
      delete new_node;
      cout << endl;

      break;
    case 3:
      if (s1.isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (s1.isEmpty()) {
        cout << "Stack is Empty" << endl;
      } else {
        cout << "PEEK Function Called : " << endl;
        new_node = s1.peek();
        cout << "TOP of Stack is: (" << new_node - > key << "," << new_node - > data << ")" <<
          endl;
      }
      break;
    case 5:
      cout << "Count Function Called: " << endl;
      cout << "No of nodes in the Stack: " << s1.count() << endl;
      break;

    case 6:
      cout << "Display Function Called - " << endl;
      s1.display();
      cout << endl;
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}





// ******************************----------Infix to Postfix Conversion----------******************************



#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;
  	stack <char> stack;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(stack, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  
	return 0;
}





// ******************************----------C++ program to evaluate value of a postfix expression----------******************************



#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
stack<int> s;

int main(){

    //taking user input
    string exp;
    cout<<"Enter postfix expression: ";
    cin>>exp;

    //traversing postfix expression from left to right
    for(int i=0;i<exp.length();i++){

        //if symbol is a digit push it in stack
        if (isdigit(exp[i]))
            s.push(exp[i] - '0');

        //if symbol is an operator then pop top 2 elements from stack, perform specific operation and push the result back into stack
        else{
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();

            if(exp[i]=='+')
                s.push(op1+op2);
            else if(exp[i]=='-')
                s.push(op1-op2);
            else if(exp[i]=='*')
                s.push(op1*op2);
            else if(exp[i]=='/')
                s.push(op1/op2);
        }   
    }
    cout<<"After evalution we get: "<<s.top();
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
 
/* a node of the singly linked list */
class Node
{
    public:
    int data;
    Node *next;
};
 
void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
 
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;
 
    /* Consider all odd nodes before the first
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        *head_ref = curr;
 
        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing
    lines following this statement */
    else prev = curr;
 
    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data <<" ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Let us create a sample linked list as following
    0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    cout << "Original Linked list ";
    printList(head);
 
    segregateEvenOdd(&head);
 
    cout << "\nModified Linked list ";
    printList(head);
 
    return 0;
}
