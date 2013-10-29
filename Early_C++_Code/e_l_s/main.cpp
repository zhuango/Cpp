#include "Conio.h"
#include "GRAPHICS.h"
#include<stdio.h>
#include<stdlib.h>
#define closegr closegraph
#define WALL 9
#define BACK 6
#define PTC 4
#define DELC 15
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP    0x4800
#define ESC   0x011b

void init();
void draw(int,int,int);
void drawpart(int);
void drawdp(int);
void newpart();
void start();
void sport();
void changedp();
int check(int);
int delmap();

int map[12][20],pat,gameover,i,j,k,w=1,speed=1,lingp=0;
long int score=0;
char scorec[20],speedc[10],lingpc[10];
struct node{
    int x[4];
    int y[4];
};
struct node part,dp;
void initgr(void) /* BGI初始化 */
{
int gd = DETECT, gm = 0; /* 和gd = VGA,gm = VGAHI是同样效果 */
registerbgidriver(EGAVGA_driver);/* 注册BGI驱动后可以不需要.BGI文件的支持运行 */
initgraph(&gd, &gm, "");
}
int main(void)
{
    char ch;
    init();
    start();
    while((ch=getch())!='Q'&&ch!='q')
    {} /* 暂停一下，看看前面绘图代码的运行结果 */
    closegr(); /* 恢复TEXT屏幕模式 */
    return 0;
}

void init()
{
    initgr(); /* BGI初始化 */
    randomize();
    setbkcolor(BACK);
    setcolor(4);
    setviewport(130,40,510,440,1);/*设置可活动区域*/
    pat=0;
    gameover=0;
    sprintf(scorec,"SCORE:%ld",score);
    outtextxy(250,300,scorec);
    sprintf(speedc,"SPEED:%d",speed);
    outtextxy(250,200,speedc);
    sprintf(lingpc,"LINE:%d",lingp);
    outtextxy(250,250,lingpc);
    for(i=0;i<=380;i+=20)
    {
        draw(0,i,WALL);
        draw(220,i,WALL);
        draw(360,i,WALL);
    }
    for(i=20;i<=360;i+=20)
    {
        draw(i,0,WALL);
        draw(i,380,WALL);
    }
    for(i=0;i<12;i++)
    for(j=0;j<20;j++)
    if(i==0||i==11||j==0||j==19)
        map[i][j]=1;
    else
        map[i][j]=0;
    newpart();
    drawpart(PTC);
}

