using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> queue1 = new Queue<int>(5);
            Queue<int> queue2 = new Queue<int>(5);
            for (int i = 0; i < 5; i++)
                queue1.Push(i);
            for (int i = 0; i < 5; i++)
                queue2.Push(i);
            Queue<int> queue3 = Queue<int>.queuing(queue1, queue2);
            queue1.Pop();
            for (!queue3.isEmpty())
                Console.WriteLine("{0} ", queue3.Pop());
        }
    }
}
