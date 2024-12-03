#pragma once

#include <string>
#include <vector>
#include "domain/file.h"

namespace domain {

class Folder {
public:
    Folder(int id, const std::string& name, const std::string& path);

    int GetId() const;
    std::string GetName() const;
    std::string GetPath() const;

    void SetName(const std::string& name);
    void SetPath(const std::string& path);

    void AddFile(const File& file);
    void RemoveFileById(int id);
    const std::vector<File>& GetFiles() const;

private:
    int id_;
    std::string name_;
    std::string path_;
    std::vector<File> files_;
};

}  // namespace domain
