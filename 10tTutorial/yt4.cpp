#include <iostream>
using namespace std;

void print_array(int array[], int size)
{
    cout << sizeof(array) << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    
}

int main()
{
    int guesses[] = {12, 43, 23, 43, 23};
    int size = sizeof(guesses)/sizeof(int);
    print_array(guesses, 5);

    return 0;
}
