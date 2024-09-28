#include <iostream>
#include <string>
#include <iostream>
using namespace std;

enum Color
{
	RED,BLACK
};

template<typename Key,typename Value> 
class MyRedBlackTree {

	//红黑树节点
	class Node {
	public:
		Key key;
		Value value;
		Color color;
		Node* left;
		Node* right;
		Node* parent;
		Node() :color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
		Node(const Key& key,const Value& value,Color color,Node* parent = nullptr)
			:key(key),value(value),color(color),left(nullptr),right(nullptr), parent(parent) {}
	};

private:
	Node* root;
	size_t size;
	Node* Nil;

public:
	MyRedBlackTree() :root(nullptr), size(0), Nil(new Node()) {
		Nil->color = Color::BLACK;
	}
	~MyRedBlackTree() {
		//释放节点内存
		DeleteTree(root);
	}
	void Insert(const Key& key, const Value& value) {
		InsertNode(key, value);
	}
	void Remove(const Key& key) {
		Node* nodeToBeRemoved = LookUp(key);
		if (nodeToBeRemoved) {
			RemoveNode(nodeToBeRemoved);
			--size;
		}
	}
	Value* At(const Key& key) {
		Node* ans = LookUp(key);
		if (ans) {
			return &(ans->value);
		}
		return nullptr;
	}
	size_t GetSize() {
		return size;
	}
	bool Empty() {
		return size == 0;
	}
	void Clear() {
		DeleteTree(root);
		size = 0;
	}
	void print() {
		InorderTraversal(root);
		cout << endl;
	}

private:
	void InsertNode(const Key& key, const Value& value) {
		//创建一个新节点，颜色为红
		Node* newNode = new Node(key, value, Color::BLACK); 
		Node* parent = nullptr;	
		Node* cmpNode = root;	//用于比较的节点，初始化为根

		//遍历树，找到合适的插入位置
		while (cmpNode) {
			parent = cmpNode;
			if (newNode->key < cmpNode->key) {
				cmpNode = cmpNode->left;
			}
			else if (newNode->key > cmpNode->key) {
				cmpNode = cmpNode->right;
			}
			else {
				//找到相同的键的节点，删除新节点并返回，本次插入失败
				delete newNode;
				return;
			}
		}

		//设置父子关系
		newNode->parent = parent;
		if (!parent) {
			//处理树空的情况
			root = newNode;
		}
		else if (newNode->key < parent->key) {
			//插入到parent的左子树
			parent->left = newNode;
		}
		else {
			//插入到parent的右子树
			parent->right = newNode;
		}

		//数据更新
		++size;

		//修复可能被破坏的红黑树性质
		InsertFixup(newNode);

	}
	void InsertFixup(Node* target) {

		//当前目标节点的父节点存在&&是红色时，需要修复
		while (target->parent && target->parent->color == Color::RED) {

			// 1.当目标节点的父节点是祖父节点的左节点时
			if (target->parent == target->parent->parent->left) {

				Node* uncle = target->parent->parent->right;

				//2.父红叔红
				if (uncle && uncle->color == Color::RED) {
					target->parent->color = Color::BLACK;
					uncle->parent->color = Color::BLACK;
					target->parent->parent->color = Color::RED;
					//将祖父节点设置为下一个目标节点
					target = target->parent->parent;
				}
				//2.父红叔黑
				else {
					
					//3.爷父子不同路，先左旋变为爷父子的情况
					if (target == target->parent->right) {
						target = target->parent;
						LeftRotate(target);
					}
					//来到这里是爷父子同路，父子红的情况，，调整父节点和爷爷节点的颜色并且进行右旋
					target->parent->color = Color::BLACK;
					target->parent->parent->color = Color::RED;
					RightRotate(target->parent->parent);
				}

			}
			//1.当目标节点的父节点是祖父节点的右节点时
			else {
				Node* uncle = target->parent->parent->left;
				//2.父红叔红
				if (uncle && uncle->color == Color::RED) {
					target->parent->color = Color::BLACK;
					uncle->parent->color = Color::BLACK;
					target->parent->parent->color = Color::RED;
					//将祖父节点设置为下一个目标节点
					target = target->parent->parent;
				}
				//2.父红叔黑
				else {
					//3.爷父子不同路，先左旋变为爷父子的情况
					if (target == target->parent->left) {
						target = target->parent;
						RightRotate(target);
					}
					//来到这里是爷父子同路，父子红的情况，，调整父节点和爷爷节点的颜色并且进行右旋
					target->parent->color = Color::BLACK;
					target->parent->parent->color = Color::RED;
					LeftRotate(target->parent->parent);
				}
			}
		}
		//保持根节点为黑色
		root->color = Color::BLACK;
	}
	void LeftRotate(Node* node) {
		//左旋：节点x的右孩子y变成x的父节点，x变成了y的左孩子。如果y有一个左孩子，它会变成x的右孩子。
		
		Node* r_son = node->right;
		node->right = r_son->left;
		if (r_son->left) {
			r_son->left->parent = node;
		}
		r_son->parent = node->parent;
		
		//链接node->parent和r_son
		if (!node->parent) {
			root = r_son;
		}
		else if (node == node->parent->left) {
			node->parent->left = r_son;
		}
		else {
			node->parent->right = r_son;
		}

		r_son->left = node;
		node->parent = r_son;
	}
	void RightRotate(Node* node) {
		//右旋:节点x的左孩子y变成x的父节点，x变成了y的右孩子。如果y有一个右孩子，它会变成x的左孩子。

		Node* l_son = node->left;
		
		node->left = l_son->right;
		if (l_son->right) {
			l_son->right->parent = node;
		}

		l_son->parent = node->parent;
		if (!node->parent) {
			root = l_son;
		}
		else if (node->parent->left == node) {
			node->parent->left = l_son;
		}
		else {
			node->parent->right = l_son;
		}

		l_son->right = node;
		node->parent = l_son;
	}
	void RemoveNode(Node* del) {
		Node* rep = del;					//rep(替代节点)，初始指向要删除的节点
		Color delOrignalCol = del->color;	//保存要删除节点的颜色
		Node* child = nullptr;				//要删除节点的孩子节点
		Node* parentRp;						//rep节点的父节点

		//只有单个孩子只能是红孩子
		//要删除节点没有左孩子
		if (!del->left) {
			rep = del->right;
			parentRp = del->parent;
			//使用rep节点替换掉del节点并且他们的颜色要进行交换
			delOrignalCol = GetColor(rep);	// 获取替代节点的颜色，所以这个delOrignalCol就是代表del节点的颜色
			ReplaceNode(del, rep);			// 用替代节点替换删除节点
		}
		//要删除节点没有右孩子
		else if (!del->right) {
			rep = del->left;
			parentRp = del->parent;
			delOrignalCol = GetColor(rep);
			ReplaceNode(del, rep);
		}
		//要删除节点有两个孩子
		else {
			//找到删除节点右子树中的最小值作为替代节点
			rep = FindMinmumNode(del->right);
			delOrignalCol = rep->color;

			//替代节点不是删除节点的直接右孩子
			if (rep != del->right) {
				
				parentRp = rep->parent;
				child = rep->right;
				parentRp->left = child;
				if (child != nullptr) {
					child->parent = parentRp;
				}

				del->left->parent = rep;
				del->right->parent = rep;
				rep->left = del->left;
				rep->right = del->right;

				//如果删除节点有父节点
				if (del->parent != nullptr) {
					if (del == del->parent->left) {
						del->parent->left = rep;
						rep->parent = del->parent;
					}
					else {
						del->parent->right = rep;
						rep->parent = del->parent;
					}
				}
				else {
					//删除节点为根
					root = rep;
					root->parent = nullptr;
				}

			
			}
			else {
				//替代节点是删除节点的直接右孩子
				child = rep->right;
				rep->left = del->left;
				del->left->parent = rep;
				if (del->parent) {
					if (del == del->parent->left) {
						del->parent->left = rep;
						rep->parent = del->parent;
					}
					else {
						del->parent->right = rep;
						rep->parent = del->parent;
					}
				}
				else {
					//删除节点为根
					root = rep;
					root->parent = nullptr;
				}
				parentRp = rep; // 更新替代节点的父节点
			}
		}

		// 如果替代节点存在，更新其颜色为删除节点的颜色
		if (rep) {
			rep->color = del->color;
		}
		else {
			// 如果替代节点不存在，将删除节点的颜色赋给origCol变量
			//当删除节点没有左右孩子时触发
			delOrignalCol = del->color;
		}

		// 如果原始颜色是黑色，需要进行额外的修复操作，因为黑色节点的删除可能会破坏红黑树的性质
		if (delOrignalCol == Color::BLACK) {

			if (child) {
				RemoveFixup(child);
			}else{
				// 如果不存在孩子节点，将Nil节点（代表空节点）的父节点设置为替代节点的父节点
				if (parentRp) {
					if (parentRp->left == nullptr) {
						parentRp->left = Nil;
					}
					else {
						parentRp->right = Nil;
					}

				}
				RemoveFixup(Nil);
				// 断开Nil节点与树的连接，因为在红黑树中Nil节点通常是单独存在的
				DisConnectNil();
			}
		}

		//删除节点
		delete del;
	}
	void RemoveFixup(Node* node) {

		//从node点开始调整

		//如果节点为Nil并且没有父节点，说明他是唯一的节点，直接返回
		if (node == Nil && node->parent == nullptr) {
			return;
		}

		//当我们没有达到根节点时，继续循环
		while (node != root)
		{
			//如果节点是其父节点的左子节点
			if (node == node->parent->left) {

				Node* sibling = node->parent->right;

				//情况1：兄红
				//转换为兄黑的情况
				if (GetColor(sibling) == Color::RED) {
					//父兄颜色交换，并且左旋
					SetColor(sibling, Color::BLACK);
					SetColor(sibling->parent, Color::RED);
					LeftRotate(sibling->parent);
					//更新新的兄弟节点
					sibling = node->parent->right;
				}

				//情况2：双侄黑
				if (GetColor(sibling->left) == Color::BLACK && GetColor(sibling->right) == Color::BLACK) {
					//兄弟变色
					SetColor(sibling, Color::RED);
					//向上移动，开启新一轮调整
					node = node->parent;
					//如果父节点是红色，就将其改为黑色并结束
					if (node->color == Color::RED) {
						node->color = Color::BLACK;
						node = root;
					}
				}
				else {

					// 情况3:顺侄红
					// 转换为对侄红情况
					if (GetColor(sibling->right) == Color::BLACK) {
						SetColor(sibling->left, Color::BLACK);
						SetColor(sibling, Color::RED);
						RightRotate(sibling);
						sibling = node->parent->right;
					}
					//情况4：对侄红
					SetColor(sibling, GetColor(node));
					SetColor(sibling->parent, Color::BLACK);
					SetColor(sibling->right, Color::BLACK);
					LeftRotate(sibling->parent);

					// 移动到根节点结束
					node = root;
				}

			}
			else {
				// 当节点是其父节点的右子节点时
				Node* sibling = node->parent->left;

				//情况1：兄红
				//转换为兄黑的情况
				if (GetColor(sibling) == Color::RED) {
					//父兄颜色交换，并且左旋
					SetColor(sibling, Color::BLACK);
					SetColor(sibling->parent, Color::RED);
					LeftRotate(sibling->parent);
					//更新新的兄弟节点
					sibling = node->parent->left;
				}

				//情况2：双侄黑
				if (GetColor(sibling->left) == Color::BLACK && GetColor(sibling->right) == Color::BLACK) {
					//兄弟变色
					SetColor(sibling, Color::RED);
					//向上移动，开启新一轮调整
					node = node->parent;
					//如果父节点是红色，就将其改为黑色并结束
					if (node->color == Color::RED) {
						node->color = Color::BLACK;
						node = root;
					}
				}
				else {

					// 情况3:顺侄红
					// 转换为对侄红情况
					if (GetColor(sibling->left) == Color::BLACK) {
						SetColor(sibling->right, Color::BLACK);
						SetColor(sibling, Color::RED);
						LeftRotate(sibling);
						sibling = node->parent->left;
					}
					//情况4：对侄红
					SetColor(sibling, GetColor(node));
					SetColor(sibling->parent, Color::BLACK);
					SetColor(sibling->left, Color::BLACK);
					RightRotate(sibling->parent);

					// 移动到根节点结束
					node = root;
				}

			}

		}
	}
	//查找节点
	Node* LookUp(Key key) {
		Node* cmpNode = root;
		while (cmpNode) {
			if (key < cmpNode->key) {
				cmpNode = cmpNode->left;
			}
			else if (key > cmpNode->key) {
				cmpNode = cmpNode->right;
			}
			else {
				return cmpNode;
			}
		}
		return cmpNode;
	}
	//获取节点颜色
	Color GetColor(Node* node) {
		if (node == nullptr) {
			return Color::BLACK;
		}
		return node->color;
	}
	//设置节点颜色
	void SetColor(Node* node,Color color) {
		if (node == nullptr) {
			return;
		}
		node->color = color;
	}
	//用新节点替换旧节点
	void ReplaceNode(Node* targetNode, Node* newNode) {
		if (!targetNode->parent) {
			root = newNode;
		}
		else if (targetNode == targetNode->parent->left) {
			targetNode->parent->left = newNode;
		}
		else {
			targetNode->parent->right = newNode;
		}

		if (newNode) {
			newNode->parent = targetNode->parent;
		}

	}
	//寻找以node节点为根的子树中的最小节点
	Node* FindMinmumNode(Node* node) {
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	// 取消Nil哨兵的连接
	void DisConnectNil() {
		if (Nil == nullptr)return;
		if (Nil->parent) {
			if (Nil = Nil->parent->left) {
				Nil->parent->left = nullptr;
			}
			else {
				Nil->parent->right = nullptr;
			}
		}
	}
	//中序遍历
	void InorderTraversal(Node* node)const {
		if (node) {
			InorderTraversal(node->left);
			cout << node->key << " ";
			InorderTraversal(node->right);
		}
	}
	//删除整颗树
	void DeleteTree(Node* node) {
		if (node) {
			DeleteTree(node->left);
			DeleteTree(node->right);
			delete node;
		}
	}
};