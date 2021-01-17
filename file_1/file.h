#ifndef FILE_H_
#define FILE_H_

class File
{
private:
    char* file;
    short int index;
public:
    File();
    ~File();
    File& enfiler(char);
    char defiler();
    bool estVide();
    bool estPlein();
    double sommet();
};

#endif
