// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <limits>  
using namespace std;

int getLength(const char* text)
{
    int count = 0;
    while (text[count] != NULL)
    {
        count++;
    }
    return count;
}

int countLower(const char* fulltext)
{
    int result = 0;
    int n_full = getLength(fulltext);

    for (int i = 0; i < n_full; i++)
    {
        if (fulltext[i] >= 'a' && fulltext[i] <= 'z')
            result++;
    }
    return result;
}

int countmatches(const char* fulltext, const char* subtext)
{
    int n_full = getLength(fulltext);
    int n_sub = getLength(subtext);
    int count = 0;

    printf("Do dai full text: %d \n", n_full);
    printf("Do dai Sub text: %d \n", n_sub);

    //Chay tu 0 đến hết full text
    for (int i = 0; i < n_full; i++)
    {
        //Với từng vị trí, check trùng với subtext 
        for (int j = 0; j < n_sub; j++)
        {
            //nếu phát hiện không trùng thì break vòng for, tiếp tục với i+1 tiếp theo
            if (subtext[j] != fulltext[i + j])
                break;
            //Nếu trùng thì break vòng for, tiếp tục với i+j tiếp theo. Lưu ý do i++ nên chỉ cần +j
            if (j == n_sub - 1)
            {
                count++;
                i = i + j;
                break;
            }
        }
    }
    return count;
}

char* translowerupper(const char* fulltext)
{
    int n_full = getLength(fulltext);
    char* transtext = new char[n_full+1];
    transtext[n_full] = NULL;
    for (int i = 0; i < n_full; i++)
    {
        if (fulltext[i] >= 'a' && fulltext[i] <= 'z')
        {
            transtext[i] = fulltext[i] + ('A' - 'a');
            continue;
        }
        if (fulltext[i] >= 'A' && fulltext[i] <= 'Z')
        {
            transtext[i] = fulltext[i] - ('A' - 'a');
            continue;
        }

        transtext[i] = fulltext[i];
    }
    return transtext;
}

int insochanlonnhat(int* arr, int size)
{
    int result = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0 && arr[i] > result)
            result = arr[i];
    }
    return result;
}

//Viet ham Maxbelow tra ve gia tri lon nhat nho hon A[k]
//Viet ham MinAbove tra ve gia tri nho nhat lon hon A[k]
int MaxBelow(int* arr, int size, int k)
{
    if (k < 0 || k > size)
        return INT_MIN;

    cout << "Vi tri thu k:" << k << endl;
    cout << "Co gia tri:" << arr[k] << endl;
    int pivot = arr[k];
    int result = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < pivot && arr[i] > result)
            result = arr[i];
    }

    return result;
}

int MinBelow(int* arr, int size, int k)
{
    return -1;
}


int main()
{
    const char* fulltext = "123bcbcbcBBBBc";
    const char* subtext = "bcBc";

    int m = countmatches(fulltext, subtext);
    printf("So lan lap: %d \n", m);


    int lower = countLower(fulltext);
    printf("So ky tu thuong: %d \n", lower);

    int number_arr[10] = { 3,58,7,2,7,9,2,56,1,67};
    int sochan = insochanlonnhat(number_arr, 10);
    printf("So chan lon nhat: %d \n", sochan);


    char* trans = translowerupper(fulltext);
    printf("Chuoi text thay doi: %s \n", trans);

    int k = 0;
    cout << "Nhap thu tu k:";
    cin >> k;

    int a[10] = { 4,2,5,7,-3,6,-8,10,4,7 };
    int kqmax = MaxBelow(a, 10, k);
    cout << "Ket qua max below:" << kqmax << endl;


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
