#include	"VertexBuffer.h"

#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* data, const unsigned int size)
{
    glGenBuffers(1, &buffer);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    Unbind();
    glDeleteBuffers(1, &buffer);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
