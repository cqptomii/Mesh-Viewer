#ifndef MESHTRIANGLE_HPP
#define MESHTRIANGLE_HPP

class HalfEdge;

class MeshTriangle {
private:
	HalfEdge* t_start;
public:
	MeshTriangle();
	MeshTriangle(HalfEdge& start);
	MeshTriangle(const MeshTriangle& m);
	virtual ~MeshTriangle();
	MeshTriangle& operator=(const MeshTriangle& m);
};

#endif // !MESHTRIANGLE_HPP