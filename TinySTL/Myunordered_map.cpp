#pragma once
#include "MyHashTable.cpp"

template <typename Key, typename Value>
class Myunordered_map {
public:
	Myunordered_map() :hashtable() {}
	void Insert(const Key& key, const Value& value) { hashtable.insert(key, value); }
	void Erase(const Key& key) { hashtable.erase(key); }
	size_t Size() { return hashtable.size(); }
	bool Empty() { return hashtable.size() == 0; }
	void Clear() { hashtable.clear(); }
	bool Contains(const Key& key) { return hashtable.find(key) != nullptr; }
	Value& At(const Key& key) {
		Value* foundValue = hashtable.find(key);
		if (foundValue) {
			return *foundValue;
		}
		else {
			throw std::out_of_range("Key not found");
		}
	}
	Value& operator[](const Key& key) {
		Value* foundValue = hashtable.find(key);
		if (foundValue) {
			return *foundValue;
		}
		else {
			// 如果键不存在，插入新键值对，并返回新插入的值的引用
			Value defaultValue;
			hashtable.insert(key, defaultValue);
			return *hashtable.find(key);
		}
	}

private:
	MyHashTable<Key, Value> hashtable;
};