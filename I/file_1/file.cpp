#include "file.h"
#include <exception>
#include "../echanger/fonctions.h"

#define LIMIT 50

File::File()
{
    file = new char[LIMIT];
    index = 0;
}

File::~File()
{
    delete[] file; 
}

File& File::enfiler(char car)
{
    if (index < LIMIT) 
        file[index++] = car;
    else 
        throw new std::exception;
}

char File::defiler()
{
    file++;
    return *(file-1);
}

bool File::estVide()
{
    return file != nullptr;
}

bool File::estPlein()
{
    return index == LIMIT;
}

double File::sommet()
{
    return file[index];
}
