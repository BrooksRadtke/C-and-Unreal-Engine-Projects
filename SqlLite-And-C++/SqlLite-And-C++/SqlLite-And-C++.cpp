#include "sqlite3.h"
#include "stdio.h">
#include <iostream>

#ifdef _Debug
#define VERIFY ASSERT
#define VERIFY_(result, expression) ASSERT(result==expression)
#else
#define VERIFY(expression)(expression)
#define VERIFY_(result, expression)(expression)
#endif

struct ConnectionHandleTraits : HandleTraits<sqlite3 *>
{
    static void Close(Type value) noexcept
    {
        VERIFY_(SQLITE_OK, sqlite3_close(value));
    }
};

using ConnectionHandle = Handle<ConnectionHandleTraits>;

int main()
{
   // sqlite3* connection = nullptr;
    ConnectionHandle connection;
    
    // Creating in-memory databasedx`
    int result = sqlite3_open(":memory:", connection.Set());

    // Error handling
    if (SQLITE_OK != result)
    {
        printf("%s\n", sqlite3_errmsg(connection.Get()));
        // Close acts as destructor in C++
        return result;
    }
}