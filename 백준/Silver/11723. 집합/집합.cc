#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makeAll(vector<bool>& b, bool flg)
{
    for (int i=1; i<=20; i++)
    {
        b[i] = flg;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int M;

    vector<bool> bArr;
    bArr.resize(21, false);
    
    std::string order;
    int orderNum = 0;

    cin >> M;

    while (M--)
    {
        cin >> order;
        if (order != "all" && order != "empty")
        {
            cin >> orderNum;
        }
        
        if (order == "empty")
        {
            makeAll(bArr, false);
        }
        else if (order == "all")
        {
            makeAll(bArr, true);
        }
        else if (order == "add")
        {
            bArr[orderNum] = true;
        }
        else if (order == "remove")
        {
            bArr[orderNum] = false;
        }
        else if (order == "check")
        {
            if (bArr[orderNum])
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (order == "toggle")
        {
            bArr[orderNum] = !bArr[orderNum];
        }
        else
        {
            // do nothing
        }
        
    }

    return 0;
}