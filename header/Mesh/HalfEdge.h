#ifndef HALFEDGE_HPP
#define HALFEDGE_HPP
#include "MeshTriangle.h"
#include "Edge.h"
#include <iostream>

class HalfEdge{
private:
    Mesh* h_mesh; // Maillage associé à la demi arête

	HalfEdge* h_next_halfedge; // Demi arête suivante dans la face
	HalfEdge* h_opposite_halfedge; // Demi arête opposé
    HalfEdge* h_siblings; // Demi arête suivante autour du même sommet

	MeshTriangle* h_face; // triangle à gauche de la demi arête
    Vertex* h_next_vertex; // Sommet suivant
    Edge* h_edge; // arête composant la demi arête

public:
	HalfEdge(Mesh* mesh,Vertex& origin,Vertex& target,MeshTriangle& triangle);
	HalfEdge(const HalfEdge& h);
	virtual ~HalfEdge();
	HalfEdge& operator=(const HalfEdge& h);
    Vertex* get_origin();
    Vertex* get_target();
    MeshTriangle* get_triangle();
    HalfEdge* get_next();
    HalfEdge* get_opposite();
    HalfEdge* get_sibling();
    Edge* get_edge();
    void set_next(HalfEdge* next);
    void set_sibling(HalfEdge* sibling);


};

#endif // !HALFEDGE_HPP

