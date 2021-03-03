#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE *fp = fopen("toth.txt","w");
    fprintf(fp,"Toth Jozsef\nUzemmernoki informatikus (BProf)\nWI2GDP");
    fclose(fp);
    FILE *fpMasodik = fopen("toth.txt","r");
    char line[101];
    while(!feof(fpMasodik))
    {
        fgets(line, 100, fpMasodik);
        puts(line);
    }
    fclose(fpMasodik);
    return 0;
}
