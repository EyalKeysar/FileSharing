#include "domain/folder.h"
#include <algorithm>  // for std::remove_if

namespace domain {

Folder::Folder(int id, const std::string& name, const std::string& path)
    : id_(id), name_(name), path_(path) {}

int Folder::GetId() const { return id_;}
std::string Folder::GetName() const { return name_;}
std::string Folder::GetPath() const { return path_;}

void Folder::SetName(const std::string& name) { name_ = name;}
void Folder::SetPath(const std::string& path) { path_ = path;}

void Folder::AddFile(const File& file) { files_.emplace_back(file);}
void Folder::RemoveFileById(int id) {
    files_.erase(
        std::remove_if(files_.begin(), files_.end(),
                       [id](const File& file) { return file.GetId() == id; }),
        files_.end());
}
const std::vector<File>& Folder::GetFiles() const { return files_;}

}  // namespace domain
