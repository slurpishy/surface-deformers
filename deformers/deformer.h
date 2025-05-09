#ifndef DEFORMER_H
#define DEFORMER_H

#include "geomVertexRewriter.h"
#include "geomVertexData.h"
#include "geomNode.h"
#include "nodePath.h"
#include "geom.h"

typedef struct GeomData {
    pvector<LVecBase3f> original_vertices;
    GeomVertexRewriter* vertices;
    GeomVertexRewriter* normals;
} GeomData;

class Deformer {
public:
    inline Deformer(NodePath& nodePath);
    virtual void update_vertex(LVecBase3f& vertex, double time);

    void deform(GeomData* geom_data, double time);
    void deform_all(double time);

private:
    void disassemble_node();

private:
    NodePath _nodePath;

    pvector<GeomData*> _vertex_data;
};

#include "deformer.I"

#endif