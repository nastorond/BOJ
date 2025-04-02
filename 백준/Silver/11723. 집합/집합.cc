#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void makeAll(unordered_set<int>& numS)
{
    for (int i=1; i<=20; i++)
    {
        numS.insert(i);
    }
}

void doOrder(std::string od, unordered_set<int>& numS, int i)
{
    if (od == "add")
    {
        numS.insert(i);
    }
    else if (od == "remove")
    {
        auto tmp = numS.find(i);
        if (tmp != numS.end()) 
        {
            numS.erase(i);
        }
    }
    else if (od == "check")
    {
        auto tmp = numS.find(i);
        if (tmp == numS.end())
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    else if (od == "toggle")
    {
        auto tmp = numS.find(i);
        if (tmp == numS.end())
        {
            numS.insert(i);
        }
        else
        {
            numS.erase(i);
        }
    }
    else if (od == "empty")
    {
        numS.clear();
    }
    else if (od == "all")
    {
        makeAll(numS);
    }
    else
    {
        // do nothing
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int M;
    unordered_set<int> numSet;
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
        
        doOrder(order, numSet, orderNum);
    }

    return 0;
}