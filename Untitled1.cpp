#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define H 10

struct coursa {
    int id;
    char name[20];
    int time;
    float score;
    char term[10];
} cou[H];


void input(struct coursa a[]); // 数据入结构体
void save(struct coursa a[]); // 数据入硬盘
void edit(struct coursa a[]);
void brows(struct coursa a[]);
void search(struct coursa a[]);

void search(struct coursa a[])
{
	int i,j,k,p,s;
	char n[20];
	while(1)
	{
	printf("您想通过那个信息查询？\n");
	printf("[1]课程编号    [2]课程名称    [0]返回\n");
	scanf("%d",&i);
	if(i==2)
	while(1)
	    {
	    	printf("请输入课程名称,输入[0]返回\n");
	    	//scanf("%d",&s);
			scanf("%s",n);
			if(strcmp(n,"0")==0)
			break;
			//if(s==0)
	    	//break;
			for(j=0;j<H;j++)
	    	{
	    		if(strcmp(a[j].name,n)==0)
	    		{
	    			printf("查询结果为：\n");
			        printf("%d %s %d %f %s\n", a[j].id, a[j].name, a[j].time, a[j].score, a[j].term);
			        break;
				}
	    		else if(j==H&&strcmp(a[j].name,n)!=0)
	    		{
	    			printf("查询不到结果");
	    	    	break;
				}
	    		
			}
			
	    }
	else if(i==1)
	while(1)
	    {
		    printf("请输入课程编号,输入[0]返回\n");
		    scanf("%d",&p);
		    if(p==0)
		    break;
		    for(j=0;j<H;j++)
	    	{
	    		if(a[j].id==p)
	    		{
				printf("查询结果为：\n");
			    printf("%d %s %d %f %s\n", a[j].id, a[j].name, a[j].time, a[j].score, a[j].term);
	    		break;
	    	    }
	    	    else if(j==H&&a[j].id!=p)
	    	    {
	    	    	printf("查询不到结果");
	    	    	break;
				}
	    	    
			}
			printf("查询结果为：\n");
			printf("%d %s %d %f %s\n", a[j].id, a[j].name, a[j].time, a[j].score, a[j].term);
	    }
	else if(i==0)
	break;
    }
	
}

