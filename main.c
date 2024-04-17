#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#define BOOKSIZE sizeof(struct book)//ͼ��
#define USERSIZE sizeof(struct user)//��¼�û�

 struct book
{
    char id[100],name[100],author[100];

    int count;//�ڹ�������
    struct book*next;
};

 struct user
{
    int username;
    char password[30];
    struct user*next;

};

void logMenu();//��¼����
void logIn();//��¼�������
void land();//�û���¼
void signIn();//ע���û�
int  isSucceed(char name[],char password[]);//�ж��û����������Ƿ���ȷ
void bookMenu();//ͼ�鹦�ܳ�ʼ�˵�
void bookFunction();//ͼ�鹦��ѡ�����
void addBook();//����ͼ��
void delectBook();//ɾ��ͼ��
void delectBookName();//������ɾ��
void delectBookId();//��idɾ��
void findBook();//����ͼ��
void findBookId();//id����
void findBookName();//��������
int libraryCount();//ͳ�������ͼ��ĸ���
void bookList();//չʾ�鼮�б�
void borrowBook();//����ͼ��
void returnBook();//�黹ͼ��


void logMenu()
{
printf("\n    ��ӭ��������ͼ�����ϵͳ\n");
printf("---------------------------------");
printf("\n|\t 1.�û���¼\t\t|\n");
printf("\n|\t 2.ע���û�\t\t|\n");
printf("\n|\t 3.�˳�ϵͳ\t\t|\n");
printf("---------------------------------\n");
}
void logIn()//��¼�������
{
    int choose;
    logMenu();
    printf("�밴��ѡ����:\n");
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
        system("cls");//����
        exit(0);
        break;

    }

}

void land()//�ж��Ƿ��½�ɹ�
{
    char userName[100];
    char password[100];
    int flag;
    system("cls");//����
    printf("\n�������˺�:\n");
//    gets(userName);
scanf("%s",userName);
    printf("\n����������:\n");
    scanf("%s",password);
    flag=isSucceed(userName,password);
    if(flag==1)
    {
        printf("��½��.");
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
        printf("\n��½�ɹ�����ӭ��������ͼ�����ϵͳ�������������...");
        getch();//ֱ�Ӽ��̵õ���ֵ������Ҫ�ٻس�
        bookFunction();

    }
    else if(flag==-1)
    {
        printf("�������������������������");
        getch();
        land();//���»ص���¼�������
    }
    else{
        printf("�û������ڣ���ע���û�");
        getch();
        system("cls");
        logIn();//�ص���ʼ��¼����
    }

}

void signIn()//ע���˻�
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
    fp=fopen("user.txt","a");//��ֻд�ķ�ʽ�����ļ�ĩβ�������
    printf("�������˺ź�����:\n�û��� ����\n");
    scanf("%s %s",userName,password);
    printf("���ٴ���������:\n");
    scanf("%s",re_password);

         if(strcmp(password,re_password)==0)
    {
        fprintf(fp,"%-10s %-15s\n",userName,password);

    }
    else
    {
        printf("�����������벻һ������س�����ע��");
        system("cls");
        logIn();
    }
    fclose(fp);
    printf("ע��ɹ�!\n");
    printf("�밴���������...");
    getch();
    system("cls");
    logIn();

}

