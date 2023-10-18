#pragma once

#include "gfx/DrawMode.h"

class IndexBuffer;

// Draw from index buffer
void draw(const IndexBuffer& indexBuffer, DrawMode mode);
// Draw from vertex count
void draw(unsigned int vertexCount, DrawMode mode);

void drawInstanced(const IndexBuffer& indexBuffer, DrawMode mode, unsigned int instanceCount);
void drawInstanced(unsigned int vertexCount, DrawMode mode, unsigned int instanceCount);