#include <iostream>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;

int main() {
    // Use smart pointers whenever possible

    // Only one unique pointer can point to an address
    std::unique_ptr<int> c;
    if (c){
        std::cout << "*c : " << *c << std::endl;
    } else {
        std::cout << "c is empty" << std::endl;
    }

    // Changing value
    c.reset(new int(2));
    if (c){
        std::cout << "*c : " << *c << std::endl;
    } else {
        std::cout << "c is empty" << std::endl;
    }

    // Invalid:
    // c = new int(2);

    // Another unique pointer
    std::unique_ptr<int> c2(new int(3));

    // Invalid:
    // c = c2; doesn't work

    // Swapping values is valid
    c.swap(c2);

    // Moving values is valid
    c = std::move(c2);
    if (c){
        std::cout << "New *c : " << *c << std::endl;
    } else {
        std::cout << "c is empty" << std::endl;
    }

    if (c2){
        std::cout << "New *c2 : " << *c << std::endl;
    } else {
        std::cout << "c2 is empty" << std::endl;
    }

    // Shared pointers
    // - More than one pointer can point to the same address
    // - Deletes data automatically when the last pointer is over
    // - More expensive than unique pointers
    std::shared_ptr<int> sp(new int(2));
    if (sp){
        std::cout << "New *sp : " << *sp << std::endl;
    } else {
        std::cout << "sp is empty" << std::endl;
    }

    // Another pointer
    // This is valid now:
    std::shared_ptr<int> sp2 = sp;
    *sp2 = 3;
    if (sp){
        cout << "New *sp : " << *sp << endl;
    } else {
        cout << "sp is empty" << endl;
    }
    if (sp2){
        cout << "New *sp2 : " << *sp << endl;
    } else {
        cout << "sp2 is empty" << endl;
    }

    // How many pointers are pointing to this number 3?
    std::cout << "There are " << sp.use_count() << " pointers to " << sp.get() << std::endl;

    return 0;
}