void brows(struct coursa a[])
{   
    int i;
	for(i = 0; i < H; i++) 
    {
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
	
}

void edit(struct coursa a[])
{
	int c,i,j,k,n;
	while(1)
	{
		printf("您想编辑第几个数据？\n");
	    printf("输入[0]返回终端\n");
		scanf("%d",&c);
		if(c==0)
		break;
		if (c < 1 || c > H) 
		{
            printf("Invalid serial number. Please enter a valid serial number between 1 and %d\n", H);
            scanf("%d", &c);
            continue;
        }
		j=1;
		if(c==1)
		for(i = 0; i < 3; i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
		else if(c==1)
		for(i = 0; i < 4; i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
    else if(c>1&&c<H-2)
    for(i=c-2;i<c+3;i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
    else if(c==H)
    for(i=H-2; i < H; i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
    else if(c==H-1)
    for(i=H-3; i < H; i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
    else if(c==H-2)
    for(i=H-4; i < H; i++) 
    {
    	printf("%d. ",j++);
        printf("%d %s %d %f %s\n", a[i].id, a[i].name, a[i].time, a[i].score, a[i].term);
    }
    
    
    printf("请输入您想编辑数据的序号（以终端展示为准）\n");
    scanf("%d",&k);
    printf("[1]删除    [2]编辑    [0]返回\n");
    scanf("%d",&n);
    if (c==1)
    {
    	if(n==1)
    	memset(&a[k-1],0,sizeof(struct coursa));
    	else if(n==2)
    	{
    	printf("请依照五位课程编号，课程名称，总课时，学分，开始日期（以形如2023/1/1的形式输入）的形式，输入修改后的数据\n");
    	scanf("%d %s %d %f %s", &a[k-1].id, a[k-1].name, &a[k-1].time, &a[k-1].score, a[k-1].term);
    	printf("编辑成功\n\n");
        }
    	else if(n==0);
	}
	else if(c==10)
	{
		if(n==1)
    	memset(&a[c+(k-2)],0,sizeof(struct coursa));
    	else if(n==2)
    	{
		printf("请依照五位课程编号，课程名称，总课时，学分，开始日期（以形如2023/1/1的形式输入）的形式，输入修改后的数据\n");
    	scanf("%d %s %d %f %s", &a[k].id, a[k].name, &a[k].time, &a[k].score, a[k].term);
    	printf("编辑成功\n\n");
        }
    	else if(n==0);
	}
	else
	{
		if(n==1)
		memset(&a[c+(k-2)],0,sizeof(struct coursa));
		else if(n==2)
		{
		printf("请依照五位课程编号，课程名称，总课时，学分，开始日期（以形如2023/1/1的形式输入）的形式，输入修改后的数据\n");
    	scanf("%d %s %d %f %s", &a[c+(k-2)].id, a[c+(k-2)].name, &a[c+(k-2)].time, &a[c+(k-2)].score, a[c+(k-2)].term);
    	printf("编辑成功\n\n");
        }
        else if(n==0);
	}
	}
}


void save(struct coursa a[])
{
	FILE *fi;
	int i,j,k;
	if((fi = fopen("co.txt", "w+")) == NULL) 
	{
        printf("file is broken or doesn't exist");
        exit(0);
    }
    for(i=0;i<H;i++)
    {
    	if(fwrite(&a[i],sizeof(struct coursa),1,fi)!=1)
    	{
    		printf("file write error\n");
		}
    	else
    	{
    		printf("%d. ",i+1);
			printf("file write success\n");
		}
	}
	fclose(fi);
    
}

void input(struct coursa a[])
{
    int i,j,k;
    struct coursa t;
    printf("你想从第几个数据开始输入？（输入会覆盖原数据）\n");
    scanf("%d",&k);
    printf("请依次输入五位课程编号，课程名称，总课时，学分，开始日期（以形如2023/1/1的形式输入）\n并用空格隔开:\n");
    for(i = k-1; i < H; i++) 
	{
        scanf("%d %s %d %f %s", &a[i].id, a[i].name, &a[i].time, &a[i].score, a[i].term);
    }
    for(i=0;i<H;i++)
    for(j=0;j<H-1-i;j++)//以下为排序语句
    {
    	if (a[j].id>a[j+1].id)
    	{
    		t.id=a[j+1].id;
			strcpy(t.name,a[j+1].name);
			t.time=a[j+1].time;
    		t.score=a[j+1].score;
			strcpy(t.term,a[j+1].term);
			
			a[j+1].id=a[j].id;
			strcpy(a[j+1].name,a[j].name);
			a[j+1].time=a[j].time;
			a[j+1].score=a[j].score;
			strcpy(a[j+1].term,a[j].term);
			
			a[j].id=t.id;
			strcpy(a[j].name,t.name);
			a[j].time=t.time;
			a[j].score=t.score;
			strcpy(a[j].term,t.term);
		}

	}
}

int main() 
{
    int i;
    FILE *fi;
    char c,p;
    	if((fi = fopen("co.txt", "r")) == NULL) //打开文件
	{
        printf("file co.txt is broken or doesn't exist");
        exit(0);
    }
     for(i=0;i<H;i++)//将已有文件进内存
    {
    	if(fread(&cou[i],sizeof(struct coursa),1,fi)!=1)
    	{
    		printf("%d. ",i+1);
			printf("file read error\n");
		}
    	else
    	{
    		printf("%d. ",i+1);
			printf("file read success\n");
		}
	}
	while(1) 
	{
        printf("请在选择您需要的功能后按[ENTER]键:\n\n");
        printf("[1]输入数据    [2]编辑    [3]浏览数据    [4]条件查询   [5]保存    [6]退出\n"); // 菜单录入
        scanf(" %c",&c);//空格来处理空白符
        if (c == '1')  // 依照用户键入数字执行功能
        input(cou);
        else if (c=='2')
        edit(cou);
        else if (c == '6') 
        break;
        else if (c=='3')
        brows(cou);
        else if (c=='5')
        save(cou);
        else if (c=='4')
        search(cou);
        
    }//操作终端
    for(i = 0; i < H; i++) {
        printf("%d %s %d %f %s\n", cou[i].id, cou[i].name, cou[i].time, cou[i].score, cou[i].term);
    }
    printf("\n\n系统以退出，请确保您已经保存以上数据");
    return 0;
}
