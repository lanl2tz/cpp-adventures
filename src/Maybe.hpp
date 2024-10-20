/**
 * This is a really easy implementation of the Maybe monad in Haskell
 * using variant.
 *
 * Used modern methods from std::variant:
 *   1. std::variant<T>
 *   2. auto func()->decltype()
 *   3. std::holds_alternative<T>(std::variant<T>)
 */

#include <stdio.h>
#include <variant>

template <typename T>
using Maybe = std::variant<T, bool>;

// Example 1: Data wrapping, T needs isValid() member.
struct Data
{
    int data;
    bool isValid() const
    {
        return data > 0;
    }
};

template <typename T>
auto wrapper(const T &data) -> Maybe<T>
{
    if (data.isValid())
    {
        return data;
    }
    return data.isValid();
}

void testWrapper(const Data &data)
{
    if (std::holds_alternative<Data>(wrapper<Data>(data)))
    {
        printf("Data holds an integer > 0!\n");
    }
    else
    {
        printf("Data holds an integer <= 0!\n");
    }
}

void test()
{
    Data dataA = {1};
    Data dataB = {0};
    testWrapper(dataA);
    testWrapper(dataB);
}