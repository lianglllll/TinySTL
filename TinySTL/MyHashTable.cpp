#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


template<typename Key,typename Value, typename Hash = hash<Key>>
class MyHashTable {

public:

	class HashNode {
	public:
		Key key;
		Value value;

		explicit HashNode(const Key& key) :key(key), value(){}
		explicit HashNode(const Key& key, const Value& value) :key(key), value(value){}
		bool operator==(const HashNode& other) { return key == other.key; }
		bool operator!=(const HashNode& other) { return key != other.key; }
		bool operator<(const HashNode& other) { return key < other.key; }
		bool operator>(const HashNode& other) { return key > other.key; }
		bool operator==(const Key& key_) const { return key == key_; }
		void print() const{ cout << key << " " << value << " "; }
	};

private:
	using Bucket = list<HashNode>;
	vector<Bucket> buckets;
	Hash hashFunction;				// ��ϣ��������
	size_t capacity;
	size_t _size;
	float maxLoadFactor = 0.75f;

	//����hashֵ
	size_t hash(const Key& key) const{
		return hashFunction(key) % capacity;
	}

	//��Ԫ�������������ĸ������Ӷ��������ʱ,��Ҫ����Ͱ�����������·������Եļ���
	void rehash(size_t newCapacity) {
		//������
		vector<Bucket> newBuckets(newCapacity);
		//������
		for (Bucket& bucket : buckets) {
			for (HashNode& hashNode : bucket) {
				size_t newIndex = hashFunction(hashNode.key)%newCapacity;
				newBuckets[newIndex].push_back(hashNode);
			}
		}
		
		buckets = std::move(newBuckets);	// ʹ���ƶ��������Ͱ����
		capacity = newCapacity;
	}


public:

	MyHashTable(size_t __size = 10,const Hash& hashFunc = Hash() ):buckets(__size),hashFunction(hashFunc),capacity(__size),_size(0){}

	void insert(const Key& key,const Value& value){
		//�鿴�Ƿ���Ҫ��hash
		if ((_size + 1) > maxLoadFactor * capacity) {
			//clear�����Ԫ��ʱ��capacity==0�����
			if (capacity == 0) {
				capacity = 1;
			}
			rehash(capacity * 2);
		}
		//��������
		size_t index = hash(key);
		//�õ���Ӧ��ͱ
		Bucket& bucket = buckets[index];
		//Ͱ��û��ͬ����key�ͽ��в���
		if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
			bucket.push_back(HashNode(key, value));
			++_size;
		}
	
	}

	void insertKey(const Key& key) { insert(key, Value{}); }

	void erase(const Key& key){
		size_t index = hash(key);
		Bucket& bucket = buckets[index];
		auto it = std::find(bucket.begin(), bucket.end(), key);
		if (it != bucket.end()) {
			bucket.erase(it);
			--_size;
		}
	
	}

	Value* find(const Key& key){
		size_t index = hash(key);
		Bucket& bucket = buckets[index];
		auto it = std::find(bucket.begin(), bucket.end(), key);
		if (it != bucket.end()) {
			return &(it->value);
		}
		return nullptr;
	}

	void clear(){
		this->buckets.clear();
		this->_size = 0;
		this->capacity = 0;
	}

	size_t size() const{
		return _size;
	}

	void print() const {
		for (size_t i = 0; i < buckets.size(); ++i) {
			for (const HashNode& item : buckets[i]) {
				item.print();
			}
		}
		cout << endl;
	}
};