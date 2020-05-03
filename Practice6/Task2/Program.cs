using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            binarytree<int> tree = new binarytree<int>(100, null);
            for (int i = 0; i <= 110; i += 10)
                tree.Add(i);
            tree.print();
            tree.search(40).print();
        }
    }
}
