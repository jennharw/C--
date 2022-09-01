#include "Ranges.h"

Ranges::Ranges(unsigned begin, unsigned end)
    : _begin(begin), _end(end)
{

}

Ranges::Iterator Ranges::begin() const
{
    return Iterator(_begin);
}

Ranges::Iterator Ranges::end() const
{
    return Iterator(_end);
}

Ranges::Iterator::Iterator(unsigned num)
    : _num(num)
{
}

Ranges::Iterator Ranges::Iterator::operator++()
{
    ++_num;
    return *this;
}

bool Ranges::Iterator::operator==(const Iterator& other) const
{
    return _num == other._num;
}

bool Ranges::Iterator::operator!=(const Iterator& other) const
{
    return _num != other._num;
}

unsigned Ranges::Iterator::operator*() const
{
    return _num;
}

// output iterator
// *iter = value
// cout

// input iterator
// value = *iter
// cin

// forward iterator
// - forward_list, unordered xxx
// ++ ÀüÁø ¹Û¿¡ ¾È µÊ

// bidirectional iterator
// - list, set, map, multiset, multimap
// ++, --

// random access iterator
// - array, vector, deque
// ++, --, +, -


// continguous access iterator (C++20)
// - array, vector
// ++, --, +, -, physical memory contiguous