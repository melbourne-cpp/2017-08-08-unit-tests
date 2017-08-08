template<typename T>
T factorial_recursive(T n) {
    return n < 2 ? 1 : n * factorial_recursive(n-1);
}

template<typename T>
T factorial_iterative(T n) {
    T result = 1;
    for (;n>1;--n)
        result *= n;
    return result;
}
