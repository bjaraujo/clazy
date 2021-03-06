#include <QtCore/QObject>
#include <QtCore/QString>

struct SmallTrivial
{
    int v;
};

struct BigTrivial
{
    int v[10];
};

struct NonTrivial
{
    int v;
    ~NonTrivial() {}
};

struct NonTrivial2
{
    int v;
    NonTrivial2() {}
    NonTrivial2(const NonTrivial2 &) {}
};

void test()
{
    auto a = new SmallTrivial(); // Warn
    auto b = new BigTrivial();
    auto c = new NonTrivial();
    auto d = new NonTrivial2();

    auto e = new(0) SmallTrivial;
    auto f = new SmallTrivial[100];

}
