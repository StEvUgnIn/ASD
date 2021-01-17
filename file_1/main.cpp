#include <iostream>
#include <memory>
#include "file.h"

int main(void)
{
    File *file = new File();
    
    delete file;
    return 0;
}