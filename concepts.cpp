#include <concepts>
#include <type_traits>

/*
    Templates accept anything for T, such as
    std::array or std::vector, which can lead
    to errors. For example add_nums() can accept
    std::vector<int> for both arguments and adding
    two std::vector<int> objects isn't allowed.
*/
template <typename T>
T add_nums(T x, T y) {
    return x + y;
}

/*
    Concepts allow the programmer to put type
    requirements on templated function or class
    to make it only accept those types for the
    arguments

    In this example, this templated type requires
    that it is an integral type using a requires
    clause.
*/
template <typename T>
    requires std::integral<T>
T add_nums_concepts(T x, T y) { return x + y; }

/*
    You can also write your own concepts as shown below
*/

template <typename T>
concept Player = requires(T& player) {
    { player.score() } -> std::is_convertible<typename From, typename To>
}