using System;
class validate
{
    public static void Main()
    {
        string str_wrench = "ilovemyfamily";
        string str_next = "";
        Console.WriteLine("请输入你的姓名:");
        Console.ReadLine();
        do
        {
            Console.WriteLine("请输入你的密码:");
            string str_passwd = Console.ReadLine();
            if (str_passwd != str_wrench)
            {
                Console.WriteLine("密码不正确,是否继续?Y/N");
            }
            str_next = Console.ReadLine();
        } while (str_next == "y" || str_next == "Y");
    }
}