// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename t> class BinaryTree
{
private:
	struct point
	{
		t value;
		int parent = -1;
		int leftchild = -1;
		int rightchild = -1;
	};

	vector<point> tree;
public:
	BinaryTree(t value)
	{
		point x;
		x.value = value;
		tree.push_back(x);
	}
	void Push(t value)
	{
		point x;
		x.value = value;

		bool b = true;
		int i = 0;
		while (b)
		{
			if (x.value <= tree[i].value)
			{
				if (tree[i].leftchild == -1)
				{
					tree[i].leftchild = tree.size();
					x.parent = i;
					tree.push_back(x);
					b = false;
				}
				else
					i = tree[i].leftchild;
			}
			else
			{
				if (tree[i].rightchild == -1)
				{
					tree[i].rightchild = tree.size();
					x.parent = i;
					tree.push_back(x);
					b = false;
				}
				else
					i = tree[i].rightchild;
			}
		}

	}
	void Pop(t value)
	{
		int i = this->Contains(value);
		if (i != -1)
		{
			if (tree[i].leftchild == -1 && tree[i].rightchild == -1)
				tree.erase(tree.begin() + i);
			else
				if (tree[i].leftchild == -1)
				{
					int j = tree[i].rightchild;

					tree[i].value = tree[tree[i].rightchild].value;
					tree[i].value = tree[tree[i].rightchild].rightchild;
					tree[i].value = tree[tree[i].rightchild].leftchild;
					tree[tree[i].rightchild].parent = i;
					tree.erase(tree.begin() + j);
				}
				else
					if (tree[i].rightchild == -1)
					{
						int j = tree[i].leftchild;
						tree[i].value = tree[tree[i].leftchild].value;
						tree[i].value = tree[tree[i].leftchild].rightchild;
						tree[i].value = tree[tree[i].leftchild].leftchild;
						tree[tree[i].leftchild].parent = i;
						tree.erase(tree.begin() + j);
					}
					else
					{
						int j = tree[i].rightchild;
						tree[i].value = tree[tree[i].rightchild].value;
						tree[i].value = tree[tree[i].rightchild].rightchild;
						int z = tree[i].leftchild;
						int z1 = tree[i].leftchild;
						tree[i].value = tree[tree[i].rightchild].leftchild;
						tree[tree[i].rightchild].parent = i;
						tree[tree[i].leftchild].parent = i;
						tree.erase(tree.begin() + j);
						while (tree[z].leftchild != -1)
						{
							z = tree[z].leftchild;
						}
						tree[z].leftchild = z1;
						tree[tree[z].leftchild].parent = z;
					}
		}
	}
	void Print()
	{
		for (int i = 0; i < tree.size(); i++)
			cout << tree[i].value << ' ';
		cout << endl;
	}
	int Contains(t value)
	{
		int i = 0;
		bool b = true;
		int r = -1;
		while (b)
		{
			if (value < tree[i].value)
			{
				if (tree[i].value == value)
				{
					b = false;
					r = i;
				}
				else
					if (tree[i].leftchild == -1)
						b = false;
					else
						i = tree[i].leftchild;
			}
			else
			{
				if (tree[i].value == value)
				{
					b = false;
					r = i;
				}
				else
					if (tree[i].rightchild == -1)
						b = false;
					else
						i = tree[i].rightchild;
			}
		}
		return r;
	}

	void GetLeaf()
	{
		for (int i = 0; i < tree.size(); i++)
			if (tree[i].leftchild == -1 && tree[i].rightchild == -1)
				cout << tree[i].value << ' ';
		cout << endl;
	}
	~BinaryTree()
	{	}
};

int main()
{
	BinaryTree <int> binarytree(2);
	binarytree.Push(10);
	binarytree.Push(1);
	cout << "Your binary tree: ";
	binarytree.Print();
	if (binarytree.Contains(10))
		binarytree.Pop(10);
	else
		cout << "Binary tree does not contain this element";
	cout << "Updated binary tree: ";
	binarytree.Print();
	cout << "List of leaves: ";
	binarytree.GetLeaf();



    //td::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
