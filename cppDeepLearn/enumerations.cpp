namespace CardGane_Scoped
{
    //the first value is assigned 0
    enum class Suit { Diamonds, Hearts, Clubs, Spades };
    //enum class Suit { Diamonds = 5, Hearts, Clubs = 4, Spades }; // 5, 6, 4, 5

    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs)//
        {
            cout << "play." << endl;
        }
    }
    void testAssign()
    {
        int account_num = Hearts;//not allowed, need a cast
    }
}

namespace GardGame_NonScoped
{
    //the first value is assigned 0
    enum Suit { Diamonds, Hearts, Clubs, Spades };
    //enum Suit { Diamonds = 5, Hearts, Clubs = 4, Spades }; // 5, 6, 4, 5

    void PlayCard(Suit suit)
    {
        if (suit == Clubs)//
        {
            cout << "play." << endl;
        }
    }
    void testAssign()
    {
        int account_num = 13345345;
        Suit hand;
        hand = account_num;//not allowed.
        int account_num = Hearts; //OK if Hearts is in a unscoped enum
    }
}

namespace ScopedEnumConversions
{
    enum class Suit{ Diamonds, Hearts, Clubs, Spades };

    void AttemptConversion()
    {
        Suit hand;

        hand = Clubs;//error C2065: 'Clubs' : undeclared identifier
        hand = Suit::Clubs;//Correct

        int account_num = 12323432;
        hand = account_num; //error C2440: '=' : connot convert from 'int' to 'Suit'
        hand = static_cast<Suit>(account_num); //OK, but probably a bug!!!

        account_num = Suit::Hearts; // error C2440: '=' : cannot convert from 'Suit' to 'int'  
        account_num = static_cast<int>(Suit::Hearts); // OK  
    }
}