// Author - Dvir Sadon
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

void (*hello_message)(const char *);

bool init()
{
    void *hdl = dlopen("./hello_ariel.so", RTLD_LAZY);
    if (NULL == hdl) 
        return false;
    hello_message = (void(*)(const char *))dlsym(hdl, "hello_message");
    if (NULL ==  hello_message) 
        return false;
    return true;
}
int main(){
    if (init())
        hello_message("Ariel");
    else
        printf ("Libary eas not loaded");
    return 0;
}