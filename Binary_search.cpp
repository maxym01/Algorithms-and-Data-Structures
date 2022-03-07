#include <iostream>
using namespace std;

class Seq
{
    bool isAsc;
    int* body;
    int size;
public:
    Seq();
    int SearchBin(int x);
    ~Seq();
};

Seq::Seq()
{
    cin >> size;
    body = new int[size];
    for (int i = 0; i < size; i++)
        cin >> body[i];
    if (body[0] < body[size - 1])
        isAsc=true;
    else
        isAsc=false;
}

int Seq::SearchBin(int x)
{
    int first = 0, last = size;
    bool q = 1;
    while (q)
    {
        int mid = (first + last) / 2;
        if (first <= last)
        {
            if ((x < body[mid] && isAsc) || (x > body[mid] && !isAsc))
                last = mid - 1;
            else if ((x > body[mid] && isAsc) || (x < body[mid] && !isAsc))
                first = mid + 1;
            else
            {
                q = 0;
                return mid;
            }
        }
        else
            q = 0;
    }
    return -1;
}

Seq::~Seq()
{
    delete[] body;
}

int main()
{
    int m, n, p, x;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Seq seq;
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            cin >> x;
            cout << seq.SearchBin(x) << '\n';
        }
    }

    return 0;
}
