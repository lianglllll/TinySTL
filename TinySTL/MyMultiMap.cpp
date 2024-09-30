#pragma once
#include "MyRedBlackTree.cpp"
#include<list>

template <typename Key, typename Value>
class MyMultiMap {
public:
	using ValueType = std::list<Value>;
	MyMultiMap() :rbTree() ,size(0){}
	void Insert(const Key& key, const Value& value) { 
		ValueType* existingValues = rbTree.At(key);
		if (existingValues) {
			existingValues->push_back(value);
		}
		else {
			ValueType values;
			values.push_back(value);
			rbTree.Insert(key, values);
		}
		size++;
	}
	void Erase(const Key& key) { 
		ValueType* existingValues = rbTree.At(key);
		if (existingValues) {
			size -= existingValues->size();
			rbTree.Remove(key);
		}
	}
	void Erase(const Key& key,const Value& value) {
		ValueType* existingValues = rbTree.At(key);
		if (existingValues) {
			existingValues->remove(value);
			size--;
			if (existingValues->empty()) {
				rbTree.Remove(key);
			}
		}
	}
	size_t Size() { return size; }
	bool Empty() { return size == 0; }
	bool Contains(const Key& key) { return rbTree.At(key) != nullptr; }
	ValueType* At(const Key& key) {
		ValueType* foundValue = rbTree.At(key);
		if (foundValue) {
			return foundValue;
		}
		else {
			throw std::out_of_range("Key not found");
		}
	}

private:
	MyRedBlackTree<Key, ValueType> rbTree;
	size_t size;
};