#define UNIT_TEST

template<typename T>
class DefenderT
{
    public:
    friend T;
    void Defence(int x, int y){}
    void Tackle(int x, int y){}
    
    private:
    int pos_x = 15;
    int pos_y = 0;
    int speed = 2;
    int stamina = 120;
};

template<typename T>
class AttackerT
{
    public:
    friend T;
    void Move(int x, int y){}
    void SpeedUp(float ratio){}

    private:
    int pos_x = 0;
    int pos_y = -30;
    int speed = 100;
    int stamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

#ifdef UNIT_TEST
class Validator;

using DefenderTest = DefenderT<Validator>;
using AttackerTest = AttackerT<Validator>;
class Validator
{
    public:
    void Validate(int x, int y, DefenderTest &d){}
    void Validate(int x, int y, AttackerTest &a){}
};

#endif

int main(void)
{
    DefenderTest d;
    AttackerTest a;
    a.Move(15, 30);
    d.Defence(15, 30);
    a.SpeedUp(1.5f);
    d.Defence(15, 30);

    Validator v;
    v.Validate(7, 0, d);
    v.Validate(1, -10, a);

    return 0;
}