using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1
{
    class Queue<T> 
    {
        T[] array;
        int head, tail;
        bool isLooped;

       public bool isFull() => this.head == this.tail && this.isLooped;
       public bool isEmpty() => this.head == this.tail && !this.isLooped;

        public Queue(int size)
        {
            this.array = new T[size];
            this.head = this.tail = 0;
            this.isLooped = false;
        }

        public void Push(T element)
        {
            if (this.isFull())
                throw new InvalidOperationException();
            this.array[this.tail] = element;
            this.tail = (this.tail + 1) % this.array.Length;
            if (this.tail == 0)
                this.isLooped = true;
        }

        public T Pop()
        {
            if (this.isEmpty())
                throw new InvalidOperationException();
            T element = this.array[this.head];
            this.head = (this.head + 1) % this.array.Length;
            if (this.head == 0)
                this.isLooped = false;
            return element;
        }

        public static Queue<T> queuing(Queue<T> a, Queue<T> b)
        {
            int size = a.array.Length + b.array.Length;
            Queue<T> queue = new Queue<T>(size);
            int pointer = a.head;
            bool isLooped = false;
            while (pointer != a.tail || isLooped != a.isLooped)
            {
                queue.Push(a.array[pointer]);
                pointer = (pointer + 1) % a.array.Length;
                if (pointer == 0)
                    isLooped = true;
            }
            pointer = b.head;
            isLooped = false;
            while (pointer != b.tail || isLooped != b.isLooped)
            {
                queue.Push(b.array[pointer]);
                pointer = (pointer + 1) % b.array.Length;
                if (pointer == 0)
                    isLooped = true;
            }
            return queue;
        }

     
    }
}
