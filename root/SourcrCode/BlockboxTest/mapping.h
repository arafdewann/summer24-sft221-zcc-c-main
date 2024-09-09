#pragma once
#ifndef MAPPING_H
#define MAPPING_H

#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100
#define BLUE 2
#define GREEN 4
#define YELLOW 8
#define DIVERSION 16

/**
* A map is a 2D raster representation of a map with contents of the map encoded as numeric values.
*/
struct Map
{
	int squares[MAP_ROWS][MAP_COLS];
	int numRows;
	int numCols;
};

/**
* A point represents the row-column position of a square on a map.
*/
struct Point
{
	char row;
	char col;
};

/**
* A route is a collection of points that are adjacent to one another and constitute a path from the
* first point on the path to the last.
*/
struct Route
{
	struct Point points[MAX_ROUTE];
	int numPoints;
	char routeSymbol;
};

/**
* Create a map with the position of all buildings in it.
* @returns - a map with the position of all buildings added to it.
*/
struct Map populateMap();

/**
* Get the number of rows in a map.
* @param map - the map to query
* @returns - the number of rows in the map.
*/
int getNumRows(const struct Map* map);

/**
* Get the number of columns in a map.
* @param map - the map to query
* @returns - the number of columns in the map.
*/
int getNumCols(const struct Map* map);

/**
* Print the map usign the symbols:
* space = open space
* X = building
* B = blue route
* G = green route
* Y = yellow route
* . = B & G routes overlap
* - = B & Y routes overlap
* * = G & Y routes overlap
* + = B & G & Y routes overlap
* P = a shortest path or route from one point to another
* @param map - map to print
* @param base1 - if true print row indices from 1 up otherwise 0 up
* @param alphaCols - if true print col header as letters, otherwise numbers
*/
void printMap(const struct Map* map, const int base1, const int alphaCols);

/**
* Add a route to a map using the indicated symbol.
* @param map - map to add route to
* @param route - the route to add to the map
* @returns a copy of the original map with the route added to it
*/
struct Map addRoute(const struct Map* map, const struct Route* route);

/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPtToRoute(struct Route* route, struct Point pt);

/**
* Add a point to a route if it is not equal to another point.
* @param route - the route to which the point should be added
* @param row - the row of the point to add to the route.
* @param col - the column of the point to add to the route.
* @param notThis - the point will be added to the route ONLY if it is not equal to this point.
*/
void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis);

/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPointToRoute(struct Route* route, const int row, const int col);

/**
* Build and return the route for the blue trucks.
* @returns - the route for the blue trucks.
*/
struct Route getBlueRoute();

/**
* Build and return the route for the green trucks.
* @returns - the route for the green trucks.
*/
struct Route getGreenRoute();

/**
* Build and return the route for the yellow trucks.
* @returns - the route for the yellow trucks.
*/
struct Route getYellowRoute();

/**
* Calculate the Euclidian distance between two points.
* @param p1 - the first point
* @param p2 - the second point
* @returns - the distance between p1 and p2.
*/
double distance(const struct Point* p1, const struct Point* p2);

/**
* Calculate the shortest path between two points so that the path does not pass through buildings.
* @param map - the map showing the location of buildings.
* @param start - the point to start from
* @param dest - the point to go to
* @returns - the shortest path from start to dest. If there is no path, then a Route of zero length is returned.If start
* and dest are the same point, it also returns a Route of zero length.
*/
struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest);

/**
* Calculate all adjacent squares to a given point so that the squares do not overpal a building and do not include the backpath.
* @param map - the map showing the location of buildings.
* @param p1 - the point to calculate possible moves for
* @param backpath - the previous point we visited on the path we travelled so we will exclude travelling backwards.
* @returns - a collection of adjacent points we could potentially move to.
*/
struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath);

/**
* Compare two points for equality.
* @param p1 - the first point
* @param p2 - the second point
* @returns - true if p1 is equal to p2
*/
int eqPt(const struct Point p1, const struct Point p2);

/**
* Calculates the Euclidian distance from every point in a route to a single point and returns the
* index of the point in the route which is closest to the point.
* @param route - the route to use to find the closest point
* @param pt - the point to to find the member of the route which is closest to this point
* @returns - the index of the closest point on the route to the point or -1 if the route is empty.
*/
int getClosestPoint(const struct Route* route, const struct Point pt);

#endif
