#include <span>
#include <vector>
#include <array>
#include <iostream>

/*
    std::span<T> is a view on a contiguous sequence of data such as
    std::array, std::vector, or std::string. It is never an owner.
    The reasoning for having an std::span<T> is that typical arrays decay
    to a pointer when passed to a function, losing the size.

    std::span<T> Members:
    extent
    T* data_
    size_t size_
*/

// std::span automatically deduces the size of what it is viewing
// It uses a specific constructor depending on the argument type and gets the 
// size from there, there is no pointer decay that occurs
size_t get_integer_span_size(std::span<int> int_view) {
    return int_view.size();
}

int main() {
    int int_arr[4] = {1, 2, 3, 4};
    std::cout << get_integer_span_size(int_arr) << "\n";

    std::vector<int> int_vec = {1, 2, 3, 4};
    std::cout << get_integer_span_size(int_vec) << "\n";

    std::array int_std_arr = {1, 2, 3, 4};
    std::cout << get_integer_span_size(int_std_arr) << "\n";



    return 0;
}