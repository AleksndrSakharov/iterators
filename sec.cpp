#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>

using std::cout;
using std::endl;
using std::sort;
using std::vector;




int main(){
    vector<int> vec = {1, 3, -5, -2, 0, 10, -10};
    std::forward_list<int> list = {1, 3, -5, -2, 0, 10, -10};
    sort(vec.begin(), vec.end());
    sort(list.begin(), list.end()); //FORWARD ACCESS < RANDOM ACCESS
    for(auto it : vec) cout << it << endl; // ВЕКТОР НЕ МЕНЯЕТСЯ
    return 0;
}