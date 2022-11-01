# PathFinder

An Windows desktop GUI application to discover optimum path through graphs of costed links. 

![image](https://user-images.githubusercontent.com/2046227/122287129-9abb3400-cebe-11eb-9095-530755d9447d.png)

To display the graphical representation of the path, graphViz must be installed. https://graphviz.org/download/

## Edit

Menu item `File | Edit` reads a space delimited text file, displays it and allows user to edit it.  Note that the editor is extremely simple, intended only for quick fixes or adjustments.  For more comples tasks, use a fully featured text editor

## Save

Menu item `File | Save` saves file displayed in editor.

## Calculate

Menu item `File | Calulate` reads and calculates path through graph specified in space delimited text file.  

The exact calculation performed is specified by the first line in the file.  

If the calculation is succesful, a graphical display of the graph with the path picked out in red will be shown.

Calculation Options are:

 - __Costs.__ Input specifies undirected links, link costs, starting and ending nodes, then uses the Dijsktra algorithm to find optimal path. [Detailed Documentation](https://github.com/JamesBremner/PathFinder3/wiki/Costs)
 - __Longest__ Input specifies directed links, link costs, starting and ending nodes, then uses a modified Dijsktra algorithm to find longest or most expensive path.  Option to find longest path between any two nodes. [Detailed Documentation](https://github.com/JamesBremner/PathFinder3/wiki/Longest)
 - __Spans__ Input specifies undirected links, with costs then uses Pim's algorithm to find minimum cost links that connect all nodes together. [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Spans)
 - __Sales__  Input specifies undirected links, with costs then finds a route that will visit every node once. [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Sales)
 - __Cams__ Find a set of nodes that cover every link.  Input specifies undirected links.  [Detailed Documentation](https://github.com/JamesBremner/PathFinder3/wiki/Cams)
 - __Cliques__ Find the set of maximal cliques in a graph. [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Cliques)
 - __Flows__ Find maximum flow through a graph.  [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Flows)
 - __Water__ Calulate shortest time to flow though pipe network with timed valve openings.
 - __Hills__ Find easiest path through hilly terrain. [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Hills)
 - __Prerequistes__ Finds paths through ordered requirements. "Before you can do B, you must have done A" [Detailed Documentation](https://github.com/JamesBremner/PathFinder2/wiki/Prerequisites)
 - __Maze__ Finds the path through a 2D grid maze. [Detailed Documentation](https://github.com/JamesBremner/PathFinder/wiki/Maze)
 - __Pickup__  Find reasonable routes for drivers that must pickup cargos and deliver them to locations. [Detailed Documentation](https://github.com/JamesBremner/PathFinder/wiki/Pickup)
  - __Allocation__ Finds an allocation of agents to tasks that optimizes the number of tasks completed. [Detailed Documentation](https://github.com/JamesBremner/PathFinder3/wiki/Allocation)
  - __Probabilities__ Finds the probability that an end node can be reached when links are available with specified probability. [Detailed Documentation](https://github.com/JamesBremner/PathFinder3/wiki/Probabilities)

## Installation

 - Download load most recent release from https://github.com/JamesBremner/PathFinder/releases
 - Unzip
 - Double click file `PathFinder.exe`.

