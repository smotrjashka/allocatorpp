#ifndef ALLOCATOR_HOME_MAP_ALLOCATOR_H
#define ALLOCATOR_HOME_MAP_ALLOCATOR_H

#include "MyPool.h"
#include <stdexcept>

template<typename T, int N>
class home_map_allocator{

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    typedef size_t size_type;

    template<typename U>
    struct rebind{
        using other = home_map_allocator<U, N>;
    };

    // Construct an object of type T at the location of ptr, using the value of U1 in the call to the
    // constructor for T.
    template <class U1>
    void construct(pointer ptr, const U1& val)
    {
        ::new (reinterpret_cast<void*>(ptr)) T(val);
    };


    // Constructors
    home_map_allocator() : pool(MyPool::GetInstance()) {};
    home_map_allocator( const home_map_allocator& other ) : pool(MyPool::GetInstance()) {};

    template <class U1, int M>
    home_map_allocator(const home_map_allocator<U1, M>&) : pool(MyPool::GetInstance()) {};

    // Destructor
    ~home_map_allocator() {};

    // Returns the address of r as a pointer type. This function and the following function are used
    // to convert references to pointers.
    pointer address(reference r) const { return &r; };
    const_pointer address(const_reference r) const { return &r; };

    // Allocate storage for n values of T.
    // wouldnt work with c++17
   // pointer allocate( size_type n, home_map_allocator<void, 0>::const_pointer hint = 0 )
    pointer allocate(std::size_t n)
    {

        if(n>(N* sizeof(T))){
            throw std::out_of_range("we trying to allocate more elements than was parametrised");
        }

        pointer return_value = reinterpret_cast<pointer>( pool.GetNext(n) );

        if ( return_value == 0 )
            throw std::bad_alloc();
        return return_value;
    };

    // Deallocate storage obtained by a call to allocate.
    void deallocate(pointer p, size_type n)
    {
        pool.Free(p);
    };

    // Return the largest possible storage available through a call to allocate.
    size_type max_size() const
    {
        size_type return_value = 0xFFFFFFFF;
        return_value /= sizeof(T);
        return return_value;
    };

    // Construct an object of type T at the location of ptr
    void construct(pointer ptr)
    {
        ::new (reinterpret_cast<void*>(ptr)) T;
    };

    // Construct an object of type T at the location of ptr, using the value of T in the call to the
    // constructor for T.
    void construct(pointer ptr, const T& val)
    {
        ::new (reinterpret_cast<void*>(ptr)) T(val);
    };

    // Call the destructor on the value pointed to by p
    void destroy(pointer p)
    {
        p->T::~T();
    };
private:
    MyPool &pool;
};


// Return true if allocators b and a can be safely interchanged. "Safely interchanged" means that b could be
// used to deallocate storage obtained through a and vice versa.
template <class T1, class T2, int N1, int N2> bool operator == ( const home_map_allocator<T1, N1>& a, const home_map_allocator<T2, N2>& b)
{
    return (N1==N2)&&(sizeof(T1)==sizeof(T2));
};

template <class T1, class T2, int N1, int N2> bool operator != ( const home_map_allocator<T1, N1>& a, const home_map_allocator<T2, N2>& b)
{
    return !(a==b);
};

#endif //ALLOCATOR_HOME_MAP_ALLOCATOR_H
