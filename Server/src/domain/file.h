#pragma once

#include <string>

namespace domain {

    class File {
    private:
        int id;
        std::string name;
        int size;  // Size of the file, maybe in bytes

    public:
        // Constructor
        File(int id, const std::string& name, int size)
            : id(id), name(name), size(size) {}

        // Getters
        int GetId() const { return id; }
        std::string GetName() const { return name; }
        int GetSize() const { return size; }

        // Setters
        void SetId(int newId) { id = newId; }
        void SetName(const std::string& newName) { name = newName; }
        void SetSize(int newSize) { size = newSize; }
    };

} // namespace domain
