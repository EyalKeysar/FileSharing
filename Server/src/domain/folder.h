#pragma once

#include <string>
#include <vector>

namespace domain {

    class Folder {
    private:
        int id;
        std::string name;
        std::vector<int> fileIds;  // List of file IDs in this folder
        std::vector<int> subfolderIds;  // List of subfolder IDs in this folder

    public:
        // Constructor
        Folder(int id, const std::string& name)
            : id(id), name(name) {}

        // Getters
        int GetId() const { return id; }
        std::string GetName() const { return name; }
        std::vector<int> GetFileIds() const { return fileIds; }
        std::vector<int> GetSubfolderIds() const { return subfolderIds; }

        // Setters
        void SetId(int newId) { id = newId; }
        void SetName(const std::string& newName) { name = newName; }
        void SetFileIds(const std::vector<int>& newFileIds) { fileIds = newFileIds; }
        void SetSubfolderIds(const std::vector<int>& newSubfolderIds) { subfolderIds = newSubfolderIds; }

        // Add a file to the folder
        void AddFileId(int fileId) { fileIds.push_back(fileId); }

        // Add a subfolder to the folder
        void AddSubfolderId(int folderId) { subfolderIds.push_back(folderId); }

        // Remove a file from the folder
        void RemoveFileId(int fileId) {
            fileIds.erase(std::remove(fileIds.begin(), fileIds.end(), fileId), fileIds.end());
        }

        // Remove a subfolder from the folder
        void RemoveSubfolderId(int folderId) {
            subfolderIds.erase(std::remove(subfolderIds.begin(), subfolderIds.end(), folderId), subfolderIds.end());
        }
    };

} // namespace domain
