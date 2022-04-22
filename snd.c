#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
void exitfunc(){
    remove("data.dmp");
}
int main(){
    remove("data.dmp");
    atexit(exitfunc);
    int matchid=0;
    FILE *fp=fopen("data.dmp","w");
    wchar_t input[1024];
    wchar_t inputlast[1024];
    while(1){
        matchid++;
        matchid=matchid%10000000;
        printf(">>");
//        cbc_setcolor(Yellow);
        fflush(stdout);
        wmemset(input,0,1024);
        fgetws(input,1024,stdin);
        fflush(stdin);
        if(input[wcslen(input)-1]==L'\n'){
            input[wcslen(input)-1]=0;
        }
//        cbc_setcolor(Default);
        if(!wcslen(input)){
            fprintf(fp,"%d.%d.%ls",matchid,wcslen(inputlast),inputlast);
        }else{
            fclose(fp);
            fp=fopen("data.dmp","w");
            fprintf(fp,"%d.%d.%ls",matchid,wcslen(input),input);
            wmemset(inputlast,0,1024);
            wcscpy(inputlast,input);
        }
        rewind(fp);
        fflush(fp);
        if(wcsncmp(input,L"quit",4)==0){
            fflush(fp);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 0;
}

