#include <iostream>
#include <string>
#include "iter.hpp"

// Printer that accepts const references (works with const arrays too).
template <typename T>
void printElem(T const &x) {
    std::cout << x << " ";
}

// Mutator that requires non-const reference; only works on non-const arrays.
template <typename T>
void increment(T &x) {
    ++x;
}

static void divider(const std::string &title) {
    std::cout << "\n--- " << title << " ---\n";
}

int main() {
    {
        divider("ints");
        int arr[] = {1, 2, 3, 4, 5};
        iter(arr, sizeof(arr)/sizeof(arr[0]), printElem<int>);
        std::cout << "\nApplying increment...\n";
        iter(arr, sizeof(arr)/sizeof(arr[0]), increment<int>);
        iter(arr, sizeof(arr)/sizeof(arr[0]), printElem<int>);
        std::cout << std::endl;
    }
    {
        divider("chars");
        char letters[] = {'a','b','c'};
        iter(letters, sizeof(letters)/sizeof(letters[0]), printElem<char>);
        std::cout << "\nApplying increment...\n";
        iter(letters, sizeof(letters)/sizeof(letters[0]), increment<char>);
        iter(letters, sizeof(letters)/sizeof(letters[0]), printElem<char>);
        std::cout << std::endl;
    }
    {
        divider("const std::string");
        const std::string words[] = {"hello", "42", "porto"};
        iter(words, sizeof(words)/sizeof(words[0]), printElem<std::string>);
        std::cout << std::endl;
        // The following line would fail to compile (as intended) because 'words' is const:
        // iter(words, sizeof(words)/sizeof(words[0]), increment<std::string>);
    }
    return 0;
}
