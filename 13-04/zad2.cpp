#include <iostream>

using namespace std;

class CustomString
{
private:
    char text[100];

public:
    CustomString(const char *s = "")
    {
        int length = 0;
        while (s[length] != '\0')
        {
            ++length;
        }
        for (int i = 0; i < length; ++i)
        {
            text[i] = s[i];
        }
        text[length] = '\0';
    }

    CustomString operator+(const CustomString &other) const
    {
        CustomString result;
        int i = 0;
        while (text[i] != '\0')
        {
            result.text[i] = text[i];
            ++i;
        }
        int j = 0;
        while (other.text[j] != '\0')
        {
            result.text[i + j] = other.text[j];
            ++j;
        }
        result.text[i + j] = '\0';
        return result;
    }

    void print() const
    {
        cout << text << endl;
    }
};

int main()
{
    CustomString A("ALFA");
    CustomString B("BET");

    CustomString C = A + B;

    cout << "A: ";
    A.print();
    cout << "B: ";
    B.print();
    cout << "C: ";
    C.print();

    return 0;
}
