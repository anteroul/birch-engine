#pragma once

#include <string>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class ObjLoader {
public:
    ObjLoader() = default;

    explicit ObjLoader(const std::string &path) {
        if (load(path)) {
            printf("Object %s loaded successfully! \n", path.c_str());
        } else
            printf("ERROR: Failed to load %s \n", path.c_str());
    }

    bool load(const std::string &path);

    // list of vertices.
    const std::vector<glm::vec3> &getVertices() const;

    // list of normals.
    const std::vector<glm::vec3> &getNormals() const;

    // list of texture coordinates.
    const std::vector<glm::vec2> &getUVs() const;

    // list of indices for the faces.
    const std::vector<unsigned int> &getIndices() const;

private:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<unsigned int> indices;

    // Parses a face line from the OBJ file and stores the indices in the given vector.
    void parseFace(const std::string &face, std::vector<unsigned int> &indices);
};
