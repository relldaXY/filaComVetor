//! Copyright 2017
/*!
*   author relldaXY
*   since 03/17/2017
*   version 1.0
*/
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
//! ArrayQueue Class.
/*!
    this class work like a queue. the first data that get in is the first data to out. 
    we have methods like remove, insert, get data and some like that. It's similar like a stack 
*/
class ArrayQueue {
 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_SIZE = 10u;

 public:
    //! Constructor.
    /*!
       Inicialize the queue 
    */
    ArrayQueue() {
        max_size_ = DEFAULT_SIZE;
        contents = new T[max_size_];
        size_ = -1;
    }
    //! Constructor.
    /*!
       Inicialize the queue 
    */
    explicit ArrayQueue(std::size_t max) {
        max_size_ = max;
        contents = new T[max_size_];
        size_ = -1;
    }
    //! Destructor.
    ~ArrayQueue() {
        delete []contents;
    }
    //! method enqueue.
    /*!
       add elements to contents
    */
    void enqueue(const T& data) {
        if (full()) {
            throw std::out_of_range("full queue");
        } else {
            contents[++size_] = data;
        }
    }
    //! method dequeue.
    /*!
       the first element from queue get out and the others elements shift to begin of the queue 
    */
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("empty queue");
        } else {
            T firstElement = contents[0];
            for (int i = 0; i< size_; i++) {
                contents[i] = contents[i+1];
            }
            --size_;
            return firstElement;
        }
    }
    //! method back.
    /*!
       return the last element from queue 
    */
    T& back() {
        if (empty()) {
            throw std::out_of_range("empty queue");
        } else {
            return contents[size_];
        }
    }
    //! method clear.
    /*!
        clear the queue 
    */
    void clear() {
        if (empty()) {
            throw std::out_of_range("empty queue");
        } else {
            size_ = -1;
        }
    }
    //! method size.
    /*!
       return the size from queue 
    */
    std::size_t size() {
        return size_+1;
    }
    //! method max size.
    /*!
       return the queue 
    */
    std::size_t max_size() {
        return max_size_;
    }
    //! method empty.
    /*!
       Is the queue is empty? 
    */
    bool empty() {
        return size_ == -1;
    }
    //! method full.
    /*!
       Is the queue is full? 
    */
    bool full() {
        return size_ == (max_size_ -1);
    }
};

}  // namespace structures

#endif