int isSucceed(char name[],char password[])//�ж��û��Ĵ�����
{
    FILE*fp;
    char userName[100];
    char userPassword[100];
    if((fp=fopen("user.txt","r"))==NULL)
    {
        system("cls");
        printf("�û������ڣ���ע���û�");
        getch();
        system("cls");
        logIn();
    }
    while(!feof(fp))//�ж��Ƿ�����ļ�ĩβ
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



void bookMenu()//ͼ�鹦�ܽ���
{
    system ("cls");
    printf("--------------����ͼ���-----------------");
    printf("\n 1.����ͼ��\t\t\t\t|\n");
    printf("\n 2.ɾ��ͼ��\t\t\t\t|\n");
    printf("\n 3.����ͼ��\t\t\t\t|\n");
    printf("\n 4.���ͼ��\t\t\t\t|\n");
    printf("\n 5.����ͼ��\t\t\t\t|\n");
    printf("\n 6.�黹ͼ��\t\t\t\t|\n");
    printf("\n 7.�˳�ϵͳ\t\t\t\t|\n");
    printf("-----------------------------------------\n");
}

void bookFunction()//ͼ�鹦�ܽ������
{
    bookMenu();
    printf("�밴��ѡ��:\n");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        addBook();//����
        break;
    case 2:
        delectBook();//ɾ��
        break;
    case 3:
        findBook();//����
        break;
    case 4:
        bookList();//�б�
        break;
    case 5:
        borrowBook();//����
        break;
    case 6:
        returnBook();//�黹
        break;
    default:
        system("cls");
        exit(0);
    }

}

void addBook()//����ͼ��
{
    system("cls");
    FILE*fp;
    char id[100],name[100],author[100];//id������������
    int count;//��������
    if((fp=fopen("library.txt","r"))==NULL)
    {
        fp=fopen("library.txt","w");//û�оʹ���һ������ͼ���txt
        fclose(fp);
    }
    fp=fopen("library.txt","a");
    printf("�������������ӵ�ͼ��\nid ���� ���� ����\n");
    scanf("%s %s %s %d",id,name,author,&count);
    fprintf(fp,"%-5s%-30s%-10s%-7d\n",id,name,author,count);
    fclose(fp);
    printf("%s��ӳɹ����밴�س�����...",name);
    getch();
    bookFunction();
}
void delectBook()//ɾ��ͼ��
{
    system("cls");
    printf("------����ͼ���------");
    printf("\n 1.idɾ��");
    printf("\n 2.����ɾ��");
    printf("\n----------------------\n");
    printf("��ѡ��ɾ����ʽ:\n");
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

void delectBookName()//������ɾ��
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
 {
      printf("��������Ҫɾ�����鼮������:\n");
      scanf("%s",delectName);
      printf("ȷ��Ҫɾ�����飿��ȡ���ò������ESC����ȷ������س�...");
      c=getch();//�ж��ǲ���ESC
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
              if(strcmp(delectName,name1)!=0)//�ж��Ƿ�������ͬ�����������ƹ���
              {
                  flag++;//��Ϊ�ж��Ƿ�������������
                  if(flag==1)//��������
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
                  //���Ƴ���Ҫɾ�����鼮�������鼮
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
         for (;p!=NULL;)//���±�д�ı�
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%sɾ���ɹ�,�����������...\n",delectName);
   getch();
   bookFunction();

     }

}
void delectBookId()//��idɾ��
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
 {
      printf("��������Ҫɾ�����鼮��id:\n");
      scanf("%s",delectName);
      printf("ȷ��Ҫɾ�����飿��ȡ���ò������ESC����ȷ������س�...");
      c=getch();//�ж��ǲ���ESC
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
              if(strcmp(delectName,id1)!=0)//�ж��Ƿ�������ͬ�����������ƹ���
              {
                  flag++;//��Ϊ�ж��Ƿ�������������
                  if(flag==1)//��������
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
                  //���Ƴ���Ҫɾ�����鼮�������鼮
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
         for (;p!=NULL;)//���±�д�ı�
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%sɾ���ɹ�,�����������...\n",delectName);
   getch();
   bookFunction();
}
}
void findBook()//����ͼ��
{
     system("cls");
    printf("------����ͼ���------");
    printf("\n 1.id����\n");
    printf("\n 2.��������");
    printf("\n----------------------\n");
    printf("��ѡ����ҷ�ʽ:\n");
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
    {
    int i;
    printf("��������Ҫ����ͼ���id:\n");
    scanf("%s",idFind);
    printf("������.");
    Sleep(500);//ϵͳ��ʱ����0.5s
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
             printf("%s %s���ҳɹ���\n",id,name);
             printf("�����������...");
             getch();
             bookFunction();
         }
    }
    if(!flag)
    {
        printf("����ʧ�ܣ������������...");
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
    {
    int i;
    printf("��������Ҫ����ͼ�������:\n");
    scanf("%s",idFind);
    printf("������.");
    Sleep(500);//ϵͳ��ʱ����0.5s
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
             printf("%s %s���ҳɹ���\n",id,name);
             printf("�����������...");
             getch();
             bookFunction();
         }
    }
    if(!flag)
    {
        printf("����ʧ�ܣ������������...");
        getch();
        bookFunction();
    }
    }
}

