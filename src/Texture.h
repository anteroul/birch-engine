#pragma once

#include <string>

struct Texture
{
	explicit Texture(const std::string& path);
	Texture() = default;
	std::string path;
	unsigned int texture{};
};
