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

class ConstIterator{
    public:
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = int;
        using reference = const int&;
        using pointer = const int*;
        ConstIterator(pointer ptr): _ptr(ptr){};
        const reference operator*() const {return *_ptr;};
        const pointer operator->() {return _ptr;};
        ConstIterator& operator++(){_ptr++; return *this;};
        ConstIterator operator++(int){ConstIterator t = *this; ++(*this); return t;};
        friend bool operator==(const ConstIterator& a, const ConstIterator& b){return a._ptr == b._ptr;};
        friend bool operator!=(const ConstIterator& a, const ConstIterator& b){return a._ptr != b._ptr;};
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
    ConstIterator cbegin(){return ConstIterator(&_data[0]);};
    ConstIterator cend(){return ConstIterator(&_data[99]);};
};




int main(){
    IntArr vec;
    for (auto it = vec.cbegin(); it != vec.cend(); it++){
        // *it = 10;
        cout << *it << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <forward_list>

// using std::cout;
// using std::endl;
// using std::sort;
// using std::vector;




// int main(){
//     vector<int> vec = {1, 3, -5, -2, 0, 10, -10};
//     std::forward_list<int> list = {1, 3, -5, -2, 0, 10, -10};
//     sort(vec.begin(), vec.end());
//     sort(list.begin(), list.end()); //FORWARD ACCESS < RANDOM ACCESS
//     for(auto it : vec) cout << it << endl; // ВЕКТОР НЕ МЕНЯЕТСЯ
//     return 0;
// }