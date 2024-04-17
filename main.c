#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#define BOOKSIZE sizeof(struct book)//图书
#define USERSIZE sizeof(struct user)//登录用户

 struct book
{
    char id[100],name[100],author[100];

    int count;//在馆内数量
    struct book*next;
};

 struct user
{
    int username;
    char password[30];
    struct user*next;

};

void logMenu();//登录界面
void logIn();//登录界面操作
void land();//用户登录
void signIn();//注册用户
int  isSucceed(char name[],char password[]);//判断用户名，密码是否正确
void bookMenu();//图书功能初始菜单
void bookFunction();//图书功能选择操作
void addBook();//增加图书
void delectBook();//删除图书
void delectBookName();//以书名删除
void delectBookId();//以id删除
void findBook();//查找图书
void findBookId();//id查找
void findBookName();//书名查找
int libraryCount();//统计书库中图书的个数
void bookList();//展示书籍列表
void borrowBook();//借阅图书
void returnBook();//归还图书


void logMenu()
{
printf("\n    欢迎来到星星图书管理系统\n");
printf("---------------------------------");
printf("\n|\t 1.用户登录\t\t|\n");
printf("\n|\t 2.注册用户\t\t|\n");
printf("\n|\t 3.退出系统\t\t|\n");
printf("---------------------------------\n");
}
void logIn()//登录界面操作
{
    int choose;
    logMenu();
    printf("请按键选择功能:\n");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        land();
        break;
    case 2:
        signIn();
        break;
    default:
        system("cls");//清屏
        exit(0);
        break;

    }

}

void land()//判断是否登陆成功
{
    char userName[100];
    char password[100];
    int flag;
    system("cls");//清屏
    printf("\n请输入账号:\n");
//    gets(userName);
scanf("%s",userName);
    printf("\n请输入密码:\n");
    scanf("%s",password);
    flag=isSucceed(userName,password);
    if(flag==1)
    {
        printf("登陆中.");
        Sleep(500);
        printf(".");
         Sleep(500);
        printf(".");
         Sleep(500);
        printf(".");
         Sleep(500);
        printf(".");
         Sleep(500);
        printf(".");
        printf("\n登陆成功！欢迎来到星星图书管理系统，按任意键继续...");
        getch();//直接键盘得到键值，不需要再回车
        bookFunction();

    }
    else if(flag==-1)
    {
        printf("密码输入错误，请重新输入密码");
        getch();
        land();//重新回到登录界面操作
    }
    else{
        printf("用户不存在，请注册用户");
        getch();
        system("cls");
        logIn();//回到初始登录界面
    }

}

void signIn()//注册账户
{
    system("cls");
    FILE*fp;
    char userName[100];
    char password[100],re_password[100];
    if((fp=fopen("user.txt","r"))==NULL)
    {
        fp=fopen("user.txt","w");
        fclose(fp);
    }
    fp=fopen("user.txt","a");//以只写的方式，在文件末尾添加数据
    printf("请输入账号和密码:\n用户名 密码\n");
    scanf("%s %s",userName,password);
    printf("请再次输入密码:\n");
    scanf("%s",re_password);

         if(strcmp(password,re_password)==0)
    {
        fprintf(fp,"%-10s %-15s\n",userName,password);

    }
    else
    {
        printf("两次输入密码不一样，请回车重新注册");
        system("cls");
        logIn();
    }
    fclose(fp);
    printf("注册成功!\n");
    printf("请按任意键返回...");
    getch();
    system("cls");
    logIn();

}

