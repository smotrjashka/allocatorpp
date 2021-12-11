#include <iostream>
#include <map>
#include "home_map_allocator.h"
#include "simp_param_container.h"

unsigned int factor(unsigned int number){
    unsigned int result = 1;
    for (int i = 2; i <= number; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "HW2!" << std::endl;

    std::map<int, int> map_with_std_allocator;
    std::map<int, int, std::less<int>, home_map_allocator<std::pair<int, int>, 10> > my_map;

    std::cout << "p1!" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "for!" << i << std::endl;
        unsigned int fact = factor(i);
        map_with_std_allocator.insert(std::make_pair(i, fact));
        my_map.emplace(std::make_pair(i, fact));
    }

    std::cout << "p1-p2!" << std::endl;

    std::cout << "stl container" << std::endl;

    auto std_it = map_with_std_allocator.begin();

    while (std_it != map_with_std_allocator.end()){
        std::cout << std_it->first << " " << std_it->second << std::endl;
        std_it++;
    }

    auto my_it = my_map.begin();

    while (my_it != my_map.end()){
        std::cout << my_it->first << " " << my_it->second << std::endl;
        my_it++;
    }

    std::cout << "p2!" << std::endl;
    ///custom container part

    simp_param_container<int> container_with_stl_allocator;
    simp_param_container<int, home_map_allocator<int, 10>> container_with_my_allocator;
    for (int i = 0; i < 10; ++i) {
        container_with_stl_allocator.insert(i);
        container_with_my_allocator.insert(i);
    }


    std::cout << *container_with_stl_allocator.GetLast() << std::endl;
    while (container_with_stl_allocator.hasPrev()){
        std::cout << *container_with_stl_allocator.getPrev() << std::endl;
    }

    std::cout << *container_with_my_allocator.GetLast() << std::endl;
    while (container_with_my_allocator.hasPrev()){
        std::cout << *container_with_my_allocator.getPrev() << std::endl;
    }


    return 0;
}
