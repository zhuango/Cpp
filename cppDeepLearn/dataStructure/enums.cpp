
enum class Color
{
    red,
    blue,
    green
};

int main(void)
{
    // Error! Color -> int.
    //Color y = 7;
    //Color z = red;
    
    // OK
    Color c = Color::red;
    return 0;
}