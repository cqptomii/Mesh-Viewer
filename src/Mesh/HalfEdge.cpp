#include "../../header/Mesh/HalfEdge.h"

HalfEdge::HalfEdge(Mesh *mesh, Vertex &origin, Vertex &target, MeshTriangle &triangle) : h_mesh(mesh) {
    if(mesh){
        mesh->push_halfedge(*this);
    }
    this->h_next_vertex = &target;
    this->h_face = &triangle;
    this->h_opposite_halfedge = nullptr;
    this->h_next_halfedge = nullptr;
    this->h_siblings = nullptr;
    this->h_edge = nullptr;

    //verification de la présence d'une demi arête ou non
    if(origin.get_halfEdge_to(target)){
        std::cout << "ERROR :: ALREADY A HALFEDGE TO THIS TARGET " << std::endl;
    }

    //vérification de la présence d'une demi arête opposée
    HalfEdge* temp = target.get_halfEdge_to(origin);
    if(temp){
        std::cout << "AN OPPOSITE HALFEDGE IS ALREADY SET on this EDGE " << std::endl;
    }
    this->h_opposite_halfedge = temp;
    temp->h_opposite_halfedge = this;

    this->h_edge = temp->h_edge;

    if(!this->h_edge){
        this->h_edge = new Edge(mesh,origin,target);
    }

    origin.link_sibling(this);
}
HalfEdge::HalfEdge(const HalfEdge& h) : h_next_vertex(h.h_next_vertex),h_edge(h.h_edge),h_next_halfedge(h.h_next_halfedge),h_opposite_halfedge(h.h_opposite_halfedge),h_face(h.h_face){}
HalfEdge:: ~HalfEdge(){
    //récuperer l'origin
    Vertex* temp = this->get_origin();
    temp->unlink_sibling(this);

    //verifier si la demi arête a une opposé
    if(this->h_opposite_halfedge){

        h_opposite_halfedge->h_opposite_halfedge = nullptr;
        h_opposite_halfedge = nullptr;
    }else{
        delete h_edge;
    }
    this->h_edge = nullptr;
    this->h_next_halfedge = nullptr;
    this->h_next_vertex = nullptr;
    if(h_mesh)
        this->h_mesh->pop_halfedge(*this);
    h_mesh = nullptr;
    this->h_face = nullptr;
}
HalfEdge& HalfEdge::operator=(const HalfEdge& h){}

Vertex *HalfEdge::get_origin() {
    return &this->h_edge->get_origin();
}

Vertex *HalfEdge::get_target() {
    return this->h_next_vertex;
}

MeshTriangle *HalfEdge::get_triangle() {
    return h_face;
}

HalfEdge *HalfEdge::get_next() {
    return h_next_halfedge;
}

HalfEdge *HalfEdge::get_opposite() {
    return this->h_opposite_halfedge;
}

HalfEdge *HalfEdge::get_sibling() {
    return this->h_siblings;
}

Edge *HalfEdge::get_edge() {
    return h_edge;
}

void HalfEdge::set_next(HalfEdge *next) {
    this->h_next_halfedge = next;
}

void HalfEdge::set_sibling(HalfEdge *sibling) {
    this->h_siblings = sibling;
}
