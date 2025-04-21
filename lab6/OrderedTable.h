#pragma once
#include <vector>
#include "Polynomial.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class OrderedTable
{
private:
    struct TableRec
    {
        TKey key;
        TValue value;
    };
    std::vector<TableRec> data{};
public:

    OrderedTable() {};

    size_t GetSize() const { return data.size(); }

    //TValue& operator[](size_t pos) { return *data[pos].value; }

    void Delete(TKey key)
    {
        int middle, left = 0, right = data.size();
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (key < data[middle].key)
                right = middle - 1;
            else if (key > data[middle].key)
                left = middle + 1;
            else
            {
                for (int i = middle; i < data.size() - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                data.pop_back();
                return;
            }
        }
    }

    TValue* Find(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while (left < right)
        {
            middle = (left + right) / 2;
            if (_key < data[middle].key)
                right = middle;
            else if (_key > data[middle].key)
                left = middle + 1;
            else
                return &data[middle].value;
        }
        return nullptr;
    }

    void Insert(TKey _key, TValue value)
    {
        if (!Find(_key))
        {
            data.push_back({ _key, value });

            int left = 0;
            int right = data.size() - 1;
            int mid;
            while (left < right) {
                mid = (right + left) / 2;
                if (data[mid].key > _key)
                    right = mid;
                else
                    left = mid + 1;
            }

            if (left < data.size() - 1) {
                for (int i = data.size() - 1; i > left; i--)
                {
                    data[i] = data[i - 1];
                }
                data[left] = TableRec{ _key, value };
            }
        }
    }

    void Print() {}

    string GetRec(int ind) {
        std::ostringstream oss;
        oss << data[ind].key << ": " << data[ind].value;
        return oss.str();
    }
};

template <typename TKey>
class PolynomialOrdTable
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

    PolynomialOrdTable() {};

    size_t GetSize() const { return data.size(); }

    Polynomial& operator[](size_t pos) { return data[pos].polynomial; }

    void Delete(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (_key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else
            {
                for (int i = middle; i < data.size() - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                data.pop_back();
                return;
            }
        }
    }

    Polynomial* Find(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while (left < right)
        {
            middle = (left + right) / 2;
            if (_key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else
                return &data[middle].polynomial;
        }
        return nullptr;
    }

    void Insert(TKey _key, Polynomial _polynomial)
    {
        if (data.size() == 0)
        {
            data.push_back({ _key, _polynomial, 0 });
        }
        else if (!Find(_key))
        {
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i].key > _key)
                {
                    data.push_back(data[data.size() - 1]);
                    for (int j = data.size() - 1; j > i; j--)
                    {
                        data[j] = data[j - 1];
                    }
                    data[i] = TableRec{ _key, _polynomial, 0 };
                    return;
                }
            }
            data.push_back({ _key, _polynomial, 0 });
        }
    }

    void Print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i].key << ": " << data[i].polynomial << " = " << data[i].result << endl;
        }
    }

    void Calculate(Point p)
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