int isSucceed(char name[],char password[])//判断用户的存在性
{
    FILE*fp;
    char userName[100];
    char userPassword[100];
    if((fp=fopen("user.txt","r"))==NULL)
    {
        system("cls");
        printf("用户不存在，请注册用户");
        getch();
        system("cls");
        logIn();
    }
    while(!feof(fp))//判断是否读到文件末尾
    {
        fscanf(fp,"%s %s",userName,userPassword);
        if(strcmp(name,userName)==0)
        {
            if(strcmp(password,userPassword)==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;

}



void bookMenu()//图书功能界面
{
    system ("cls");
    printf("--------------星星图书馆-----------------");
    printf("\n 1.增加图书\t\t\t\t|\n");
    printf("\n 2.删除图书\t\t\t\t|\n");
    printf("\n 3.查找图书\t\t\t\t|\n");
    printf("\n 4.浏览图书\t\t\t\t|\n");
    printf("\n 5.借阅图书\t\t\t\t|\n");
    printf("\n 6.归还图书\t\t\t\t|\n");
    printf("\n 7.退出系统\t\t\t\t|\n");
    printf("-----------------------------------------\n");
}

void bookFunction()//图书功能界面操作
{
    bookMenu();
    printf("请按键选择:\n");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        addBook();//增加
        break;
    case 2:
        delectBook();//删除
        break;
    case 3:
        findBook();//查找
        break;
    case 4:
        bookList();//列表
        break;
    case 5:
        borrowBook();//借阅
        break;
    case 6:
        returnBook();//归还
        break;
    default:
        system("cls");
        exit(0);
    }

}

void addBook()//增加图书
{
    system("cls");
    FILE*fp;
    char id[100],name[100],author[100];//id，书名，作者
    int count;//馆内数量
    if((fp=fopen("library.txt","r"))==NULL)
    {
        fp=fopen("library.txt","w");//没有就创建一个关于图书的txt
        fclose(fp);
    }
    fp=fopen("library.txt","a");
    printf("请输入你想增加的图书\nid 书名 作者 数量\n");
    scanf("%s %s %s %d",id,name,author,&count);
    fprintf(fp,"%-5s%-30s%-10s%-7d\n",id,name,author,count);
    fclose(fp);
    printf("%s添加成功！请按回车继续...",name);
    getch();
    bookFunction();
}
void delectBook()//删除图书
{
    system("cls");
    printf("------星星图书馆------");
    printf("\n 1.id删除");
    printf("\n 2.书名删除");
    printf("\n----------------------\n");
    printf("请选择删除方式:\n");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        delectBookId();
        break;
    default:
        delectBookName();
        break;
    }
}

void delectBookName()//以书名删除
{
    system("cls");
    FILE*fp;
    struct book*head=NULL;
    struct book*p,*p1,*p2;
    char id1[100],name1[100],author1[100],c,delectName[100];
    int count1,num,i,flag;
    flag=0;
 if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
 {
      printf("请输入你要删除的书籍的名字:\n");
      scanf("%s",delectName);
      printf("确认要删除该书？若取消该操作请点ESC，若确定点击回车...");
      c=getch();//判断是不是ESC
      if(c==27)
      {

          bookFunction();
      }
      else{
          fp=fopen("library.txt","r");
          num=libraryCount();
//          printf("\n %d",num);
          for(i=0;i<num;i++)
          {
              fscanf(fp,"%s%s%s%d",id1,name1,author1,&count1);
              if(strcmp(delectName,name1)!=0)//判断是否名字相同，进行链表复制工作
              {
                  flag++;//作为判断是否存在链表的旗帜
                  if(flag==1)//创建链表
                  {
                      p1=p2=(struct book*)malloc(BOOKSIZE);
                      head=p1;
                  }
                  else
                  {
                      p2->next=p1;
                      p2=p1;
                      p1=(struct book*)malloc(BOOKSIZE);
                  }
                  //复制除了要删除的书籍的其他书籍
                  strcpy(p1->id,id1);
                  strcpy(p1->name,name1);
                  strcpy(p1->author,author1);
                  p1->count=count1;
              }

          }
           if(flag==0)
              {
                  head=NULL;
              }
              else
              {
                  p2->next=p1;
                  p1->next=NULL;
                  fclose(fp);
              }
         }
         fp=fopen("library.txt","w");
         fclose(fp);
         fp=fopen("library.txt","a");
         p=head;
         for (;p!=NULL;)//重新编写文本
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s删除成功,按任意键返回...\n",delectName);
   getch();
   bookFunction();

     }

}
void delectBookId()//以id删除
{
     system("cls");
    FILE*fp;
    struct book*head=NULL;
    struct book*p,*p1,*p2;
    char id1[100],name1[100],author1[100],c,delectName[100];
    int count1,num,i,flag;
    flag=0;
 if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
 {
      printf("请输入你要删除的书籍的id:\n");
      scanf("%s",delectName);
      printf("确认要删除该书？若取消该操作请点ESC，若确定点击回车...");
      c=getch();//判断是不是ESC
      if(c==27)
      {
          bookFunction();
      }
      else{
          fp=fopen("library.txt","r");
          num=libraryCount();
//          printf("\n %d",num);
          for(i=0;i<num;i++)
          {
              fscanf(fp,"%s%s%s%d",id1,name1,author1,&count1);
              if(strcmp(delectName,id1)!=0)//判断是否名字相同，进行链表复制工作
              {
                  flag++;//作为判断是否存在链表的旗帜
                  if(flag==1)//创建链表
                  {
                      p1=p2=(struct book*)malloc(BOOKSIZE);
                      head=p1;
                  }
                  else
                  {
                      p2->next=p1;
                      p2=p1;
                      p1=(struct book*)malloc(BOOKSIZE);
                  }
                  //复制除了要删除的书籍的其他书籍
                  strcpy(p1->id,id1);
                  strcpy(p1->name,name1);
                  strcpy(p1->author,author1);
                  p1->count=count1;
              }

          }
           if(flag==0)
              {
                  head=NULL;
              }
              else
              {
                  p2->next=p1;
                  p1->next=NULL;
                  fclose(fp);
              }
         }
         fp=fopen("library.txt","w");
         fclose(fp);
         fp=fopen("library.txt","a");
         p=head;
         for (;p!=NULL;)//重新编写文本
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s删除成功,按任意键返回...\n",delectName);
   getch();
   bookFunction();
}
}
void findBook()//查找图书
{
     system("cls");
    printf("------星星图书馆------");
    printf("\n 1.id查找\n");
    printf("\n 2.书名查找");
    printf("\n----------------------\n");
    printf("请选择查找方式:\n");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        findBookId();
        break;
    default:
        findBookName();
        break;
    }


}

