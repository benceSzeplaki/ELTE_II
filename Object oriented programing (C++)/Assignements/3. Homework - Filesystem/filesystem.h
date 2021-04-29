#pragma once

#include <vector>

class File
{
    private:
        int numberOfFiles;
    public:
        File(int NoFs) { numberOfFiles = NoFs; }
        int getNoFs() { return numberOfFiles; }
};

class Folder
{
    private:
        std::vector<File*> Files;
        std::vector<Folder*> Folders;
        int sizeOfFolder;
    public:
        Folder() { sizeOfFolder = 0; }
        void add(File* newFile)
        {
            sizeOfFolder += newFile->getNoFs();
            Files.push_back(newFile);
        }
        void add(Folder* newFolder)
        {
            sizeOfFolder++;
            Folders.push_back(newFolder);
            sizeOfFolder = this->calcSizeOfFolder();
        }
        int calcSizeOfFolder()
        {
            int SoF = 0;
            for(unsigned int i = 0; i < this->Files.size(); i++)
            {
                SoF = SoF + this->Files[i]->getNoFs();
            }
            for(unsigned int i = 0; i < this->Folders.size(); i++)
            {
                SoF = SoF + this->Folders[i]->calcSizeOfFolder();
            }
            return SoF;
        }
        int getSize() { return sizeOfFolder; }
};

class FileSystem
{
    public:
        Folder root;
};
