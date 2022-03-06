#include <iostream>
using namespace std;

bool IsAsc(int seq[], int n)
{
    if(seq[0]<seq[n-1])
        return true;
    else
        return false;
}

int SearchBin(int seq[], int n, int x, bool isAsc)
{
    int first=0, last=n;
    bool q=1;
    while(q)
    {
        int mid=(first+last)/2;
        if(first<=last)
        {
            if((x<seq[mid] && isAsc) || (x>seq[mid] && !isAsc))
                last = mid-1;
            else if((x>seq[mid] && isAsc) || (x<seq[mid] && !isAsc))
                first = mid+1;
            else
            {
                q=0;
                return mid;
            }
        }
        else
            q=0;
    }
    return -1;
}



int main()
{
    int m, n, p, x;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        int* seq = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> seq[j];
        }
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            cin >> x;
            cout << SearchBin(seq, n, x, IsAsc(seq, n)) << '\n';
        }
        delete[] seq;
    }
    
    return 0;
}
