#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

template <typename T>
class Queue{
public:

    /** \brief Class constructor
     */
    Queue();

    /** \brief Class destructor
     */
    ~Queue();

    /** \brief Class copy constructor.
     *
     * \param q Queue reference
     *
     */
    Queue(const Queue<T> &q);

    /** \brief Assignation overloaded operator for Queue class.
     *
     * \param q Queue reference
     * \return A queue with items from another queue.
     *
     */
    Queue<T> &operator=(const Queue<T> &q);

    /** \brief Method to add items to the end of queue
     *
     * \param item value.
     *
     */
    void Add(const T &value);

    /** \brief Method to use to remove an item from the queue
     *
     */
    void Remove();

    /** \brief Method to use to get first in queue
     *
     * \return item value.
     *
     */
    T GetFirst();

    /** \brief Method to use to get the last in queue
     *
     * \return item value
     *
     */
    unsigned GetLast();

    /** \brief Method to know if the queue is empty
     *
     * \return boolean that indicates true if queue is empty or false if is not.
     *
     */
    bool ItsEmpty() const;

    /** \brief Method to clear all content in queue
     *
     */
    void Clear();

    /** \brief Method to get size of queue
     *
     */
    unsigned GetSize();

    /** \brief Method to print queue
     *
     */
    void Print();

private:
    struct Item{
        T value;
        Item *next;
        Item(T v, Item *next = NULL): value(v), next(next){}
    };
    Item *bottom;
    int itemNum;

};


#include "Queue.tpp"
#endif // QUEUE_H_INCLUDED
