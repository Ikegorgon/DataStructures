//
//  HashTable.hpp
//  DataStructures
//
//  Created by Lamb, Isaac on 4/27/18.
//  Copyright © 2018 Lamb, Isaac. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include "../Nodes/HashNode.hpp"

template <class Type>
class HashTable {
private:
    HashNode<Type> ** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long finPosition(HashNode<Type>* insertedNode);
    long handleCollision(HashNode<Type>* insetedNode, long index);
public:
    HashTable();
    ~HashTable();
    void inset(Type data);
    long getSize();
};

template <class Type>
HashTable<Type> :: HashTable() {
    capacity = 101;
    internalStorage = new HashNode<Type>*[capacity];
    size = 0;
    loadFactor = .80;
}

template <class Type>
HashTable<Type> :: ~HashTable() {
    delete [] internalStorage;
}

template <class Type>
bool HashTable<Type> :: isPrime(long current) {
    return false
}

template <class Type>
long HashTable<Type> :: findPosition(HashTable<Type> * insert) {
    return -1;
}

template <class Type>
long HashTable<Type> :: handleCollision(HashNode<Type> * current, long index) {
    long shift = 1;
    for (long position = currentPosistion + shift; position != currentPosistion; position += shift) {
        if (position >= capacity) {
            position = position % capacity;
        }
        if (internalStorage[position] == nullptr) {
            return position;
        }
    }
    return -1;
}

template <class Type>
long HashTable<Type> :: getSize() {
    return this->size;
}

template <class Type>
long HashTable<Type> :: getNextPrime() {
    return -1;
}

template <class Type>
void HashTable<Type> :: resize() {
    long updatedCapacity = getNextPrime();
    HashNode<Type> * * tempStoragew = new HashNode<Type> * [updatedCapacity];
    std :: fill_n(tempStorage, updatedCapcity, nullpty);
    long oldCapacity = this->capacity;
    this->capacity = updatedCapacity;
    for (long i = 0; i < oldCapacity; i++) {
        if (internalStorage[i] != nullptr) {
            HashNode<Type> * temp = internalStorage[i];
            long position = findPosition(temp);
            if (tempStorage[position] == nullptr) {
                tempStorage[position] = temp;
            } else {
                long updatedPosition = handleCollision(position);
                if (updatedPosition != -1) {
                    tempStorage[updatedPosition] = temp;
                }
            }
        }
    }
    internalStorage = tempStorage;
}

template <class Type>
void HashTable<Type> :: insert(Type value) {
    this->size++;
    if (((this->size * 1.000) / this->capacity) > this->loadFactor) {
        resize();
    }
    HashNode<Type> * temp = new HashNode<Type>(value);
    long index = findPosition(temp);
    if (internalStorage[index] == nullptr) {
        internalStorage = temp;
    } else {
        long updatedPosition = handleCollision(index);
        if (updatedPosition != -1) {
            internal[updatedPosition] = temp;
        }
    }
}

#endif /* HashTable_hpp */