void findBookId()
{
    system("cls");
    FILE*fp;
    char idFind[100],id[100],name[100],author[100];
    int num,flag,count;
    flag=0;
    if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
    {
    int i;
    printf("请输入所要查找图书的id:\n");
    scanf("%s",idFind);
    printf("查找中.");
    Sleep(500);//系统暂时休眠0.5s
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf("\n");
    num=libraryCount();
    for(i=0;i<num;i++)
    {
         fscanf(fp,"%s%s%s%d",id,name,author,&count);
         if(strcmp(idFind,id)==0)
         {
             flag=1;
             printf("%s %s查找成功！\n",id,name);
             printf("按任意键继续...");
             getch();
             bookFunction();
         }
    }
    if(!flag)
    {
        printf("查找失败！按任意键返回...");
        getch();
        bookFunction();
    }
    }

}

void findBookName()
{
    system("cls");
    FILE*fp;
    char idFind[100],id[100],name[100],author[100];
    int num,flag,count;
    flag=0;
    if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
    {
    int i;
    printf("请输入所要查找图书的书名:\n");
    scanf("%s",idFind);
    printf("查找中.");
    Sleep(500);//系统暂时休眠0.5s
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf("\n");
    num=libraryCount();
    for(i=0;i<num;i++)
    {
         fscanf(fp,"%s%s%s%d",id,name,author,&count);
         if(strcmp(idFind,name)==0)
         {
             flag=1;
             printf("%s %s查找成功！\n",id,name);
             printf("按任意键继续...");
             getch();
             bookFunction();
         }
    }
    if(!flag)
    {
        printf("查找失败！按任意键返回...");
        getch();
        bookFunction();
    }
    }
}

int libraryCount()//统计书库中图书的个数
{
    FILE*fp;
    int count,i;
    char id[100],name[100],author[100];
    fp=fopen("library.txt","r");
    for(i=0;!feof(fp);i++)//循环到文本末尾
    {
         fscanf(fp,"%s%s%s%d\n",id,name,author,&count);
    }
    fclose(fp);
//    i--;
    return i ;
}

