#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class HalfEdge;

class Vertex{
private:
	GLushort v_id;
	glm::vec3 v_pos;
	glm::vec3 v_color;
	glm::vec2 v_tex_pos;
	HalfEdge* v_next_edge;

	bool use_texture;
	
public:
	Vertex();
	Vertex(GLushort id, glm::vec3 pos, glm::vec3 color);
	Vertex(GLushort id, glm::vec3 pos, glm::vec3 color, glm::vec2 tex_pos, bool use_tex_coord);
	Vertex(const Vertex& v);
	virtual ~Vertex();
	Vertex& operator=(const Vertex& v);
	void set_next_edge(HalfEdge& e);
};
#endif // !VERTEX_HPP

