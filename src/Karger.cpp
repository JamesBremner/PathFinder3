#include "cPathFinder.h"

namespace raven
{
    namespace graph
    {

        void cPathFinder::contract(int n1, int n2)
        {
            std::string newNodeName = findNode(n1).myName + "_" + findNode(n2).myName;
            int newNodeIndex = findoradd(newNodeName);

            for (auto &e : inlinks(n1))
            {
                int i = srcIndex(e);
                if (i != n2)
                {
                    addLink(i, newNodeIndex);
                }
                removeLink(i, n1);
            }
            for (auto &e : inlinks(n2))
            {
                int i = srcIndex(e);
                if (i != n2)
                {
                    addLink(i, newNodeIndex);
                }
                removeLink(i, n2);
            }
            removeNode(n1);
            removeNode(n2);
        }
        std::vector<std::vector<std::string>>
        cPathFinder::KargerSplitContracted()
        {
            std::vector<std::vector<std::string>> ret;
            for (auto node : nodes())
            {
                std::vector<std::string> v;
                auto n = node.second.myName;
                int q = 0;
                int p = n.find("_");
                while (p != -1)
                {
                    v.push_back(n.substr(q, p - q));
                    q = p + 1;
                    p = n.find("_", q);
                }
                v.push_back(n.substr(q));
                ret.push_back(v);
            }
            return ret;
        }

        /// @brief Cut graph into two components
        /// @param[out] bestcutsize number of edges to cut
        /// @param[in] bestbalance 0: any minimum cut, 1 : min cut with best balance of node counts
        /// @param[out] bestbalance node count in smallest component
        /// @param[in] trialcount
        /// @return 2D vector of names of nodes in each component
        /// https://en.wikipedia.org/wiki/Karger%27s_algorithm
        std::vector<std::vector<std::string>>
        cPathFinder::Karger(
            int &bestcutsize,
            int &bestbalance,
            int trialCount )
        {
            bestcutsize = linkCount();
            bool fbalance = ( bestbalance > 0 );
            bestbalance = 0;
            auto best = *this;
            auto backup = *this;

            srand(time(NULL));

            for (int trial = 0; trial < trialCount; trial++)
            {
                while (nodeCount() > 2)
                {
                    // select random link to contract
                    auto m = links();
                    auto it = std::next(
                        m.begin(),
                        rand() % m.size());
                    contract(
                        it->first.first,
                        it->first.second);
                }
                int cutsize = linkCount();
                if (cutsize < bestcutsize)
                {
                    bestcutsize = cutsize;
                    best = *this;
                }
                if (fbalance && cutsize <= bestcutsize)
                {
                    int balance = backup.nodeCount();
                    for (auto vs : KargerSplitContracted())
                    {
                        if (vs.size() < balance)
                            balance = vs.size();
                    }
                    if (balance > bestbalance)
                    {
                        bestbalance = balance;
                        best = *this;
                    }
                }
                *this = backup;
            }
            return best.KargerSplitContracted();
        }
    }
}
void KargerTest()
{
    std::cout << "Karger Test\n";

    raven::graph::cPathFinder finder;

    finder.addLink("1", "2");
    finder.addLink("1", "3");
    finder.addLink("2", "3");
    finder.addLink("1", "4");
    finder.addLink("2", "5");
    finder.addLink("3", "6");
    finder.addLink("5", "6");
    finder.addLink("4", "6");
    finder.addLink("5", "4");

    std::cout << finder.linksText() << "\n";

    int mincutsize;
    int minComponentSize;
    auto vk = finder.Karger(
        mincutsize,
        minComponentSize,
        20 );

    std::cout << "******\nresult "
              << " cut size " << mincutsize
              << " size of minimum component " << minComponentSize << "\n";
    for (auto &node : vk[0])
        std::cout << node << " ";
    std::cout << "\n";
    for (auto &node : vk[1])
        std::cout << node << " ";
    std::cout << "\n";
}