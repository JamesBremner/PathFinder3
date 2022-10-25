#include <queue>
#include "cPathFinder.h"

namespace raven
{
    namespace graph
    {
        void cPathFinder::EdmondsKarp()
        {
            // https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm

            while (true)
            {
                myPred.clear();
                myPred.resize(nodeCount(), -1);
                std::queue<int> Q;
                Q.push(myStart);
                while (Q.size())
                {
                    int cur = Q.front();
                    Q.pop();
                    cNode curN = findNode(cur);
                    for (auto &l : curN.myLink)
                    {
                        int t = l.first;
                        if (t == myStart)
                            continue;
                        // check link has unused capacity
                        if (l.second.myCost <= l.second.myValue)
                            continue;
                        myPred[t] = cur;
                        Q.push(t);
                    }
                }
                if (myPred[myEnd] == -1)
                    break;

                int pathFlow = 1e6;
                int cur = myEnd;
                while (true)
                {
                    auto &l = findLink(myPred[cur],cur);
                    if (l.myCost - l.myValue < pathFlow)
                        pathFlow = l.myCost - l.myValue;
                    cur = myPred[cur];
                    if (cur == myStart)
                        break;
                }
                cur = myEnd;
                while (true)
                {
                    auto &l = findLink(myPred[cur],cur);
                    l.myValue += pathFlow;
                    cur = myPred[cur];
                    if (cur == myStart)
                        break;
                }
            }
        }
    }
}