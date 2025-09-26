#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"


int main() {
    Data d; d.id = 42; d.name = "forty-two"; d.value = 4.2;


    uintptr_t raw = Serializer::serialize(&d);
    Data* back = Serializer::deserialize(raw);


    std::cout << "Original ptr: " << &d << "\n";
    std::cout << "Deserialized: " << back << "\n";


    if (back == &d) {
        std::cout << "OK: pointers match\n";
        std::cout << "id=" << back->id << ", name=" << back->name << ", value=" << back->value << "\n";
    } else {
        std::cout << "KO: pointers differ\n";
    }
    return 0;
}
