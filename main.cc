#include <iostream>

class VirtualParent
{
    public:
        virtual int get_value() { return 1; }
        int another_value() { return 2; }
};

class VirtualInherit : public VirtualParent
{
    public:
        int get_value() override { return 2; }
        int another_value() { return 1; }
};

class NoInherit
{
    public:
        int get_value() { return 0; }
        int another_value() { return 0; }
};

class AnotherNoInherit
{
    public:
        int get_value() { return 10; }
        int another_value() { return 10; }
};

class Empty {};

void print_value(VirtualParent & vp)
{
    std::cout << "Printing value: " << vp.get_value() << " | " << vp.another_value() << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "Hello, world!" << std::endl;

    VirtualParent p{};
    VirtualInherit i{};
    NoInherit n{};

    VirtualParent& i_p = i;

    std::cout << "p: " << p.get_value() << std::endl;
    std::cout << "i: " << i.get_value() << std::endl;
    std::cout << "i_p: " << i_p.get_value() << std::endl;
    std::cout << "n: " << n.get_value() << std::endl;

    print_value(p);
    //print_value(i);
    //print_value(n);

    //std::cout << "Size test: " << sizeof(VirtualParent) << std::endl;
    //std::cout << "Size test: " << sizeof(Empty) << std::endl;
    //std::cout << "Size test: " << sizeof(NoInherit) << std::endl;
}
