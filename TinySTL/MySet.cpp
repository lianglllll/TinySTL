#pragma once
#include "MyRedBlackTree.cpp"

template <typename Key> class MySet {

public:
	MySet():rbTree(){}
	void Insert(const Key& key) { rbTree.Insert(key, key); }
	void Erase(const Key& key) { rbTree.Remove(key); }
	size_t Size() { return rbTree.GetSize(); }
	bool Empty() { return rbTree.Empty(); }
	bool Contains(const Key& key) { return rbTree.At(key) != nullptr; }

private:
	MyRedBlackTree<Key, Key> rbTree;
};