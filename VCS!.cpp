#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <filesystem>
#include <openssl/sha.h>

namespace fs = std::filesystem;

class VersionControlSystem {
private:
    std::string repositoryPath;
    std::vector<std::string> commits;

    std::string calculateHash(const std::string &content) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, content.c_str(), content.length());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        return ss.str();
    }

public:
    VersionControlSystem(const std::string &repoPath) : repositoryPath(repoPath) {
        fs::create_directory(repoPath);
    }

    void initializeRepository() {
        std::cout << "Initialized empty repository in " << repositoryPath << std::endl;
    }

    void trackFile(const std::string &filename) {
        std::string filePath = repositoryPath + "/" + filename;
        std::ofstream file(filePath);
        file.close();
        std::cout << "Tracking file: " << filename << std::endl;
    }

    void commit(const std::string &filename, const std::string &content) {
        std::string filePath = repositoryPath + "/" + filename;
        std::ifstream file(filePath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        std::string currentContent = buffer.str();
        if (currentContent == content) {
            std::cout << "No changes to commit." << std::endl;
            return;
        }

        std::string hash = calculateHash(content);
        commits.push_back(hash);

        std::ofstream commitFile(repositoryPath + "/commits.txt", std::ios::app);
        commitFile << hash << " " << filename << std::endl;
        commitFile.close();

        std::ofstream updatedFile(filePath);
        updatedFile << content;
        updatedFile.close();

        std::cout << "Changes committed successfully." << std::endl;
    }

    void viewLog() {
        std::cout << "Commit Log:" << std::endl;
        for (const auto &commit : commits) {
            std::cout << commit << std::endl;
        }
    }

    void revert(const std::string &hash, const std::string &filename) {
        // Implement file reversion logic using hash
    }

    void integrityCheck() {
        // Implement integrity check logic
    }
};

int main() {
    std::string repoPath = "my_repository";
    VersionControlSystem vcs(repoPath);

    vcs.initializeRepository();
    vcs.trackFile("example.txt");

    std::string content1 = "This is the initial content.";
    vcs.commit("example.txt", content1);

    std::string content2 = "This is the modified content.";
    vcs.commit("example.txt", content2);

    vcs.viewLog();

    return 0;
}
