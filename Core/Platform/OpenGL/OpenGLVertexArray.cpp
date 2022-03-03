#include "Iridpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

#include "Logger/Log.h"

namespace Iridescent {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Iridescent::ShaderDataType::Float:    return GL_FLOAT;
			case Iridescent::ShaderDataType::Float2:   return GL_FLOAT;
			case Iridescent::ShaderDataType::Float3:   return GL_FLOAT;
			case Iridescent::ShaderDataType::Float4:   return GL_FLOAT;
			case Iridescent::ShaderDataType::Mat3:     return GL_FLOAT;
			case Iridescent::ShaderDataType::Mat4:     return GL_FLOAT;
			case Iridescent::ShaderDataType::Int:      return GL_INT;
			case Iridescent::ShaderDataType::Int2:     return GL_INT;
			case Iridescent::ShaderDataType::Int3:     return GL_INT;
			case Iridescent::ShaderDataType::Int4:     return GL_INT;
			case Iridescent::ShaderDataType::Bool:     return GL_BOOL;
		}

		IRID_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		IRID_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
    }
}
