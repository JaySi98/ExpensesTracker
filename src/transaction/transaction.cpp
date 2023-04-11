#include <transaction/transaction.hpp>

namespace transaction
{
    bool operator < (const transaction& left, const transaction& right)
    {
        return left.id < right.id;        
    }

    bool operator == (const transaction& left, const transaction& right)
    {
        return left.id == right.id;        
    }

} // namespace transaction
