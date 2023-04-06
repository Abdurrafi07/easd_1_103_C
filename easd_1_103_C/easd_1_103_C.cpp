// 1. Karena algorima dapat mempermudah menyelesaikan suatu masalah yang tidak dapat diselesaikan dengan mudah
// 2. Array dan linked
// 3. Waktu, Tingkat Kesulitan, penyimpanan
// 4. Selection sort
// 5. Quadratic :selection sort, insertion sort, shell sort
// Loglinier : quick sort, bubble sort, merge sort

#include <iostream>
using namespace std;

int Rafi[345];
int cmp_count = 0;
int mov_count = 0;
int n;

void input(){
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 345)
			break;
		else
			cout << "\nMaksimum panjang array adalah 345" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int R = 0; R < n; R++)
	{
		cout << "<" << (R + 1) << ">";
		cin >> Rafi[R];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = Rafi[x];
	Rafi[x] = Rafi[y];
	Rafi[y] = temp;
}

void s_sort(int low, int high)
{
	int pivot, R, F;
	if (low > high)
		return;

	pivot = Rafi[low];

	R = low + 1;
	F = high;

	while (R <= F)
	{
		while ((Rafi[R] <= pivot) && (R <= high))
		{
			R++;
			cmp_count++;
		}
		cmp_count++;

		while ((Rafi[F] > pivot) && (F >= low))
		{
			F--;
			cmp_count++;
		}
		cmp_count++;
	

		if (R < F)
		{
			swap(R, F);
			mov_count++;
		}
	}

	if (low < F)
	{
		swap(low, F);
		mov_count++;
	}

	s_sort(low, F - 1);
	s_sort(F + 1, high);
}

void display() {
	cout << "\n------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "------------------" << endl;

	for (int R = 0; R < n; R++)
	{
		cout << Rafi[R] << " ";
	}

	cout << "\n\nNumber of comparasion: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	s_sort(0, n - 1);
	display();
	system("pause");

	return 0;
}