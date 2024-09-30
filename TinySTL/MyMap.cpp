#pragma once
#include "MyRedBlackTree.cpp"

template <typename Key,typename Value>
class MyMap {
public:
	MyMap():rbTree(){}
	void Insert(const Key& key, const Value& value) { rbTree.Insert(key, value); }
	void Erase(const Key& key) { rbTree.Remove(key); }
	size_t Size() { return rbTree.GetSize(); }
	bool Empty() { return rbTree.Empty(); }
	bool Contains(const Key& key) { return rbTree.At(key) != nullptr; }
	Value& At(const Key& key) {
		Value* foundValue = rbTree.At(key);
		if (foundValue) {
			return *foundValue;
		}
		else {
			throw std::out_of_range("Key not found");
		}
	}
	Value& operator[](const Key& key) {
		Value* foundValue = rbTree.At(key);
		if (foundValue) {
			return *foundValue;
		}
		else {
			// 如果键不存在，插入新键值对，并返回新插入的值的引用
			Value defaultValue;
			rbTree.Insert(key, defaultValue);
			return *rbTree.At(key);
		}
	}

private:
	MyRedBlackTree<Key, Value> rbTree;
};