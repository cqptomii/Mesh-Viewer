#ifndef MESHTRIANGLE_HPP
#define MESHTRIANGLE_HPP
#include "Mesh.hpp"
class HalfEdge;

class MeshTriangle {
private:
    Mesh* t_mesh;
	HalfEdge* t_start;
public:
	 MeshTriangle(Mesh* mesh);
	MeshTriangle(HalfEdge& start);
	MeshTriangle(const MeshTriangle& m);
	virtual ~MeshTriangle();
	MeshTriangle& operator=(const MeshTriangle& m);
};

#endif // !MESHTRIANGLE_HPP