#include "BinarySearchTree.h"
#include <iostream>

int main()
{
    BinarySearchTree bst;

    // Demonstracja rekurencyjnych operacji
    std::cout << "Rekurencyjne operacje:\n";
    bst.insertRec(50);
    bst.insertRec(30);
    bst.insertRec(70);
    bst.insertRec(20);
    bst.insertRec(40);
    bst.insertRec(60);
    bst.insertRec(80);

    std::cout << "Wyszukiwanie (Rekurencyjne): 40 znajduje się w drzewie? "
              << (bst.searchRec(40) ? "Tak" : "Nie") << std::endl;
    std::cout << "Minimalna wartość (Rekurencyjne): " << bst.findMinRec() << std::endl;
    std::cout << "Maksymalna wartość (Rekurencyjne): " << bst.findMaxRec() << std::endl;

    bst.removeRec(70); // Usuwanie elementu 70
    std::cout << "Po usunięciu 70, czy 70 jest w drzewie? "
              << (bst.searchRec(70) ? "Tak" : "Nie") << std::endl;

    // Czyszczenie drzewa
    bst.removeRec(50);
    bst.removeRec(30);
    bst.removeRec(20);
    bst.removeRec(40);
    bst.removeRec(60);
    bst.removeRec(80);

    // Demonstracja iteracyjnych operacji
    std::cout << "\nIteracyjne operacje:\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Wyszukiwanie (Iteracyjne): 40 znajduje się w drzewie? "
              << (bst.search(40) ? "Tak" : "Nie") << std::endl;
    std::cout << "Minimalna wartość (Iteracyjne): " << bst.findMin() << std::endl;
    std::cout << "Maksymalna wartość (Iteracyjne): " << bst.findMax() << std::endl;

    bst.remove(70); // Usuwanie elementu 70
    std::cout << "Po usunięciu 70, czy 70 jest w drzewie? "
              << (bst.search(70) ? "Tak" : "Nie") << std::endl;

    return 0;
}
