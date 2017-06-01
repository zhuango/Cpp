class Poly;
typedef Poly P;

class LiLei
{
    friend class Poly;
};

class Jim
{
    // error in C++98, must have class key word.
    friend Poly;
};

class HanMeiMei
{
    // error in C++98, must have class key word.
    friend P;
};

template<typename T>
class FriendTemplate
{
    friend T;
};

int main(void)
{
    // Poly is a friend of FriendTemplate.
    FriendTemplate<Poly> p;
    FriendTemplate<int> pp;
    return 0;
}