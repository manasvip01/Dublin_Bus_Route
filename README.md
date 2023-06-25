# Dublin_Bus_Route
Using Dijkstra’s algorithm on the graph, print the optimal sequence of bus stops from a given source to a given destination.

## Description
Dublin Bus Route is a program that utilizes Dijkstra's algorithm to determine the optimal sequence of bus stops from a given source to a given destination in Dublin. The program makes use of real-time updates from Dublin Bus to provide accurate location and expected time of arrival for their buses. By viewing Dublin as a graph consisting of nodes (bus stops) and edges (bus routes), the program calculates the shortest path based on the weights (distances) between the nodes.

## How it works
1. Data Loading:
   - The program loads data from two files: one containing a list of all bus stops in Dublin (nodes), and another containing a list of routes between those bus stops (edges).
   - The weights on the edges represent the distances in meters between each bus stop.
   - Real data is used, which is publicly available through a live API provided by Dublin Bus.

2. Graph Building:
   - Using the loaded data, the program constructs a graph that models the public transport system of Dublin city.
   - Each bus stop is represented as a node, and the routes between bus stops are represented as edges with corresponding weights.

3. Dijkstra's Algorithm:
   - Dijkstra's algorithm is applied to the graph to determine the optimal route from a given source bus stop to a given destination bus stop.
   - The algorithm calculates the shortest path by considering the weights (distances) between the nodes.

4. Output:
   - The program outputs the optimal sequence of bus stops from the source to the destination, taking into account the expected time of arrival based on real-time updates from Dublin Bus.

## Additional Information
- The program uses real-time data provided by Dublin Bus for accurate location and expected time of arrival.
- The provided bus stop and route data is publicly available through a live API, and the program can be extended to incorporate more comprehensive information from the API.
- This project serves as an exercise in applying Dijkstra's algorithm to solve a real-world problem and demonstrates how graph theory can be used to optimize travel routes in Dublin.
- 
## Credits
This project is based on the concept of graph theory and the application of Dijkstra's algorithm to solve the bus route optimization problem. The real-time data used in this project is provided by Dublin Bus through their public API. The project was developed by [Manasvi Prakash] as a programming exercise.

Feel free to extend this project, add more features, or customize it to suit your needs.

Enjoy optimizing your bus routes in Dublin!