void bookList()//展示书籍列表
{
    system("cls");
    FILE*fp;
    char id[100],name[100],author[100];
    int count,num,i;
    num=libraryCount();
     if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
    {
    printf("搜索中.");
    Sleep(500);//系统暂时休眠0.5s
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf("\n");
    num=libraryCount();//统计书本本数
    printf("%d\n",num);
    if(num==0)
    {
        printf("\n该书库中暂无存书！按任意键返回...");
        getch();
        bookFunction();

    }
    else
    {
        system("cls");
          printf("\n书号\t书名\t\t\t   作者\t   书本数\n\n");
          printf("------------------------------------------------------\n");
         for(i=0;i<num;i++)
    {
         fscanf(fp,"%s%s%s%d",id,name,author,&count);
//         printf("%s\n",author);
//         printf("%d\n",count);
         printf("|%-5s%-30s%-10s%-7d|\n",id,name,author,count);
         printf("------------------------------------------------------\n");
    }
    fclose(fp);
    printf("按任意键返回...");
    getch();
    bookFunction();
    }
    }
}
void borrowBook()//借阅图书
{
    system("cls");
    FILE*fp;
    struct book*head=NULL;
    struct book*p,*p1,*p2;
    char id1[100],name1[100],author1[100],c,borrowName[100];
    char id2[100],name2[100],author2[100];
    int count1,num,i,j,flag,flag1,count2;
    flag=0,flag1=0;
 if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
 {
      printf("请输入你要借阅的书籍的名字:\n");
      scanf("%s",borrowName);
      printf("确认要借阅该书？若取消该操作请点ESC，若确定点击回车...");
      c=getch();//判断是不是ESC
      if(c==27)
      {
          bookFunction();
      }
       else{
          fp=fopen("library.txt","r");
          num=libraryCount();
//          printf("\n %d",num);
        for(i=0;i<num;i++)
        {

         fscanf(fp,"%s%s%s%d",id2,name2,author2,&count2);
         if(strcmp(borrowName,name2)==0)
         {
             flag1=1;
             if(count2==0)
             {
                  printf("\n%s暂无库存，十分抱歉，请按任意键返回...",name2);
                      getch();
                      bookFunction();
             }
         }
        }
        fclose(fp);
        if(flag1)
        {
             fp=fopen("library.txt","r");
            for(j=0;j<num;j++)
          {
              fscanf(fp,"%s%s%s%d",id1,name1,author1,&count1);
                  flag++;//作为判断是否存在链表的旗帜
                  if(flag==1)//创建链表
                  {
                      p1=p2=(struct book*)malloc(BOOKSIZE);
                      head=p1;
                  }
                  else
                  {
                      p2->next=p1;
                      p2=p1;
                      p1=(struct book*)malloc(BOOKSIZE);
                  }
                  //复制书籍
                  strcpy(p1->id,id1);
                  strcpy(p1->name,name1);
                  strcpy(p1->author,author1);
                  if(count1>0)
                  {
                      if(strcmp(borrowName,name1)==0)
                  {
                      p1->count=count1-1;
                  }
                  else
                  {
                      p1->count=count1;
                  }
                  }
//                  else
//                  {
//                      printf("\n%s暂无库存，十分抱歉，请按任意键返回...",p1->name);
//                      getch();
//                      bookFunction();
//                  }

          }
        if(flag==0)
              {
                  head=NULL;
              }
              else
              {
                  p2->next=p1;
                  p1->next=NULL;
                  fclose(fp);
              }
              fp=fopen("library.txt","w");
         fclose(fp);
         fp=fopen("library.txt","a");
         p=head;
         for (;p!=NULL;)//重新编写文本
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s借阅成功,按任意键返回...\n",borrowName);
   getch();
   bookFunction();
         }
         else
         {
             printf("\n%s不存在，请确认你是否借阅正确！",borrowName);
             printf("\n按任意键返回...\n");
             getch();
             bookFunction();
         }

       }

     }

}
void returnBook()//归还图书
{
    system("cls");
    FILE*fp;
    struct book*head=NULL;
    struct book*p,*p1,*p2;
    char id1[100],name1[100],author1[100],c,returnName[100];
    char id2[100],name2[100],author2[100];
    int count1,num,i,j,flag,flag1,count2;
    flag=0,flag1=0;
 if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("该书库不存在！按任意键返回...");
     getch();
     bookFunction();
 }
 else
 {
      printf("请输入你要的归还籍的名字:\n");
      scanf("%s",returnName);
      printf("确认要归还该书？若取消该操作请点ESC，若确定点击回车...");
      c=getch();//判断是不是ESC
      if(c==27)
      {
          bookFunction();
      }
      else{
          fp=fopen("library.txt","r");
          num=libraryCount();
//          printf("\n %d",num);
        for(i=0;i<num;i++)
        {

         fscanf(fp,"%s%s%s%d",id2,name2,author2,&count2);
         if(strcmp(returnName,name2)==0)
         {
             flag1=1;
         }
        }
        fclose(fp);
        if(flag1)
        {
             fp=fopen("library.txt","r");
            for(j=0;j<num;j++)
          {
              fscanf(fp,"%s%s%s%d",id1,name1,author1,&count1);
                  flag++;//作为判断是否存在链表的旗帜
                  if(flag==1)//创建链表
                  {
                      p1=p2=(struct book*)malloc(BOOKSIZE);
                      head=p1;
                  }
                  else
                  {
                      p2->next=p1;
                      p2=p1;
                      p1=(struct book*)malloc(BOOKSIZE);
                  }
                  //复制书籍
                  strcpy(p1->id,id1);
                  strcpy(p1->name,name1);
                  strcpy(p1->author,author1);

                      if(strcmp(returnName,name1)==0)
                  {
                      p1->count=count1+1;//剩余数量
                  }
                  else
                  {
                      p1->count=count1;
                  }

          }
        if(flag==0)
              {
                  head=NULL;
              }
              else
              {
                  p2->next=p1;
                  p1->next=NULL;
                  fclose(fp);
              }
              fp=fopen("library.txt","w");
         fclose(fp);
         fp=fopen("library.txt","a");
         p=head;
         for (;p!=NULL;)//重新编写文本
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s归还成功,按任意键返回...\n",returnName);
   getch();
   bookFunction();
         }
         else
         {
             printf("\n%s不存在，请确认你是否归还正确！",returnName);
             printf("\n按任意键返回...\n");
             getch();
             bookFunction();
         }


     } }


}
int main()
{
    logIn();//登录界面
    return 0;
}
