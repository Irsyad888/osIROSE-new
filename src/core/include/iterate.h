#pragma once

#include <tuple>
#include <memory>
#include <type_traits>

namespace Core {

template <class F, std::size_t... Is>
constexpr auto index_apply_impl(F f, std::index_sequence<Is...>) {
    return f(std::integral_constant<std::size_t, Is>{}...);
}

template <std::size_t N, class F>
constexpr auto index_apply(F f) {
    return index_apply_impl(std::forward<F>(f), std::make_index_sequence<N>{});
}

template <std::size_t N, class Tuple>
constexpr auto take_front(Tuple &t) {
    return index_apply<N>([&](auto... Is) {
            return std::make_tuple(std::get<Is>(t)...);
            });
}

template <class Tuple, class F>
constexpr auto apply(Tuple &t, F &&f) {
    return index_apply<std::tuple_size<Tuple>{}>([&](auto... Is) {
            return f(std::get<Is>(t)...);
            });
}

template <class Tuple>
constexpr auto reverse(Tuple &t) {
    return index_apply<std::tuple_size<Tuple>{}>([&](auto... Is) {
            return std::make_tuple(std::get<std::tuple_size<Tuple>{} - 1 - Is>(t)...);
            });
}

template <class F, class... Ts, std::size_t... Is>
constexpr void for_each_in_tuple(const std::tuple<Ts...> &tuple, F f, std::index_sequence<Is...>) {
    using expander = int[];
    (void) expander{0, ((void)f(Is, std::get<Is>(tuple)), 0)...};
}

template <class F, class... Ts>
constexpr void for_each_in_tuple(const std::tuple<Ts...> &tuple, F f) {
    for_each_in_tuple(tuple, f, std::make_index_sequence<sizeof...(Ts)>());
}

}
