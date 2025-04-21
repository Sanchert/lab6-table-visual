#pragma once
#include <vector>
#include "Polynomial.h"
#include <iostream>
#include <sstream>
using namespace std;
using namespace Polynomial_;

template <typename TKey, typename TValue>
class UnorderedTable
{
private:
    struct TableRec
    {
        TKey key;
        TValue value;
    };
    std::vector<TableRec> data{};
public:

    UnorderedTable() {};

    size_t GetSize() const { return data.size(); }

    TValue& operator[](size_t pos) { return data[pos].value; }

    void Delete(TKey key)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].key == key)
            {
                data[i] = data[data.size() - 1];
                data.pop_back();
                return;
            }
        }
    }

    TValue* Find(TKey key)
    {
        for (auto& val : data)
        {
            if (val.key == key)
            {
                return &val.value;
            }
        }
        return nullptr;
    }

    void Insert(TKey key, TValue value)
    {
        if (Find(key))
            return;
        data.push_back(TableRec{ key, value });
    }

    void Print() {}

    string GetRec(int ind) {
        std::ostringstream oss;
        oss << data[ind].key << ": " << data[ind].value;
        return oss.str();
    }
};

template <typename TKey, typename TValue>
class UnorderedTableList
{
private:
    struct TableRec
    {
        TKey key;
        TValue value;
    };
    ListI<TableRec> table{};
public:
    UnorderedTableList() {};

    size_t GetSize() const { return table.getSize(); }

    TValue& operator[](size_t pos) { return table[pos].value; }

    void Delete(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                table.removeFrom(i);
                return;
            }
        }
    }

    TValue* Find(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                return &table[i].value;
            }
        }
        return nullptr;
    }

    void Insert(TKey key, TValue value)
    {
        if (Find(key))
            return;
        table.pushBack(TableRec{ key, value });
    }

    void Print()
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            cout << table[i].key << ": " << table[i].value << endl;
        }
    }

    string GetRec(int ind) {
        std::ostringstream oss;
        oss << table[ind].key << ": " << table[ind].value;
        return oss.str();
    }
};


template <typename TKey>
class PolynomialUTable
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };

    std::vector<TableRec> data{};
public:

    PolynomialUTable() {};

    size_t GetSize() const { return data.size(); }

    Polynomial& operator[](size_t pos) { return data[pos].polynomial; }

    void Delete(TKey key)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].key == key)
            {
                data[i] = data[data.size() - 1];
                data.pop_back();
                return;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        for (auto& val : data)
        {
            if (val.key == key)
            {
                return &val.polynomial;
            }
        }
        return nullptr;
    }

    void Insert(TKey key, Polynomial polynomial)
    {
        if (Find(key))
            return;
        data.push_back({ key, polynomial });
    }

    void Print() {}

    void Calculate(Polynomial_::Point p)
    {
        for (auto& val : data)
        {
            val.result = val.polynomial.calculate(p);
        }
    }

    string GetRec(int ind) {
        std::ostringstream oss;
        oss << data[ind].key << ": " << data[ind].polynomial << " = " << data[ind].result;
        return oss.str();
    }
};

template <typename TKey>
class PolynomialUTableList
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };
    ListI<TableRec> table{};
public:
    PolynomialUTableList() {};

    size_t GetSize() const { return table.getSize(); }

    Polynomial& operator[](size_t pos) { return table[pos].polynomial; }

    void Delete(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                table.removeFrom(i);
                return;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                return &table[i].polynomial;
            }
        }
        return nullptr;
    }

    void Insert(TKey key, Polynomial polynomial)
    {
        if (Find(key))
            return;
        table.pushBack({ key, polynomial });
    }

    void Print()
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            cout << table[i].key << ": " << table[i].polynomial << " = " << table[i].result << endl;
        }
    }

    void Calculate(Point p)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            table[i].result = table[i].polynomial.calculate(p);
        }
    }

    string GetRec(int ind) {
        std::ostringstream oss;
        oss << table[ind].key << ": " << table[ind].polynomial << " = " << table[ind].result;
        return oss.str();
    }
};
