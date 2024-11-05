#ifndef HALFEDGE_HPP
#define HALFEDGE_HPP
#include "../header/MeshTriangle.h"
#include "../header/Edge.h"

class HalfEdge{
private:
	Vertex* h_origin;
	Edge* h_edge;
	HalfEdge* h_next;
	HalfEdge* h_opposite;
	MeshTriangle* h_face;
public:
	HalfEdge();
	HalfEdge(const HalfEdge& h);
	virtual ~HalfEdge();
	HalfEdge& operator=(const HalfEdge& h);

};

#endif // !HALFEDGE_HPP

