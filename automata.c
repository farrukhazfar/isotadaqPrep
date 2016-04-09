#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 300
#define ITERATIONS 100
#define SEED 150

int main()
{
    char F='O',B=' ';
    //    int y[8]= {0,0,0,1,0,0,1,0}; /*rule is set to popular "rule 18"*/
    int y[8]= {0,0,0,1,0,0,1,1}; /*rule is set to popular "rule 18"*/
    int x[COLUMNS],z[COLUMNS];
    int r,j,k;
    FILE *fp;
    fp=fopen("cellular_automata_rule_specific1.txt","w");

    fprintf(fp,"Set font size to 1 on your text viewer to see the larger picture\n");
    fprintf(fp,"If you are using notepad click Format->font and change the font size\n\n\n");

    fprintf(fp,"rule  %d%d%d%d%d%d%d%d\n ",y[0],y[1],y[2],y[3],y[4],y[5],y[6],y[7]);

    for(j=0; j<COLUMNS; j++)
    {
        x[j]=0;
        z[j]=0;
    }
    x[SEED]=1;

    for(k=0; k<ITERATIONS; k++)
    {
        x[0]=x[COLUMNS-1]=0;
        for(r=1; r<(COLUMNS-1); r++)
        {
            if( (x[r-1]==0)&&(x[r]==0)&&(x[r+1]==0) )
                z[r]=y[7];
            else if( (x[r-1]==0)&&(x[r]==0)&&(x[r+1]==1) )
                z[r]=y[6];
            else if( (x[r-1]==0)&&(x[r]==1)&&(x[r+1]==0) )
                z[r]=y[5];
            else if( (x[r-1]==0)&&(x[r]==1)&&(x[r+1]==1) )
                z[r]=y[4];
            else if( (x[r-1]==1)&&(x[r]==0)&&(x[r+1]==0) )
                z[r]=y[3];
            else if( (x[r-1]==1)&&(x[r]==0)&&(x[r+1]==1) )
                z[r]=y[2];
            else if( (x[r-1]==1)&&(x[r]==1)&&(x[r+1]==0) )
                z[r]=y[1];
            else if( (x[r-1]==1)&&(x[r]==1)&&(x[r+1]==1) )
                z[r]=y[0];
            if(z[r]==1)fprintf(fp,"%c",F);
            else fprintf(fp,"%c",B);
        }
        fprintf(fp,"\n ");


        z[0]=z[COLUMNS-1]=0;
        for(r=1; r<(COLUMNS-1); r++)
        {
            if( (z[r-1]==0)&&(z[r]==0)&&(z[r+1]==0) )
                x[r]=y[7];
            else if( (z[r-1]==0)&&(z[r]==0)&&(z[r+1]==1) )
                x[r]=y[6];
            else if( (z[r-1]==0)&&(z[r]==1)&&(z[r+1]==0) )
                x[r]=y[5];
            else if( (z[r-1]==0)&&(z[r]==1)&&(z[r+1]==1) )
                x[r]=y[4];
            else if( (z[r-1]==1)&&(z[r]==0)&&(z[r+1]==0) )
                x[r]=y[3];
            else if( (z[r-1]==1)&&(z[r]==0)&&(z[r+1]==1) )
                x[r]=y[2];
            else if( (z[r-1]==1)&&(z[r]==1)&&(z[r+1]==0) )
                x[r]=y[1];
            else if( (z[r-1]==1)&&(z[r]==1)&&(z[r+1]==1) )
                x[r]=y[0];
            if(x[r]==1)fprintf(fp,"%c",F);
            else fprintf(fp,"%c",B);
        }
        fprintf(fp,"\n ");
    }



    printf("open cellular_automata_rule_specific.txt to see cellular automata pattern..!!\n\n");
    return 0;
}
