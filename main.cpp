#include <iostream>
using namespace std;

struct Iterator
{
    using iterator_category = forward_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = int;
    using reference = int&;
    using pointer = int*;
    Iterator(pointer ptr): _ptr(ptr){};
    reference operator*() const {return *_ptr;};
    pointer operator->() {return _ptr;};
    Iterator& operator++(){_ptr++; return *this;};
    Iterator operator++(int){Iterator t = *this; ++(*this); return t;};
    friend bool operator==(const Iterator& a, const Iterator& b){return a._ptr == b._ptr;};
    friend bool operator!=(const Iterator& a, const Iterator& b){return a._ptr != b._ptr;};
    private:
        pointer _ptr;
};

class IntArr
{
private:
    int _data[99];
public:
    Iterator begin(){return Iterator(&_data[0]);};
    Iterator end(){return Iterator(&_data[99]);};//DOPISAT AND PROTESTIT
};




int main(){

    return 0;
}