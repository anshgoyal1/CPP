#include <iostream>
using namespace std;
#define BIT_LEN 32

void set_bit(int *n, int b)
{
    *n |= (1 << b);
}
void unset_bit(int *n, int b)
{
    *n &= ~(1 << b);
}
int get_bit(int *n, int b)
{
    return *n & (1 << b);
}

int True(int *bits, int *known, int b)
{
    return get_bit(bits, b) && get_bit(known, b);
}

int False(int *bits, int *known, int b)
{
    return !get_bit(bits, b) && get_bit(known, b);
}

void clear(int *bits, int *known)
{
    int i;
    cin >> i;
    unset_bit(bits, i);
    set_bit(known, i);
}

void set(int *bits, int *known)
{
    int i;
    cin >> i;
    set_bit(bits, i);
    set_bit(known, i);
}

void Or(int *bits, int *known)
{
    int i, j;
    cin >> i >> j;
    if (True(bits, known, i) || True(bits, known, j))
    {
        set_bit(bits, i);
        set_bit(known, i);
    }
    else if (False(bits, known, i) && False(bits, known, j))
    {
        unset_bit(bits, i);
        set_bit(known, i);
    }
    else
    {
        unset_bit(known, i);
    }
}

void And(int *bits, int *known)
{
    int i, j;
    cin >> i >> j;
    if (True(bits, known, i) && True(bits, known, j))
    {
        set_bit(bits, i);
        set_bit(known, i);
    }
    else if (False(bits, known, i) || False(bits, known, j))
    {
        unset_bit(bits, i);
        set_bit(known, i);
    }
    else
    {
        unset_bit(known, i);
    }
}

void print(int *bits, int *known)
{
    char buffer[BIT_LEN + 1];
    buffer[BIT_LEN] = '\0';
    for (int i = 0; i < BIT_LEN; i++)
    {
        if (True(bits, known, i))
            buffer[BIT_LEN - 1 - i] = '1';
        else if (False(bits, known, i))
            buffer[BIT_LEN - 1 - i] = '0';
        else
            buffer[BIT_LEN - 1 - i] = '#';
    }
    cout << buffer;
}

int main()
{
    int n, bits = 0, known = 0;
    cin >> n;
    while (n--)
    {
        string command;
        cin >> command;
        if (command[0] == 'C')
            clear(&bits, &known);
        else if (command[0] == 'S')
            set(&bits, &known);
        else if (command[0] == 'O')
            Or(&bits, &known);
        else
            And(&bits, &known);
    }
    print(&bits, &known);
    return 0;
}
