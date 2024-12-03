#pragma once

#include <string>

namespace domain {

class File {
public:
    File(int id, const std::string& name, const std::string& path, int size);

    int GetId() const;
    std::string GetName() const;
    std::string GetPath() const;
    int GetSize() const;

    void SetName(const std::string& name);
    void SetPath(const std::string& path);
    void SetSize(int size);

private:
    int id_;
    std::string name_;
    std::string path_;
    int size_;
};

}  // namespace domain
