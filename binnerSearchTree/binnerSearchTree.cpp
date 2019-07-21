#include <set>
#include <iostream>
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;
// 搜索树  
template<class K, class V>
//定义二叉搜索树的结点
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
    //如果根节点为空则插入的结点作为新的根节点
    if (_root == nullptr)
    {
      _root = new Node(kv);
      return true;
    }

    Node* parent = nullptr;
    Node* cur = _root;
    //根据二叉搜索树的规则，将要插入的新节点，大于当前节点
    //则与当前节点的右孩子再进行比较，小于当前结点则与当前结点
    //左孩子进行比较，并更新当前比较的结点，直到出现空节点插入
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
      //出现相同结点则不插入
      else
      {
        return false;
      }
    }

    //到这步还需直到新的结点插入到它父亲的左孩子还是右孩子
    //的位置，仍需一步比较
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
    //根据二叉搜索树的特性，大了往右找，小了往左找
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
        // 1.只有0-1个孩子
        Node* del = cur;
        if (cur->_left == nullptr)
        {
          //如果当前要删除的是根节点，且该节点没有左孩子
          //则它的右孩子成为新的根
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
        // 2.有两个孩子
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
