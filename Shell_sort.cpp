#include <iostream>
#include <string>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() > b.length())
        return true;
    else if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); ++i)
        {
            if ((a[i] - '0') > (b[i] - '0'))
                return true;
            else if ((a[i] - '0') == (b[i] - '0'))
                continue;
            else
                return false;
        }
    }
    else
        return false;
    return 0;
}

int shellSort(string arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            string temp = arr[i];

            int j;
            for (j = i; j >= gap && compare(arr[j - gap], temp); j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    string* a = new string[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    shellSort(a, n);
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
    delete[] a;
    return 0;

}
