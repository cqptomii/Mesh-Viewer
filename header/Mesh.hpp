//
// Created by tomfr on 22/10/2024.
//

#ifndef MESH_VIEWER_MESH_HPP
#define MESH_VIEWER_MESH_HPP

#include <vector>
#include "HalfEdge.h"

class Mesh {
private:
    std::vector<Vertex> mesh_vertex;
    std::vector<HalfEdge> mesh_half_edge;
    std::vector<MeshTriangle> mesh_triangle;
public:
    Mesh();
    Vertex addVertex();
    void onDraw();
};


#endif //MESH_VIEWER_MESH_HPP
