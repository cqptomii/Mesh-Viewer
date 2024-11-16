#include "../../header/Mesh/Vertex.h"
#include "../../header/Mesh/HalfEdge.h"
Vertex::Vertex(Mesh* mesh) : v_mesh(mesh){
    if(v_mesh) {
        mesh->push_vertex(*this);

        this->v_id = mesh->get_vertex_amount();
    }

    this->v_attributes.emplace_back(); // Vertex coordinates
    this->v_attributes.emplace_back(); // Vertex Color
    this->v_attributes.emplace_back(); // Vertex Normal
    this->v_attributes.emplace_back(); // Vertex TexCoord

    this->v_next_edge = nullptr;
}
Vertex::Vertex(Mesh* mesh, glm::vec3& pos, glm::vec3& color) : Vertex(mesh){
    this->setCoord(pos);
    this->setColor(color);
}
Vertex::Vertex(Mesh* mesh, glm::vec3& pos, glm::vec3& color, glm::vec2& tex_pos, bool use_tex_coord) : Vertex(mesh) {
    this->setCoord(pos);
    this->setColor(color);
    this->setTexCoord(tex_pos);
}
Vertex::Vertex(const Vertex& v){
	if (&v != nullptr) {
        this->v_mesh = v.v_mesh;
		this->v_id = v.v_id;
		this->v_attributes = v.v_attributes;
		this->v_next_edge = v.v_next_edge;
		//this->use_texture = v.use_texture;
	}
}
Vertex& Vertex::operator=(const Vertex& v) {
	if (&v != this) {
        this->v_mesh = v.v_mesh;
		this->v_id = v.v_id;
        this->v_attributes = v.v_attributes;
		this->v_next_edge = v.v_next_edge;
		//this->use_texture = v.use_texture;
	}
	return *this;
}
Vertex::~Vertex() {
    if(v_mesh){
        v_mesh->pop_vertex(*this); // Supprime le sommet du maillage
        v_mesh = nullptr;
    }
    HalfEdge* halfEdge = v_next_edge; // Supprime tous les triangles autour de ce sommet
    while(halfEdge){
        HalfEdge* next = halfEdge->get_sibling();
        delete halfEdge->get_triangle();
        halfEdge = next;
    }
}
void Vertex::link_sibling(HalfEdge *halfEdge) {

}
void Vertex::unlink_sibling(HalfEdge *halfEdge) {

}
Vertex& Vertex::setCoord(glm::vec3& pos) {
    this->v_attributes[ID_VERTEXCOORD] = glm::vec4 (pos,0);
    return *this;
}
Vertex& Vertex::setCoord(glm::vec4& pos) {
    this->v_attributes[ID_VERTEXCOORD] = pos;
    return *this;
}
Vertex& Vertex::setColor(glm::vec3 &color) {
    this->v_attributes[ID_COLOR] = glm::vec4 (color,1.0f);
    return *this;
}
Vertex& Vertex::setColor(glm::vec4 &color) {
    this->v_attributes[ID_COLOR] = color;
    return *this;
}

Vertex &Vertex::setNormal(glm::vec3 &normal) {
    this->v_attributes[ID_NORMAL] = glm::vec4 (normal,0.0);
    return *this;
}
Vertex& Vertex::setTexCoord(glm::vec2& tex_pos){
    this->v_attributes[ID_TEXCOORD] = glm::vec4 (tex_pos,0.0f,0.0f);
    return *this;
}
std::vector<MeshTriangle*> Vertex::get_triangle_around(){

}
std::vector<MeshTriangle*> Vertex::get_triangle_ordered_around(){
    std::vector<MeshTriangle*> triangles;
    HalfEdge* halfEdge = this->v_next_edge;

    while(halfEdge){
        triangles.push_back(halfEdge->get_triangle());
        if(halfEdge->get_next())
            halfEdge = halfEdge->get_next();
        if(halfEdge->get_next())
            halfEdge = halfEdge->get_next();
        if(halfEdge->get_opposite()){
            halfEdge = halfEdge->get_opposite();
        }else{
            halfEdge = nullptr;
        }
    }
    return triangles;
}

std::vector<Vertex *> Vertex::get_neighbor_vertex() {

    return std::vector<Vertex *>();
}

HalfEdge *Vertex::get_halfEdge_to(Vertex &target) {
    if(this->v_next_edge){
        Vertex* temp = v_next_edge->get_target();
        if(temp == &target){
            return v_next_edge;
        }
    }

    return nullptr;
}


