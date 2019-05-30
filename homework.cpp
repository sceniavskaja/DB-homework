#include <iostream>
#include <fstream>
#include <windows.h>
#define pattern "ZZ.ZZ.ZZ"
using namespace std;

int main(){
    ifstream get("remote_server/share/file.txt");
    ofstream write("remote_server2/share/file.txt");
    string line;
    bool Reversed=false;

    while(!get.eof()){
        getline(get,line);
        if(Reversed==true){

            int n = line.length();
            char line2[n + 1];
            strcpy(line2, line.c_str());

            for(int i=n-1; i>=0;i--)
            write<<line2[i];
            write<<endl;
        }else if(Reversed==false){
            write<<line<<endl;
        }
        //------------------------------------
        size_t found = line.find(pattern);
        if(found != string::npos){

            int n = line.length();
            char line2[n + 1];
            strcpy(line2, line.c_str());

            if(line[n-4]=='Z'&&line[n-3]=='.'&&line[n-2]=='Z'&&line[n-1]=='Z'){
                Reversed=false;
            }else{
                Reversed=true;
            }
        }else{
            Reversed=false;
        }
    }
    ofstream Delete("remote_server/share/file.txt");
    Delete<<"";
    write.close();
    get.close();
    Delete.close();
    return 0;
}
