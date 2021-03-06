#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdarg.h>
#include <iterator>

#include "errors.h"
#include "listbase.h"
#include "listnode.h"
#include "listiterator.h"

template <typename T>
class List : public ListBase
{
public:
    List();
    explicit List(const List<T> &someList);
    List(List<T> &&someList) noexcept;
    List(std::initializer_list<T> someList);
    List(const T *arr, const int size);
    template <typename T_>
    List(T_ begin, T_ end);
    virtual ~List() = default;

    List<T> &operator=(const List<T> &someList);
    List<T> &operator=(List<T> &&someList) noexcept;
    List<T> &operator=(std::initializer_list<T> someList);

    List<T> &append(const T &data);
    List<T> &operator+=(const T &data);
    List<T> &add(const T &data) const;
    List<T> &operator+(const T &data) const;

    List<T> &reverse();

    List<T> &insert(const T &data, const ListIter<T> &iter);
    List<T> &extend(const List<T> &ListToAdd);
    List<T> &operator+=(const List<T> &someList);
    List<T> &addlist(const List<T> &someList) const;
    List<T> &operator+(const List<T> &somelist) const;

    List<T> &pushBack(const T &data);
    List<T> &pushFront(const T &data);

    //const T pop();
    const T pop();

    const T remove(const ListIter<T> &iter, const int count);
    const T remove(const ListIter<T> &iter);
    size_t remove(const ListIter<T> &begin, const ListIter<T> &end);

    List<T> &clear();

    bool isEqual(const List<T> &someList) const;
    bool operator==(const List<T> &someList) const;
    bool isNotEqual(const List<T> &someList) const;
    bool operator!=(const List<T> &someList) const;

    ListIter<T> begin() noexcept;
    ListIter<T> end() noexcept;
    ConstListIter<T> begin() const noexcept;
    ConstListIter<T> end() const noexcept;
    ConstListIter<T> c_begin() const noexcept;
    ConstListIter<T> c_end() const noexcept;

private:
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

    std::shared_ptr<ListNode<T>> initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode = nullptr);
    void addList(const List<T> &ListToAdd);
    bool isNodesEqual(const List<T> &someList) const;
    bool isEmpty() const;
};

#endif
