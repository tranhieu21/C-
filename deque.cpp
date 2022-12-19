#define AA_DEQUE_H_

#include <string>

template<typename T>
class Deque {
public:

    void push(T);
    void pop();
    void reserve(size_t);
    void resize(size_t, T = T());
    void clear();

    T& front();
    T& back();
    T& at(size_t);
    
private:
    T* container_;
    size_t capacity_;
    size_t size_;
    size_t front_;

    void reallocate();
    void shift_left(size_t, size_t, size_t);
    void shift_right(size_t, size_t, size_t);
    void out_of_range(const char*, size_t, const char*, const char*, size_t) const;
    void check_nonempty() const;
};


template <typename T> void Deque<T>::push(T value) {
    container_[(front_ + size_) % capacity_] = value;
    size_++;
    reallocate();
}

template <typename T> void Deque<T>::pop() {
  check_nonempty();
  size_--;
  front_ = (front_ + 1) % capacity_;
}

template <typename T> void Deque<T>::reserve(size_t capacity) {
    if (capacity <= capacity_) {
    return;
    }
    T* new_container = new T[capacity];
    for (size_t i = 0; i < size_; i++) {
        new_container[i] = container_[(i + front_) % capacity_];
    }
    delete[] container_;
    container_ = new_container;
    capacity_ = capacity;
    front_ = 0;
}

template <typename T> T& Deque<T>::front() {
    check_nonempty();
    return container_[front_];
}

template <typename T> T& Deque<T>::back() {
    check_nonempty();
    return container_[(front_ + size_ - 1) % capacity_];
}

template <typename T> T& Deque<T>::at(size_t index) {
    if (index >= size_) {
        out_of_range("index", index, ">=", "this->size()", size_);
    }
}
