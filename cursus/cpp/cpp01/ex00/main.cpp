#include "Pony.hpp"

void ponyOnTheStack(void)
{
    Pony stackPony("stackPony");
    stackPony.cry();
    stackPony.eat();
}

void ponyOnTheHeap(void)
{
    Pony *heapPony;

    heapPony = new Pony("heapPony");
    heapPony->cry();
    heapPony->eat();
    delete heapPony;
}

int main(void)
{
    std::cout << "==========ponyOnTheStack============"<< std::endl;
    ponyOnTheStack();
    std::cout << "==========ponyOnTheHeap============="<< std::endl;
    ponyOnTheHeap();
    std::cout << "==========Program End===============" << std::endl;
    return (0);
}