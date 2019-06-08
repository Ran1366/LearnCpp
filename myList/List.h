#pragma once

template<class T>
struct ListNode
{
  ListNode<T>* _next;
  ListNode<T>* _prev;
  T _data;

  ListNode(const T& x = T())
    :_next(nullptr)
     , _prev(nullptr)
     , _data(x)
  {}
};

// typedef __ListIterator<T, T&, T*> iterator;
// typedef __ListIterator<T, const T&, const T*> const_iterator;
template<class T, class Ref, class Ptr>
struct __ListIterator
{
  typedef ListNode<T> Node;
  typedef __ListIterator<T, Ref, Ptr> Self;
  Node* _node;

  __ListIterator(Node* node)
    :_node(node)
  {}

  // *it;
  Ref operator*()
  {
    return _node->_data;
  }

  // it->
  //T* operator->()
  Ptr operator->()
  {
    return &_node->_data;
  }

  Self& operator++()
  {
    _node = _node->_next;
    return *this;
  }

  Self operator++(int)
  {
    Self tmp(*this);
    _node = _node->_next;
    return tmp;
  }


  Self& operator--()
  {
    _node = _node->_prev;
    return *this;
  }

  // it1 != it2
  bool operator!=(const Self& it)
  {
    return _node != it._node;
  }
};

template<class T>
class List
{
  typedef ListNode<T> Node;
  public:
  typedef __ListIterator<T, T&, T*> iterator;
  typedef __ListIterator<T, const T&, const T*> const_iterator;


  List()
    :_head(new Node)
  {
    _head->_next = _head;
    _head->_prev = _head;
  }

  iterator begin()
  {
    return _head->_next;
  }

  const_iterator end() const
  {
    return _head;
  }

  const_iterator begin() const
  {
    return const_iterator(_head->_next);
  }

  iterator end()
  {
    return iterator(_head);
  }

  void PushBack(const T& x)
  {
    Node* tail = _head->_prev;
    Node* newnode = new Node(x);

    tail->_next = newnode;
    newnode->_prev = tail;

    newnode->_next = _head;
    _head->_prev = newnode;
  }
  private:
  Node* _head;
};

// struct AA
// {
// int _a1;
// int _a2;
// };

// void TestList1()
// {
// List<int> l;
// l.PushBack(1);
// l.PushBack(2);
// l.PushBack(3);

// List<int>::iterator it = l.begin();
// while (it != l.end())
// {
// cout << *it << " ";
// ++it;
// }
// cout << endl;

// for (auto e : l)
// {
// cout << e << " ";
// }
// cout << endl;

// List<AA> laa;
// AA aa1 = { 1, 2 };
// laa.PushBack(aa1);
// laa.PushBack({3, 4});
// List<AA>::iterator ita = laa.begin();
// while (ita != laa.end())
// {
//	cout << (*ita)._a1 << (*ita)._a2 << endl;
// cout << ita->_a1 << ita->_a2 << endl;

// ++ita;
// }

// AA* pa = new AA;
// pa->_a1 = 10;
// cout << (*pa)._a1 << endl;

// int* pi = new int;
// *pi;
// }
