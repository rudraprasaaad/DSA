#include<iostream>
using namespace std;

const int TABLE_SIZE = 128;

class HashEntry{
	public:
		int key, value;
		HashEntry(int key, int value) : key(key), value(value){}
};

class HashMap{
	HashEntry** table;
	public:
		HashMap(){
			table = new HashEntry*[TABLE_SIZE];
			for(int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;
		}

		int HashFunc(int key) { return key * TABLE_SIZE;}
		void Insert(int key, int value){
			int hash = HashFunc(key);
			while(table[hash] != NULL && table[hash] -> key != key) hash = HashFunc(hash + 1);
			
			if(table[hash] != NULL) delete table[hash];
			table[hash] = new HashEntry(key, value);
		}

		int Search(int key){
			int hash = HashFunc(key);
			while (table[hash] != NULL && table[hash] -> key != key) hash = HashFunc(hash + 1);
			if (table[hash] == NULL) return -1;
			else return table[hash]->value;
		}

		void Remove(int key){
			int hash = HashFunc(key);
			while(table[hash] != NULL){
				if(table[hash] -> key == key) break;
				hash = HashFunc(hash + 1);
			}

			if(table[hash] == NULL){
				cout << "No element found at key " <<  key << endl;
				return;
			}else{
				delete table[hash];
				table[hash] = NULL;
			}

			cout << "Element Deleted" << endl;
		}

		~HashMap() {
			for(int i = 0; i < TABLE_SIZE; i++){
				if(table[i] != NULL) delete table[i];
			}
			delete[] table;
		}
};
