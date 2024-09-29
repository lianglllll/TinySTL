#pragma once
#include "MyRedBlackTree.cpp"

template <typename Key> class MyMultiSet {
private:
	MyRedBlackTree<Key, size_t> rbTree;
	size_t size;

public:
	MyMultiSet(): size(0) {}
	~MyMultiSet(){}
	void Insert(const Key& key) {
		auto count = rbTree.At(key);
		if (count) {
			(*count)++;
			++size;
		}
		else {
			rbTree.Insert(key, 1);
			++size;
		}
	}
	void Erase(const Key& key) {
		auto count = rbTree.At(key);
		if (!count) {
			return;
		}
		(*count)--;
		--size;
		if (*count == 0) {
			rbTree.Remove(key);
		}
	}
	size_t Size() const { return size; }
	bool Empty()const { return size == 0; }
	size_t Count(const Key& key) {
		auto count = rbTree.At(key);
		if (count) {
			return *count;
		}
		return 0;
	}
	void Clear() {
		size = 0;
		rbTree.Clear();
	}

};

