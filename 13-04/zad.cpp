#include <iostream>

using namespace std;

class Set
{
private:
    int S[10];
    int size;

public:
    Set() : size(0) {}

    void add(int element)
    {
        if (size < 10)
        {
            S[size++] = element;
        }
        else
        {
            cout << "Set is full, cannot add more elements!" << endl;
        }
    }

    Set operator+(const Set &other) const
    {
        Set result;
        for (int i = 0; i < size; ++i)
        {
            result.add(S[i]);
        }
        for (int i = 0; i < other.size; ++i)
        {
            result.add(other.S[i]);
        }
        return result;
    }

    Set operator*(const Set &other) const
    {
        Set result;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < other.size; ++j)
            {
                if (S[i] == other.S[j])
                {
                    result.add(S[i]);
                    break;
                }
            }
        }
        return result;
    }

    bool operator<(const Set &other) const
    {
        for (int i = 0; i < size; ++i)
        {
            bool found = false;
            for (int j = 0; j < other.size; ++j)
            {
                if (S[i] == other.S[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                return false;
            }
        }
        return true;
    }

    bool operator>(const Set &other) const
    {
        return other < *this;
    }

    Set operator++()
    {
        Set result = *this;
        for (int i = 0; i < size; ++i)
        {
            ++S[i];
        }
        return result;
    }

    void print() const
    {
        cout << "{ ";
        for (int i = 0; i < size; ++i)
        {
            cout << S[i] << " ";
        }
        cout << "}" << endl;
    }
};

int main()
{
    Set A, B;

    A.add(1);
    A.add(2);

    B.add(2);
    B.add(3);

    Set sum = A + B;
    cout << "Sum: ";
    sum.print();

    Set intersection = A * B;
    cout << "Intersection: ";
    intersection.print();

    if (A < B)
    {
        cout << "A is a subset of B" << endl;
    }

    if (A > B)
    {
        cout << "A contains all elements which are in set A and B" << endl;
    }

    ++A;
    cout << "A after increment: ";
    A.print();

    return 0;
}
