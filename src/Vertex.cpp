#include "../header/Vertex.h"
#include "../header/HalfEdge.h"
Vertex::Vertex() : v_id(0),v_pos(glm::vec3(0.0f)),v_color(glm::vec3(1.0f,1.0f,0.0f)),v_tex_pos(glm::vec2(0.0f)),use_texture(false), v_next_edge() {}
Vertex::Vertex(GLushort id, glm::vec3 pos, glm::vec3 color) : v_id(id),v_pos(pos),v_color(color),v_tex_pos(), use_texture(), v_next_edge() {}
Vertex::Vertex(GLushort id, glm::vec3 pos, glm::vec3 color, glm::vec2 tex_pos, bool use_tex_coord) : v_id(id),v_pos(pos),v_color(color),v_tex_pos(tex_pos),use_texture(use_tex_coord),v_next_edge() {}
Vertex::Vertex(const Vertex& v){
	if (&v != nullptr) {
		this->v_id = v.v_id;
		this->v_pos = v.v_pos;
		this->v_color = v.v_color;
		this->v_tex_pos = v.v_tex_pos;
		this->v_next_edge = v.v_next_edge;
		this->use_texture = v.use_texture;
	}
}
Vertex::~Vertex() {}
Vertex& Vertex::operator=(const Vertex& v) {
	if (&v != this) {
		this->v_id = v.v_id;
		this->v_pos = v.v_pos;
		this->v_color = v.v_color;
		this->v_tex_pos = v.v_tex_pos;
		this->v_next_edge = v.v_next_edge;
		this->use_texture = v.use_texture;
	}
	return *this;
}
void Vertex::set_next_edge(HalfEdge& e) {
	if (&e != nullptr) {
		this->v_next_edge = &e;
	}
}