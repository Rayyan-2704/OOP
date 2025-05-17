#include <iostream>
#include <string>
#include <exception>
using namespace std;

class FileException : public exception
{
public:
    virtual const char *what() const noexcept
    {
        return "FileException";
    }
};

class FileNotFoundException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "PermissionDeniedException - Access denied!";
    }
};

void validateFile(const string &fileName)
{
    if (fileName == "missingfile.txt")
    {
        throw FileNotFoundException();
    }
    else if (fileName == "secretfile.txt")
    {
        throw PermissionDeniedException();
    }

    cout << "File \"" << fileName << "\" opened successfully!" << endl;
}

int main()
{
    string fileName = "secretfile.txt";

    try
    {
        validateFile(fileName);
    }
    catch (const FileNotFoundException &e)
    {
        cout << "Error in validating \"" << fileName << "\": " << e.what() << endl;
    }
    catch (const PermissionDeniedException &e)
    {
        cout << "Error in validating \"" << fileName << "\": " << e.what() << endl;
    }
    catch (const FileException &e)
    {
        cout << "Error in validating \"" << fileName << "\": " << e.what() << endl;
    }

    return 0;
}
