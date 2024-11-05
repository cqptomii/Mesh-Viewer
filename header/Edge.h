#ifndef EDGE_HPP
#define EDGE_HPP
#include "../header/Vertex.h"
class Edge{
private:
	Vertex* e_origin;
	Vertex* e_end;
public:
	Edge();
	Edge(Vertex& origin,Vertex& end);
	Edge(const Edge& e);
	virtual ~Edge();
	Edge& operator=(const Edge& e);
};
#endif // !EDGE_HPP

