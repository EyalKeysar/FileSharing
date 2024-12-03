#include "domain/file.h"

namespace domain {

File::File(int id, const std::string& name, const std::string& path, int size)
    : id_(id), name_(name), path_(path), size_(size) {}

int File::GetId() const { return id_;}
std::string File::GetName() const { return name_;}
std::string File::GetPath() const { return path_;}
int File::GetSize() const { return size_;}

void File::SetName(const std::string& name) { name_ = name;}
void File::SetPath(const std::string& path) { path_ = path;}
void File::SetSize(int size) { size_ = size;}

}  // namespace domain
