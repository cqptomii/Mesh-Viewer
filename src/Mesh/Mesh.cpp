//
// Created by tomfr on 22/10/2024.
//

#include <algorithm>
#include "../../header/Mesh/Mesh.hpp"
Mesh::Mesh() : name("untitled"),mesh_vertex(), mesh_half_edge(),mesh_triangle() {}
Mesh::Mesh(std::string name) : name(std::move(name)),mesh_vertex(),mesh_half_edge(),mesh_triangle() {}
Vertex Mesh::addVertex() {

}
void Mesh::push_vertex(const Vertex &v) {
    this->mesh_vertex.push_back(v);
}
void Mesh::pop_vertex(const Vertex &v) {
    mesh_vertex.erase(std::remove_if(mesh_vertex.begin(),mesh_vertex.end(),
                                     [&v](const Vertex& vertex){ return vertex == v;}),
                                     mesh_vertex.end());
}

unsigned int Mesh::get_vertex_amount() {
    return this->mesh_vertex.size();
}

void Mesh::push_halfedge(const HalfEdge &h) {

}

void Mesh::pop_halfedge(const HalfEdge &h) {

}

void Mesh::push_edge(const Edge &h) {

}

void Mesh::pop_edge(const Edge &h) {

}
