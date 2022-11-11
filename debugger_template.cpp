#include "bits/stdc++.h"
using namespace std;

// TODO: update to c++20 and get used to this

namespace debugger_template {
template <typename T>
concept ostreamable = requires(T x) {
    std::cout << x;
    std::cerr << x;
};

template <typename T>
concept iterable = requires(T x) {
    x.begin();
    x.end();
};

class view {
   private:
    std::ostream &stream;
    int depth;
    int space;

   public:
    view(std::ostream &stream = std::cerr, int depth = 0, int space = 2)
        : stream(stream), depth(depth), space(space) {}

    view &operator()() { return *this; }

#ifdef local
   public:
    template <typename T>
    requires ostreamable<T> view &operator()(const T &object) {
        stream << object;
        return *this;
    }

    template <typename T>
    requires(iterable<T> and not ostreamable<T>) view &operator()(
        const T &object) {
        operator()("[");
        for (auto element : object) operator()(element, ", ");
        operator()(object.begin() == object.end() ? "]" : "\b\b]");
        return *this;
    }

    template <size_t N, typename... T>
    std::enable_if_t<(sizeof...(T) <= N), view &> operator()(
        const std::tuple<T...> &) {
        return *this;
    }

    template <size_t N, typename... T>
    std::enable_if_t<(sizeof...(T) > N), view &> operator()(
        const std::tuple<T...> &tuple) {
        operator()(std::get<N>(tuple), sizeof...(T) == N + 1 ? "" : ", ");
        operator()<N + 1, T...>(tuple);
        return *this;
    }

    template <typename... T>
    view &operator()(const std::tuple<T...> &tuple) {
        operator()("(");
        operator()<0, T...>(tuple);
        operator()(")");
        return *this;
    }

    template <typename U, typename... V>
    view &operator()(const U &object, const V &... others) {
        static_assert(sizeof...(others) > 0);
        return operator()(object)(others...);
    }

    template <typename U, typename V>
    view &operator()(const std::pair<U, V> &pair) {
        operator()('(', pair.first, ", ", pair.second, ')');
        return *this;
    }

    template <typename T>
    requires(not iterable<T>) view &operator()(const std::vector<T> &vector) {
        operator()("[");

        int index = 0;
        for (auto element : vector) {
            operator()(element, index == int(vector.size()) - 1 ? "" : ", ");
            ++index;
        }

        operator()("]");
        return *this;
    }

    template <typename T>
    requires iterable<T> view &operator()(const std::vector<T> &vector) {
        depth += 1;
        std::string padding(depth * space, ' ');
        operator()("[", !vector.empty() ? "\n" : "");

        int index = 0;
        for (auto element : vector) {
            operator()("  ", padding, "[", index, "]: ", element,
                       index == int(vector.size()) - 1 ? "\n" : ",\n");
            ++index;
        }

        operator()(!vector.empty() ? padding : "", "]");
        depth -= 1;

        return *this;
    }

    template <typename U, typename V>
    view &operator()(const std::map<U, V> &map) {
        depth += 1;
        std::string padding(depth * space, ' ');
        operator()("[", !map.empty() ? "\n" : "");

        int index = 0;
        for (auto &[key, value] : map) {
            operator()("  ", padding, "\"", key, "\": ", value,
                       index == int(map.size()) - 1 ? "\n" : ",\n");
            ++index;
        }

        operator()(!map.empty() ? padding : "", "]");
        depth -= 1;

        return *this;
    }
#else
   public:
    template <typename... T>
    view &operator()(const T &...) {
        return *this;
    }
#endif
};
}  // namespace debugger_template

debugger_template::view debug;
#define print(x) "{\n  \"", #x, "\": ", x, "\n}\n"

int32_t main() {
    int n = 100;
    debug(print(n));
}
