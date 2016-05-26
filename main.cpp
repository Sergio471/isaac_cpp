#include "isaac.hpp"
#include <iostream> 
#include <unordered_set>
#include <ctime>

using namespace std;

int main()
{ 
    std::srand(std::time(0));
    std::unordered_set<UINT32> nset;
    int a = std::rand(), b = std::rand(), c = std::rand();
    QTIsaac<>  isaac(a, b, c);
    int nOfTrials;

    std::cout << "Enter num of trials: ";
    std::cin >> nOfTrials;
    if (cin.fail())
    {
        std::cout << "Incorrect input. Using default (1 mln)." << std::endl;
        nOfTrials = 1e6;
    }

    int i = 0;
    for (; i < nOfTrials; ++i) 
    {
        UINT32 cur = isaac.rand();

        if (nset.find(cur) != nset.end())
        {
            std::cout << "Period is " << i << std::endl;
            break;
        }
        else
        {
            nset.insert(cur);
        }
    }

    std::cout << "No repetitions in " << i << " trials." << std::endl;
}
