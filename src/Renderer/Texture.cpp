#include "pch.h"
#include "Texture.h"

Texture::Texture()
    : m_width(0), m_height(0)
{}

Texture::Texture(const std::string& filepath)
    : m_filepath(filepath)
{}

Texture::~Texture()
{}