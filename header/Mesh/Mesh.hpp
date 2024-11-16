//
// Created by tomfr on 22/10/2024.
//

#ifndef MESH_VIEWER_MESH_HPP
#define MESH_VIEWER_MESH_HPP
#include <string>
#include <list>
#include "HalfEdge.h"

class Mesh {
private:
    std::string name;
    std::list<Vertex> mesh_vertex;
    std::list<HalfEdge> mesh_half_edge;
    std::list<Edge> mesh_edge;
    std::list<MeshTriangle> mesh_triangle;
public:
    Mesh();
    Mesh(std::string name);
    Vertex addVertex();
    void push_vertex(const Vertex& v);
    void pop_vertex(const Vertex& v);
    unsigned int get_vertex_amount();
    void push_halfedge(const HalfEdge& h);
    void pop_halfedge(const HalfEdge& h);
    void push_edge(const Edge& h);
    void pop_edge(const Edge& h);
    void onDraw();
};


#endif //MESH_VIEWER_MESH_HPP
