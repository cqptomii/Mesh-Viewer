#include "../../header/Mesh/Edge.h"

Edge::Edge(Mesh *mesh, Vertex &origin, Vertex &end) : e_mesh(mesh),e_origin(&origin),e_end(&end){
}
Edge::Edge(const Edge& e) : e_mesh(e.e_mesh),e_origin(e.e_origin),e_end(e.e_end){}
Edge:: ~Edge(){}
Edge& Edge::operator=(const Edge& e) {
	if (&e != this) {
		this->e_origin = e.e_origin;
		this->e_end = e.e_end;
	}
	return *this;
}

Vertex &Edge::get_origin() {
    return *this->e_origin;
}
