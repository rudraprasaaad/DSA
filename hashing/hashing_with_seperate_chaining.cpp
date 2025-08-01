#include<iostream>
#include<cstring>

using namespace std;

struct node{
	char* key; 
	char* value;
	struct node* next;
};

void setNode(node *n ,char* key, char* value){
	n->key = key;
	n->value = value;
	n->next = NULL;
}

struct hashMap{
	int numOfElements, capacity;
	node** arr;
};

void initializeHashMap(hashMap *mp){
	mp->capacity = 100;
	mp->numOfElements = 0;
	mp->arr = (node**)malloc(sizeof(node*) * mp->capacity);
	for(int i = 0; i < mp->capacity; i++) mp->arr[i] = NULL;
}

int hashFunction(hashMap* mp, char* key){
	int sum = 0, factor = 31;
	for(int i = 0; i < strlen(key); i++){
		sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
		factor = ((factor % 32767) * (31 % 32767)) % 32767;
	}
	return sum;
}

void insert(hashMap* mp, char* key, char* value){
	int bucketIndex = hashFunction(mp, key);
	node* newNode = (node*)malloc(sizeof(node));
	setNode(newNode, key, value);
	newNode->next = mp->arr[bucketIndex];
	mp->arr[bucketIndex] = newNode;
}

char* search(hashMap *mp, char* key){
	int bucketIndex = hashFunction(mp, key);
	node* bucketHead = mp->arr[bucketIndex];
	while(bucketHead){
		if(strcmp(bucketHead->key, key) == 0)
			return bucketHead->value;
		bucketHead = bucketHead->next;
	}
	return (char*)"Oops! No data found.\n";
}