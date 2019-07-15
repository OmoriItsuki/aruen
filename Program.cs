using System;
class Program
{
    static int number = 3;
    static string characters = "多計琳太郎ポリクロ";

    static void Main()
    {
        string answer = Answer(), call;
        int count = 0;
        Console.WriteLine("Game Start");
        do
        {
            call = Input();
            if(call=="give up")
            {
                Console.WriteLine("The answer is {0}. Think the reason why you lost by tomorrow", answer);
                return;
            }
            Check(in answer, in call);
            count++;
        } while (answer != call);

        Console.WriteLine("The answer is {0}: {1} times", answer, count);
    }

    static string Input()
    {
        string call = Console.ReadLine();
        while (true)
        {
            if(call=="give up")
            {
                break;
            }
            if (call.Length != number)
            {
                Console.WriteLine("please input {0} numbers", number);
                call = Console.ReadLine();
                continue;
            }
            for (int i = 0; i < number; i++)
            {
                if (!characters.Contains(call[i].ToString()))
                {
                    Console.WriteLine("There is a character not specified");
                    call = Console.ReadLine();
                    continue;
                }
            }
            break;
        }
        return call;
    }

    static void Check(in string answer, in string call)
    {
        int eat = 0, bite = 0;
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                if (answer[i] == call[j])
                {
                    if (i == j)
                    {
                        eat += 1;
                    }
                    else
                    {
                        bite += 1;
                    }
                }
            }
        }
        Console.WriteLine("{0} eat {1} bite", eat, bite);
    }

    static string Answer()
    {
        string chara = characters;
        string answer = null;
        Random random = new Random();
        for (int i = 0; i < number; i++)
        {
            int n = random.Next(0, chara.Length);
            answer = answer + chara[n];
            chara = chara.Remove(n, 1);
        }
        return answer;
    }
}
