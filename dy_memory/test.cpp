#include <iostream>
using namespace std;


class Stack
{
public:
    Stack(int capacity = 10, int size = 0)
        :_capacity(capacity)
    {
         int* s = new int;
    }

    ~Stack()
    {
        free(s);
        int _capacity = 0;
        int _size = 0;
    }
private:
    int* a;
    int _capacity;
    int _size;
};

int main()
{
     
    return 0;
}
