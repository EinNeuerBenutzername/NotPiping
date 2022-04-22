#include <stdio.h>
#include <Windows.h>
#include <wchar.h>
int main(){
    int matchid,matchidold=1,len=0;
    FILE *fp=fopen("data.dmp","r");
    if(!fp){
        printf("Waiting for sender...\n");
        FILE *fp=fopen("data.dmp","w");
        fclose(fp);
    }
    while(1){
        Sleep(30);
        if(!fp){
            fp=fopen("data.dmp","r");
            continue;
        }
        fscanf(fp,"%d.%d.",&matchid,&len);
        if(matchid==matchidold){
            rewind(fp);
            fflush(fp);
            continue;
        }
        wchar_t line[1024];
        wmemset(line,0,1024);
        fgetws(line,len+1,fp);
        wprintf(L"%ls\n",line);
        matchidold=matchid;
        rewind(fp);
        fflush(fp);
        if(wcsncmp(line,L"quit",4)==0){
            fclose(fp);
            remove("data.dmp");
            return 0;
        }
    }
    fclose(fp);
    remove("data.dmp");
}
