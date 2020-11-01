#include<stdio.h>
#include<stdlib.h>

void flag(){
    system("/bin/cat flag.txt");
}
int x=2,y=2;
char canary;
int main(){
    srand((unsigned)time(NULL));canary='A'+rand()%26;
    printf("Hello,What's your name?\n");fflush(stdout);
    char maze[5][5],name[15];name[14]=canary;
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)maze[i][j]='#';
    maze[2][2]='.';
    fgets(name,50,stdin);
    if(name[14]!=canary){printf("Don't hack~~\n");return 0;}
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)printf("%c",maze[i][j]);
        printf("\n");
    }
    printf("U : up, D : down, L : left, R : right\n");fflush(stdout);
    for(int i=0;i<10;i++){
        printf("x : %d, y: %d\n",x,y);
        char c[5];fgets(c,sizeof(c),stdin);
        char dir=c[0];
        if(dir=='U'){
            if(x==0){flag();return 0;}
            if(maze[x-1][y]=='#')printf("You cant't go there\n");
            else x--;
        }else if(dir=='D'){
            if(x==4){flag();return 0;}
            if(maze[x+1][y]=='#')printf("You cant't go there\n");
            else x++;
        }else if(dir=='L'){
            if(y==0){flag();return 0;}
            if(maze[x][y-1]=='#')printf("You cant't go there\n");
            else y--;
        }else if(dir=='R'){
            if(y==4){flag();return 0;}
            if(maze[x][y+1]=='#')printf("You cant't go there\n");
            else y++;
        }else {
            printf("Invalid\n");
        }
        fflush(stdout);
    }
}