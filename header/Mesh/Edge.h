#ifndef EDGE_HPP
#define EDGE_HPP
#include "Vertex.h"
class Edge{
private:
    Mesh* e_mesh;

	Vertex* e_origin;
	Vertex* e_end;
public:
	Edge(Mesh* mesh,Vertex& origin,Vertex& end);
	Edge(const Edge& e);
	virtual ~Edge();
	Edge& operator=(const Edge& e);
    Vertex& get_origin();
};
#endif // !EDGE_HPP

