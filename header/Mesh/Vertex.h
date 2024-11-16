#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Mesh.hpp"
class HalfEdge;
enum{
    ID_VERTEXCOORD,
    ID_COLOR,
    ID_NORMAL,
    ID_TEXCOORD,
};
class Vertex{
private:
	GLushort v_id; // numéro du sommet

    //Attribut du sommet
    std::vector<glm::vec4> v_attributes;

    Mesh* v_mesh; // Maillage d'appartenance au sommet
    HalfEdge* v_next_edge; // demi arête sortante de ce sommet

	//bool use_texture;
	
public:
	Vertex(Mesh* mesh);
	Vertex(Mesh* mesh, glm::vec3& pos, glm::vec3& color);
	Vertex(Mesh* mesh, glm::vec3& pos, glm::vec3& color, glm::vec2& tex_pos, bool use_tex_coord);
	Vertex(const Vertex& v);
	virtual ~Vertex();
	Vertex& operator=(const Vertex& v);
    void link_sibling(HalfEdge* halfEdge);
    void unlink_sibling(HalfEdge* halfEdge);
    Vertex& setCoord(glm::vec3& pos);
    Vertex& setCoord(glm::vec4& pos);
    Vertex& setColor(glm::vec3& color);
    Vertex& setColor(glm::vec4& color);
    Vertex& setNormal(glm::vec3& normal);
    Vertex& setTexCoord(glm::vec2& tex_pos);
    std::vector<MeshTriangle*> get_triangle_around();
    std::vector<MeshTriangle*> get_triangle_ordered_around();
    std::vector<Vertex*> get_neighbor_vertex();
    HalfEdge* get_halfEdge_to(Vertex& target);
};
#endif // !VERTEX_HPP

