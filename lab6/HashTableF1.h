#pragma once
#include <string>
#include "Polynomial.h"

using namespace Polynomial_;
using namespace std;

template<typename TKey, typename TValue>
class HashTableF1
{
private:
    struct TableRec
    {
        bool isFree = true;
        TKey key;
        TValue value;
    };
    int capacity;
    TableRec* table;

    int Hash(TKey key)
    {
        return key % capacity;
    }

    int FindInd(TKey key)
    {
        int ind = Hash(key);
        if (!table[ind].isFree)
        {
            return ind;
        }
        return -1;
    }

public:

    HashTableF1()
    {
        capacity = 32;
        table = new TableRec[capacity];
    }

    ~HashTableF1()
    {
        delete[] table;
    }

    size_t GetCapacity() const
    {
        return capacity;
    }

    TValue& operator[](size_t pos)
    {
        if (pos < capacity)
        {
            return table[pos].value;
        }
        throw out_of_range("Index out of range");
    }

    TValue* Find(TKey key)
    {
        int ind = FindInd(key);
        if (ind != -1)
            return &table[ind].value;
        return nullptr;
    }

    void Insert(TKey key, TValue value)
    {
        int ind = Hash(key);
        if (table[ind].isFree)
        {
            table[ind] = TableRec{ false, key, value };
        }
    }

    void Delete(TKey key)
    {
        int ind = Hash(key);
        table[ind].isFree = true;
    }

    string GetRec(int ind) {
        std::ostringstream oss;
        if (!table[ind].isFree)
        {
            oss << table[ind].key << ": " << table[ind].value << endl;
        }
        else
        {
            oss << "... ..." << endl;
        }
        return oss.str();
    }
};

template<typename TKey>
class PolynomialHashTableF1
{
private:
    struct TableRec
    {
        bool isFree = true;
        TKey key;
        Polynomial value;
        double result;
    };
    int capacity;
    TableRec* table;

    int Hash(TKey key)
    {
        return key % capacity;
    }
    
    int FindInd(TKey key)
    {
        int ind = Hash(key);
        if (!table[ind].isFree)
        {
            return ind;
        }
        return -1;
    }

public:

    PolynomialHashTableF1() :
        capacity(32),
        table(new TableRec[capacity])
    {}

    ~PolynomialHashTableF1()
    {
        delete[] table;
    }

    size_t GetCapacity() const
    {
        return capacity;
    }

    Polynomial& operator[](size_t pos)
    {
        if (pos < capacity)
        {
            return table[pos].value;
        }
        throw out_of_range("Index out of range");
    }

    void Delete(TKey key)
    {
        int ind = Hash(key);
        table[ind].isFree = true;
    }

    Polynomial* Find(TKey key)
    {
        int ind = FindInd(key);
        if (ind != -1)
            return &table[ind].value;
        return nullptr;
    }

    void Insert(TKey key, Polynomial value)
    {
        int ind = Hash(key);
        if (table[ind].isFree)
        {
            table[ind] = TableRec{ false, key, value };
        }
    }

    string GetRec(int ind) {
        std::ostringstream oss;
        if (!table[ind].isFree)
        {
            oss << table[ind].key << ": " << table[ind].value << " = " << table[ind].result << endl;
        }
        else
        {
            oss << "... ... ..." << endl;
        }
        return oss.str();
    }

    void Calculate(Polynomial_::Point p)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (!table[i].isFree)
            {
                table[i].result = table[i].value.calculate(p);
            }
        }
    }
};