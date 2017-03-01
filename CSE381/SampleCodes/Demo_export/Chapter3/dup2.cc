#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
 
using namespace std;
 
int main()
{
    //First, we're going to open a file
    int file = open("myfile.txt",O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR );
    if(file < 0){
       cout<<"fail to create myfile.txt\n";
       return 1;
    } 

    char  msg[ ] =" Standard  output dev\n";   
    write(1, msg, strlen(msg));



    //Now we redirect standard output to the file using dup2
    if(dup2(file,1) < 0) {
    
       cout<<"fail to dup2( )\n";
       return 1;
    }

  
  //Now standard out has been redirected, we can write to
    // the file
    cout << "This will print in myfile.txt" << endl; 
 
    //At the end the file has to be closed:
    close(file);
    
    cout<<"Done\n"; 
    return 0;
}//end of function main