void draw(int x,int y,int p)/*画小元件*/
{
    setcolor(p);
    rectangle(x+1,y+1,x+18,y+18);
    rectangle(x+3,y+3,x+16,y+16);
}
void newpart()
{
    int ran;
    ran=rand()%7;
    switch(ran)
    {
        case 0:
        {
            for(i=0;i<4;i++)
            {
                part.x[i]=i;
                part.y[i]=0;
            }
            break;
        }
        case 1:
        {
            for(i=0;i<3;i++)
            {
                part.x[i]=i;
                part.y[i]=1;
            }
            part.x[3]=2;
            part.y[3]=0;
            break;
        }
        case 2:
        {
            for(i=0;i<3;i++)
            {
                part.x[i]=i;
                part.y[i]=0;
            }
            part.x[3]=2;
            part.y[3]=1;
            break;
        }
        case 3:
        {
            for(i=0;i<3;i++)
            {
                part.x[i]=i;
                part.y[i]=0;
            }
            part.x[3]=1;
            part.y[3]=1;
            break;
        }
        case 4:
        {
            for(i=0;i<2;i++)
            {
                part.x[i]=i;
                part.y[i]=0;
            }
            for(i=2;i<4;i++)
            {
                part.x[i]=i-1;
                part.y[i]=1;
            }
            break;
        }
        case 5:
        {
            for(i=0;i<2;i++)
            {
                part.x[i]=i;
                part.y[i]=1;
            }
            for(i=2;i<4;i++)
            {
                part.x[i]=i-1;
                part.y[i]=0;
            }
            break;
        }
        case 6:
        {
            for(i=0;i<2;i++)
            {
                part.x[i]=i;
                part.y[i]=0;
                part.x[i+2]=i;
                part.y[i+2]=1;
            }
            break;
        }
    }
}
void drawpart(int color)
{
    for(i=0;i<4;i++)
        draw(260+(part.x[i])*20,40+(part.y[i])*20,color);
}
void drawdp(int color)
{
    for(i=0;i<4;i++)
        draw((dp.x[i])*20,(dp.y[i])*20,color);
}
void start()
{

    while(gameover==0)
    {
        sport();
        if(delmap()==1)
        {
            setcolor(BACK);
            outtextxy(250,300,scorec);
            outtextxy(250,200,speedc);
            sprintf(scorec,"SCORE:%ld",score);
            sprintf(speedc,"SPEED:%d",speed);
            setcolor(PTC);
            outtextxy(250,300,scorec);
            outtextxy(250,200,speedc);
        }
        setcolor(BACK);
        outtextxy(250,250,lingpc);
        sprintf(lingpc,"LINE:%d",lingp);
        setcolor(PTC);
        outtextxy(250,250,lingpc);

    }
    setcolor(15);
    settextstyle(0,0,4);
    outtextxy(50,180,"GAME OVER");
    settextstyle(0,0,1);
    outtextxy(70,220,"PRESS Q TO QUIT GAME.");
}
void sport()
{
    int delayn=0,key,delayt;
    drawpart(BACK);
    pat=0;
    for(i=0;i<4;i++)
    {
        dp.x[i]=part.x[i]+4;
        dp.y[i]=part.y[i]+2;
    }
    if(check(1)==1){gameover=1;pat=1;}
    newpart();
    drawpart(PTC);
    drawdp(PTC);
    while(pat==0)
    {
        while(!kbhit())
        {
            if(speed<=9)
                delayt=3300-speed*300;
            else
                delayt=600;
            delay(delayt*w);
            delayn++;
            if(delayn%100)
                 continue;
            delayn=0;
            if(check(1)==1)
            {
                for(i=0;i<4;i++)
                map[dp.x[i]][dp.y[i]]=1;
                pat=1;
                break;
            }
            drawdp(BACK);
            changedp(1);
            drawdp(PTC);
        }
    w=1;
    if(pat==1)break;
    key=bioskey(0);
    if(key==ESC)
    {
        exit(0);
    }
    else if(key==DOWN)
    {
        w=0;
    }
    else if(key==LEFT)
    {
        if(check(2)==0){drawdp(BACK);changedp(2);drawdp(PTC); }
    }
    else if(key==RIGHT)
    {
        if(check(0)==0){drawdp(BACK);changedp(0);drawdp(PTC); }
    }
    else if(key==UP)
    {
        if(check(3)==0){drawdp(BACK);changedp(3);drawdp(PTC);}
    }
    }
}
void changedp(int p)
{
    int ex,rx,ry;
        switch(p)
        {
            case 1:
            {
                for(i=0;i<4;i++)
                dp.y[i]++;
                break;
            }
            case 2:
            {
                for(i=0;i<4;i++)
                dp.x[i]--;
                break;
            }
            case 0:
            {
                for(i=0;i<4;i++)
                dp.x[i]++;
                break;
            }
            case 3:
            {
                for(i=0;i<4;i++)
                if(i!=1)
                {
                    ex=dp.x[i];
                    dp.x[i]=dp.x[1]+dp.y[1]-dp.y[i];
                    dp.y[i]=dp.y[1]-dp.x[1]+ex;
                }
                break;
            }
        }
       
}
int check(int p)
{
    struct node chp;
        switch(p)
        {
            case 1:
            {
                for(i=0;i<4;i++)
                    if(map[dp.x[i]][dp.y[i]+1]==1)
                        return 1;
                break;
            }
            case 2:
            {
                for(i=0;i<4;i++)
                    if(map[dp.x[i]-1][dp.y[i]]==1)
                        return 1;
                break;
            }
            case 0:
            {
                for(i=0;i<4;i++)
                    if(map[dp.x[i]+1][dp.y[i]]==1)
                        return 1;
                break;
            }
            case 3:
            {
                for(i=0;i<4;i++)
                {
                    chp.x[i]=dp.x[i];
                    chp.y[i]=dp.y[i];
                }
                changedp(3);
                for(j=0;j<4;j++)
                if(map[dp.x[j]][dp.y[j]]==1)
                {
                    for(i=0;i<4;i++)
                    {
                        dp.x[i]=chp.x[i];
                        dp.y[i]=chp.y[i];
                    }
                    return 1;
                }
                for(i=0;i<4;i++)
                    {
                        dp.x[i]=chp.x[i];
                        dp.y[i]=chp.y[i];
                    }
                break;
            }
        }
    return 0;
}
int delmap()
{
    int sum,m=0;
    for(i=18;i>1;i--)
    {
        sum=0;
        for(j=1;j<=10;j++)
            sum+=map[j][i];
        if(sum==10)
        {
            m++;
            for(k=1;k<=10;k++)
            {
                delay(6000);
                draw(k*20,i*20,DELC);
            }
            for(k=i;k>1;k--)
            for(j=1;j<=10;j++)
            {
                map[j][k]=map[j][k-1];
                if(map[j][k]==1)draw(j*20,k*20,PTC);
                else draw(j*20,k*20,BACK);
            }
            i++;
        }
    }
    switch(m)
    {
     case 0:break;
     case 1:
        {score+=100;break;}
     case 2:
        {score+=300;break;}
     case 3:
        {score+=1000;break;}
     case 4:
        {score+=1600;break;}
    }
        speed=(int)score/10000+1;
    lingp+=m;
    if(m==0)return 0;
    else return 1;
}