#include "../../header/Mesh/MeshTriangle.h"
#include "../../header/Mesh/HalfEdge.h"

MeshTriangle::MeshTriangle(HalfEdge& start) : t_start(&start){}
MeshTriangle::MeshTriangle(const MeshTriangle& m) : t_start(m.t_start) {}
MeshTriangle:: ~MeshTriangle() {}
MeshTriangle& MeshTriangle::operator=(const MeshTriangle& m) {
	if (this != &m) {
		this->t_start = m.t_start;
	}
	return *this;
}