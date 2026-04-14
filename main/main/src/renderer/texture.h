#pragma once

class texture
{
	unsigned int textureID;
	int width, height, nrChannels;
	unsigned char* data;
public:
	texture(const char* path);
	void bind(unsigned int slot = 0) const;
	void unbind() const;
};

