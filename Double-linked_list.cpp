#include <iostream>
#include <cstdlib>
using namespace std;
struct DNode
{
  int data; // элемент данных
  DNode * next; // указатель на следующий узел
  DNode * prev; // указатель на предыдущий узел
  DNode(int d = 0, DNode * n = nullptr, DNode * p = nullptr) :
  data(d), next(n), prev(p) {} // конструктор
  };
  struct DList
  {
  DNode *head, *tail;
  ~DList(){  del(); }//деструктор

  DList() { head = nullptr; tail = nullptr; }

  DNode* copy(DNode* x) //функция copy
  {
    if (x == nullptr) { return nullptr; }
    DNode* y = new DNode(x->data, copy(x->next), nullptr);
    if (y->next != nullptr){ y->next->prev = y; }
    return y;
  }

  DList(const DList& l)//конструктор копий
  {
    head = copy(l.head);
    DNode* c = head;
    while (c->next != nullptr){  c = c->next;  }
    tail = c;
  }

  DList & operator=(const DList& l)//перегруженный оператор =
  {
    del();
    head = copy(l.head);
    DNode* c = head;
    while (c->next != nullptr){  c = c->next;  }
    tail = c;
    return *this;
  }

  void add_first(int d) // 2-я реализация метода add_first
  {
    DNode *t;
    t = new DNode(d, head, nullptr);
    if (head == nullptr)
    {
      head = t;
      tail = t;
    }
    else
    {
      head->prev = t;
      head = t;
    }
  }

  void print(){ // печать в прямом порядке
    DNode *p = head;
    while (p != nullptr)
    {
    cout << p->data << "\t";
    p = p->next; // переход к следующему элементу
    }
    cout << endl;
  }

  void insertp(int n1, int data1){
    DNode *list, *temp, *p;
    temp = new DNode (data1, nullptr, nullptr);
    int u=0;
    p=head;
    while(u+1<n1){
     u++;
     p=p->next;
    }
    list = p;
    p = p->next; // указатель на следующий узел
    list->next = temp;
    temp->prev = list; // предыдущий узел указывает на создаваемый
    temp->data = data1; // данные добавляемого узла
    temp->next = p; // созданный узел указывает на следующий
    p->prev = temp;
    return;
  }

  void del()
  {
    if (head == nullptr){  return; }
    else
    {
      DNode* c = head;
      while (c != nullptr)
      {
        DNode* temp = c;
        c = c->next;
        delete temp;
      }
      head = c;
      tail = nullptr;
    }
  }

  void delp (int n){
    if ((head == nullptr)&&(tail == nullptr))
    {
      cout << "Empty"<<endl;
      return;
    }
    DNode *temp=head,*p=NULL,*ne=NULL;
    int i=0;
    while(i<n){
      i++;
      p=temp; // Запоминаем предыдущий в цепочке
      temp=temp->next;
      ne=temp->next;
    }
    if(head==temp){  head=temp->next;  }
    else
    {
      p->next=ne;
      ne->prev=p;
    }
    delete (temp);
    return;
  }

  void print_reverse(){
    DNode *p = tail;
    while (p != nullptr)
    {
    cout << p->data << "\t";
    p = p->prev; // переход к следующему элементу
    }
    cout << endl;
  }
  
  void Print() // печать в прямом и обратном порядках
  {
    print();
    print_reverse();
    cout << endl;
  }
}; // конец структуры DList
int main()
{
  DList l; // l  пустой список
  l.add_first(3); // добавление
  l.add_first(2);
  l.add_first(1);
  l.Print();
  l.insertp(2,15);
  l.Print();
  l.delp(1);
  l.print();
  DList l2;
  l2.add_first(6);
  l2.add_first(7);
  l2.add_first(8);
  l2.print();
  l2 = l;
  l.print();
  l2.print();
  // печать
  return EXIT_SUCCESS;
}
