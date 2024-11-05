#include "../header/Edge.h"
Edge::Edge() : e_origin(),e_end(){}
Edge::Edge(Vertex& origin,Vertex& end) : e_origin(&origin),e_end(&end) {}
Edge::Edge(const Edge& e) : e_origin(e.e_origin),e_end(e.e_end){}
Edge:: ~Edge(){}
Edge& Edge::operator=(const Edge& e) {
	if (&e != this) {
		this->e_origin = e.e_origin;
		this->e_end = e.e_end;
	}
	return *this;
}
