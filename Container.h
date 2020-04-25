#ifndef CONTAINER_H
#define CONTAINER_H
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;
/*
If there's an error like this -> #include<ext/pb_ds/assoc_container.hpp>
Error was "cannot open source file hash_standard_resize_policy_imp.hpp ".
Then go to dir -> C:\MinGW\lib\gcc\mingw32\8.2.0\include\c++\ext\pb_ds\detail\resize_policy
Rename -> "hash_standard_resize_policy_imp.hpp0000644" to "hash_standard_resize_policy_imp.hpp"
*/

template<typename T>
class Container{
public:
    Container() = default;

    /* Добавление элемента по универсальной ссылке.
     * Сложность O(logN)
     * */
    template <typename T1>
    void insert(T1&& obj)
    {
        m_container.insert(obj);
    }

    /* Поиск элемента по индексу
     * в отсортированном по неубыванию множестве.
     * Сложность O(logN)
     * */
    T at(int index) {
        if(index > m_container.size())
            throw std::out_of_range("Error: index out of range");
        return *m_container.find_by_order(index); }

    /* Поиск индекса элемента
     * в отсортированном по неубыванию множестве.
     * Сложность O(logN)
     */
    int find(T obj) { return m_container.order_of_key(obj); }

    /* Количество элементов в контейнере
     * Сложность O(1)
     * */
    int size() { return m_container.size(); }

    /* Отрезание контейнера в виде копии
     * Сложность O(MlogN), где M - размер копии
     * */
    Container split(int index)
    {
        Container<T> newContainer;
        for(int i = index; i < m_container.size(); ++i)
        {
            newContainer.insert(this->at(i));
        }
        return newContainer;
    }

    /* Построение объекта из аргументов
     * Сложность O(logN)
     * */
    template <class... Args>
    void emplace(Args...args)
    {
        insert(T(args...));
    }
private:
    tree< T, null_type,
    std::less<T>,rb_tree_tag,
    tree_order_statistics_node_update>
    m_container;
};

#endif //CONTAINER_H
