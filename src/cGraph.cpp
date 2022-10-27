#include "cGraph.h"

namespace raven {
namespace graph
{
int source( link_t& link )
{
    return link.first.first;
}
int target( link_t& link ) 
{
    return link.first.second;
}
}
}