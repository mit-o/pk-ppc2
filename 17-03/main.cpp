// main.cpp
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
    SinglyLinkedList sList;
    DoublyLinkedList dList;

    // Dodawanie elementów do listy jednokierunkowej
    sList.push_front(1);
    sList.push_back(2);
    sList.push_front(3); // Lista: 3, 1, 2

    // Dodawanie elementów do listy dwukierunkowej
    dList.push_front(1);
    dList.push_back(2);
    dList.push_front(3); // Lista: 3, 1, 2

    // Wyszukiwanie wartości w liście jednokierunkowej
    int searchValue = 2;
    std::cout << "Lista jednokierunkowa: ";
    sList.print();
    if (sList.search(searchValue))
    {
        std::cout << "Znaleziono wartość " << searchValue << " w liście jednokierunkowej." << std::endl;
    }
    else
    {
        std::cout << "Nie znaleziono wartości " << searchValue << " w liście jednokierunkowej." << std::endl;
    }

    // Wyszukiwanie wartości w liście dwukierunkowej
    searchValue = 3;
    std::cout << "Lista dwukierunkowa: ";
    dList.print();
    if (dList.search(searchValue))
    {
        std::cout << "Znaleziono wartość " << searchValue << " w liście dwukierunkowej." << std::endl;
    }
    else
    {
        std::cout << "Nie znaleziono wartości " << searchValue << " w liście dwukierunkowej." << std::endl;
    }

    std::cout << "Lista jednokierunkowa przed usunięciem: ";
    sList.print();
    std::cout << "Lista dwukierunkowa przed usunięciem: ";
    dList.print();

    sList.remove_front(); // Usuwa 3
    sList.remove_back();  // Usuwa 2
    sList.push_front(5);  // Dodaje na początek
    sList.remove(1);      // Usuwa 1 (środek)

    // Usuwanie elementów z listy dwukierunkowej
    dList.remove_front(); // Usuwa 3
    dList.remove_back();  // Usuwa 2
    dList.push_front(5);  // Dodaje na początek
    dList.remove(1);      // Usuwa 1 (środek)

    // Wyświetlanie list po usunięciach
    std::cout << "Lista jednokierunkowa po usunięciu: ";
    sList.print();
    std::cout << "Lista dwukierunkowa po usunięciu: ";
    dList.print();

    // Dodawanie nowych elementów na koniec list
    sList.push_back(8); // Dodaje 8 na koniec listy jednokierunkowej
    dList.push_back(8); // Dodaje 8 na koniec listy dwukierunkowej

    // Wyświetlanie zawartości list po dodaniu elementów na koniec
    std::cout << "Lista jednokierunkowa po dodaniu na koniec: ";
    sList.print();
    std::cout << "Lista dwukierunkowa po dodaniu na koniec: ";
    dList.print();

    return 0;
}
