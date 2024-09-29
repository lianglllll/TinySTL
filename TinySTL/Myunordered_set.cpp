#pragma once
#include "MyHashTable.cpp"

template <typename Key> class Myunordered_set {

public:
	Myunordered_set() :hashtable() {}
	~Myunordered_set() {}
	void Insert(const Key& key) { hashtable.insert(key, key); }
	void Erase(const Key& key) { hashtable.erase(key); }
	size_t Size() { return hashtable.size(); }
	bool Empty() { return hashtable.size() == 0; }
	bool Contains(const Key& key) { return hashtable.find(key) != nullptr; }
	void Clear()  { hashtable.clear(); }

private:
	MyHashTable<Key, Key> hashtable;
};