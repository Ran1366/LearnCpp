#include <set>
#include <iostream>
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;
// ������  
template<class K, class V>
//��������������Ľ��
struct BSTreeNode
{
  pair<K, V> _kv;
  BSTreeNode<K, V>* _left;
  BSTreeNode<K, V>* _right;

  BSTreeNode(const pair<K, V>& kv)
    :_left(nullptr)
     , _right(nullptr)
     , _kv(kv)
  {}
};

template<class K, class V>
class BSTree
{
  typedef BSTreeNode<K, V> Node;
  public:
  BSTree()
    :_root(nullptr)
  {}

  bool Insert(const pair<K, V>& kv)
  {
    //������ڵ�Ϊ�������Ľ����Ϊ�µĸ��ڵ�
    if (_root == nullptr)
    {
      _root = new Node(kv);
      return true;
    }

    Node* parent = nullptr;
    Node* cur = _root;
    //���ݶ����������Ĺ��򣬽�Ҫ������½ڵ㣬���ڵ�ǰ�ڵ�
    //���뵱ǰ�ڵ���Һ����ٽ��бȽϣ�С�ڵ�ǰ������뵱ǰ���
    //���ӽ��бȽϣ������µ�ǰ�ȽϵĽ�㣬ֱ�����ֿսڵ����
    while (cur)
    {
      if (cur->_kv.first > kv.first)
      {
        parent = cur;
        cur = cur->_left;
      }
      else if (cur->_kv.first < kv.first)
      {
        parent = cur;
        cur = cur->_right;
      }
      //������ͬ����򲻲���
      else
      {
        return false;
      }
    }

    //���ⲽ����ֱ���µĽ����뵽�����׵����ӻ����Һ���
    //��λ�ã�����һ���Ƚ�
    cur = new Node(kv);
    if (parent->_kv.first < kv.first)
    {
      parent->_right = cur;
    }
    else
    {
      parent->_left = cur;
    }
    return true;
  }

  Node* Find(const K& kv)
  {
    Node* cur = _root;
    //���ݶ��������������ԣ����������ң�С��������
    while (cur)
    {
      if (cur->_kv.first < kv.first)
      {
        cur = cur->_right;
      }
      else if (cur->_kv.first > kv.first)
      {
        cur = cur->_left;
      }
      else
      {
        return cur;
      }
    }

    return nullptr;
  }

  bool Remove(const K& key)
  {
    Node* parent = nullptr;
    Node* cur = _root;
    while (cur)
    {
      if (cur->_kv.first < key)
      {
        parent = cur;
        cur = cur->_right;
      }
      else if (cur->_kv.first > key)
      {
        parent = cur;
        cur = cur->_left;
      }
      else
      {
        // 1.ֻ��0-1������
        Node* del = cur;
        if (cur->_left == nullptr)
        {
          //�����ǰҪɾ�����Ǹ��ڵ㣬�Ҹýڵ�û������
          //�������Һ��ӳ�Ϊ�µĸ�
          if (parent == nullptr)
          {
            _root = cur->_right;
          }
          else
          {
            if (cur == parent->_left)
            {
              parent->_left = cur->_right;
            }
            else
            {
              parent->_right = cur->_right;
            }
          }					
        }
        else if (cur->_right == nullptr)
        {
          if (parent == nullptr)
          {
            _root = cur->_left;
          }
          else
          {
            if (cur == parent->_left)
            {
              parent->_left = cur->_left;
            }
            else
            {
              parent->_right = cur->_left;
            }
          }	
        }
        // 2.����������
        else
        {
          Node* rpParent = cur;
          Node* replace = cur->_right;
          while (replace->_left)
          {
            rpParent = replace;
            replace = replace->_left;
          }

          cur->_kv = replace->_kv;
          del = replace;
          if (rpParent->_left == replace)
          {
            rpParent->_left = replace->_right;
          }
          else
          {
            rpParent->_right = replace->_right;
          }
        }

        delete del;

        return true;
      }
    }

    return false;
  }

  void InOrder()
  {
    _InOrder(_root);
    cout << endl;
  }

  void _InOrder(Node* root)
  {
    if (root == nullptr)
      return;

    _InOrder(root->_left);
    cout << root->_kv.first << " ";
    _InOrder(root->_right);
  }

  private:
  Node* _root;
};

int main()
{
  BSTree<int, int> tree;
  tree.Insert(make_pair(1, 1));
  tree.Insert(make_pair(5, 1));
  tree.Insert(make_pair(2, 1));
  tree.Insert(make_pair(6, 1));
  tree.Insert(make_pair(7, 1));
  tree.Insert(make_pair(9, 1));
  tree.Insert(make_pair(4, 1));
  tree.InOrder();

  tree.Remove(1);
  tree.Remove(2);
  tree.Remove(5);
  tree.Remove(2);
  tree.Remove(4);
  tree.Remove(1);
  tree.Remove(10);
  tree.InOrder();

  return 0;
}
