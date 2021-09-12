#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

class List
{
private:
  Node *head;
  int size;

public:
  List()
  {
    this->head = NULL;
    this->size = 0;
  }

  int getSize()
  {
    return this->size;
  }

  void addNode(int data)
  {
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (this->head == NULL)
    {
      this->head = node;
    }
    else
    {
      Node *current = this->head;

      while (current->next != NULL)
      {
        current = current->next;
      }

      current->next = node;
      node->prev = current;
    }
    this->size++;
  }

  void printList()
  {
    Node *current = head;

    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  bool removeNode(int index)
  {
    Node *current = this->head;
    int currentIndex = 0;

    if (index < 0 || index > this->size - 1)
    {
      return false;
    }

    while (index != currentIndex && current != NULL)
    {
      current = current->next;
      currentIndex++;
    }

    if (current == this->head)
    {
      this->head = this->head->next;
      this->head->prev = NULL;
      delete current;
    }
    else if (current->next == NULL)
    {
      current->prev->next = NULL;
      delete current;
    }
    else
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
    }

    this->size--;
    return true;
  }

  bool showNode(int index)
  {
    Node *current = this->head;
    int currentIndex = 0;

    if (index < 0 || index > this->size - 1)
    {
      return false;
    }

    while (current != NULL && currentIndex != index)
    {
      current = current->next;
      currentIndex++;
    }
    cout << "Value: " << current->data << endl;

    char str[] = "";

    cout << "Enter 1 for next, 2 for prev, 0 for exit" << endl;
    cin >> str;
    while (!isdigit(str[0]))
    {
      cout << "Enter number" << endl;
      cin >> str;
    }

    int digit = atoi(str);
    while (true)
    {
      if (digit == 1)
      {
        if (current->next != NULL)
        {
          current = current->next;
          cout << "Value: " << current->data << endl;
        }
        else
        {
          cout << "Node dont exist" << endl;
        }
      }
      if (digit == 2)
      {
        if (current->prev != NULL)
        {
          current = current->prev;
          cout << "Value: " << current->data << endl;
        }
        else
        {
          cout << "Node dont exist" << endl;
        }
      }

      if (digit == 0)
      {
        break;
      }

      cout << "Enter number" << endl;
      cin >> str;

      while (!isdigit(str[0]))
      {
        cout << "Enter number" << endl;
        cin >> str;
      }

      digit = atoi(str);
    }

    return true;
  }

  void serialize()
  {
    ofstream fout("out.txt");
    if (fout.is_open())
    {
      Node *node = this->head;

      while (node != NULL)
      {
        fout.write((char *)&node->data, sizeof(node->data));
        node = node->next;
      }
    }
    else
    {
      cout << "File not open" << endl;
    }
    fout.close();
  }

  void deserialize()
  {
    ifstream fin("out.txt");

    if (fin.is_open())
    {
      Node *node = new Node;
      while (fin.read((char *)&node->data, sizeof(node->data)))
      {
        cout << node->data << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "File not open" << endl;
    }

    fin.close();
  }
};

int main()
{
  List list;

  list.addNode(5);
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(4);

  list.printList();

  // list.showNode(0);
  // list.serialize();
  // list.deserialize();

  // list.removeNode(4);
  // list.removeNode(0);
  // list.printList();

  cout << "End work!" << endl;
}