int libraryCount()//ͳ�������ͼ��ĸ���
{
    FILE*fp;
    int count,i;
    char id[100],name[100],author[100];
    fp=fopen("library.txt","r");
    for(i=0;!feof(fp);i++)//ѭ�����ı�ĩβ
    {
         fscanf(fp,"%s%s%s%d\n",id,name,author,&count);
    }
    fclose(fp);
//    i--;
    return i ;
}

void bookList()//չʾ�鼮�б�
{
    system("cls");
    FILE*fp;
    char id[100],name[100],author[100];
    int count,num,i;
    num=libraryCount();
     if((fp=fopen("library.txt","r"))==NULL)
 {
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
    {
    printf("������.");
    Sleep(500);//ϵͳ��ʱ����0.5s
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
    num=libraryCount();//ͳ���鱾����
    printf("%d\n",num);
    if(num==0)
    {
        printf("\n����������޴��飡�����������...");
        getch();
        bookFunction();

    }
    else
    {
        system("cls");
          printf("\n���\t����\t\t\t   ����\t   �鱾��\n\n");
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
    printf("�����������...");
    getch();
    bookFunction();
    }
    }
}
void borrowBook()//����ͼ��
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
 {
      printf("��������Ҫ���ĵ��鼮������:\n");
      scanf("%s",borrowName);
      printf("ȷ��Ҫ���ĸ��飿��ȡ���ò������ESC����ȷ������س�...");
      c=getch();//�ж��ǲ���ESC
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
                  printf("\n%s���޿�棬ʮ�ֱ�Ǹ���밴���������...",name2);
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
                  flag++;//��Ϊ�ж��Ƿ�������������
                  if(flag==1)//��������
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
                  //�����鼮
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
//                      printf("\n%s���޿�棬ʮ�ֱ�Ǹ���밴���������...",p1->name);
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
         for (;p!=NULL;)//���±�д�ı�
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s���ĳɹ�,�����������...\n",borrowName);
   getch();
   bookFunction();
         }
         else
         {
             printf("\n%s�����ڣ���ȷ�����Ƿ������ȷ��",borrowName);
             printf("\n�����������...\n");
             getch();
             bookFunction();
         }

       }

     }

}
void returnBook()//�黹ͼ��
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
     printf("����ⲻ���ڣ������������...");
     getch();
     bookFunction();
 }
 else
 {
      printf("��������Ҫ�Ĺ黹��������:\n");
      scanf("%s",returnName);
      printf("ȷ��Ҫ�黹���飿��ȡ���ò������ESC����ȷ������س�...");
      c=getch();//�ж��ǲ���ESC
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
                  flag++;//��Ϊ�ж��Ƿ�������������
                  if(flag==1)//��������
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
                  //�����鼮
                  strcpy(p1->id,id1);
                  strcpy(p1->name,name1);
                  strcpy(p1->author,author1);

                      if(strcmp(returnName,name1)==0)
                  {
                      p1->count=count1+1;//ʣ������
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
         for (;p!=NULL;)//���±�д�ı�
   {
   	   fprintf(fp,"%-5s%-30s%-10s%-7d\n",p->id,p->name,p->author,p->count);
   	   p=p->next;
   }
   fclose(fp);
   printf("\n%s�黹�ɹ�,�����������...\n",returnName);
   getch();
   bookFunction();
         }
         else
         {
             printf("\n%s�����ڣ���ȷ�����Ƿ�黹��ȷ��",returnName);
             printf("\n�����������...\n");
             getch();
             bookFunction();
         }


     } }


}
int main()
{
    logIn();//��¼����
    return 0;
}
