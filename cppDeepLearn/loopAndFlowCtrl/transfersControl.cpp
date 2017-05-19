int main(void)
{
    char MyArray[5] = {'2', '2', 'a', 'c'};
    int i = 0;
    while(1)
    {
        int total=0;

        char ch = MyArray[i++];
        if(ch >= '0' && ch <= '9')
        {
            goto Label1;

            int i = ch - '0';//illegal
            //int i;//legal

        Label1:
            total += i;
        }
        else
        {
            break;
        }
    }

    return 0;
}