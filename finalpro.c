#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//handled cases
struct case_handled
{
    int sno;
    char *case_details;
    char *status;
};
int ci,ga,cr; //to refer position in array

//structure for date
struct date
{
    int dd,mm,yy;
};

//cases to be handled
struct case_inhand
{
    int caseno;
    struct date r;
    struct date d;
    char *name;
    long int fare; //advance
    long long int contact_no;
    char *case_details;
    struct case_inhand *next;
};

typedef struct case_inhand *ih_node;
ih_node new,temp,prev;

//creating header for civil,general and criminal lawyers.
typedef ih_node header;
header a1,a2,a3;

void create_list(){
    a1=(struct case_inhand*)malloc(sizeof(struct case_inhand));
    a2=(struct case_inhand*)malloc(sizeof(struct case_inhand));
    a3=(struct case_inhand*)malloc(sizeof(struct case_inhand));
    a1->next=NULL;
    a2->next=NULL;
    a3->next=NULL;
    if(a1==NULL||a2==NULL||a3==NULL)
        printf("FATAL ERROR : Failure in memory allocation !!");
}
//lawyer structure
struct lawyer_details
{
    char *name;
    int contact;
    char *gender;
    int experience;
    char *qualification;
    struct case_handled ch[25];
    struct case_inhand *ih_node;
}l[3];

//creating lawyer details
void create_linfo(){
    create_list();
    int i;
    //lawyer1
    l[0].name="SARAVANAN";
    l[0].contact=44577;
    l[0].gender="Male";
    l[0].experience=7;
    l[0].qualification="BA.BL,LLB.,";
    //values for handled cases
    l[0].ch[0].sno=1;
    l[0].ch[0].case_details="AGAINST CONSTRUCTING APARTMENT IN LAKE";
    l[0].ch[0].status="WIN";
    l[0].ch[1].sno=2;
    l[0].ch[1].case_details="MURUGAN'S FAMILY LAND ISSUE";
    l[0].ch[1].status="WIN";
    ci=1;

    for(i=0;i<2;i++){
        new=(struct case_inhand*)malloc(sizeof(struct case_inhand));
        if(i==0){
            new->caseno=94673;
            new->name="SELVAN";
            new->r.dd=20;
            new->r.mm=10;
            new->r.yy=2020;
            new->d.dd=16;
            new->d.mm=11;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="COMMON WALL ISSUE";
            new->contact_no=9765894032;
            new->next=NULL;
            a1->next=new;
        }
        else{
            new->caseno=94783;
            new->name="ANANYA";
            new->r.dd=1;
            new->r.mm=11;
            new->r.yy=2020;
            new->d.dd=24;
            new->d.mm=12;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="SCHOOL BUILDING COLLAPSE";
            new->contact_no=9867994013;
            new->next=a1->next;
            a1->next=new;
        }
    }

    //lawyer2
    l[1].name="VENBA";
    l[1].contact=43579;
    l[1].gender="Female";
    l[1].experience=9;
    l[1].qualification="BA.BL,LLM";
    //values for handled cases
    l[1].ch[0].sno=1;
    l[1].ch[0].case_details="INJUSTICE TO FARMER";
    l[1].ch[0].status="WIN";
    l[1].ch[1].sno=2;
    l[1].ch[1].case_details="AGAINST CURRUPTION";
    l[1].ch[1].status="WIN";
    ga=1;

    for(i=0;i<2;i++){
        new=(struct case_inhand*)malloc(sizeof(struct case_inhand));
        if(i==0){
            new->caseno=78965;
            new->name="KAVITHA";
            new->r.dd=14;
            new->r.mm=10;
            new->r.yy=2020;
            new->d.dd=13;
            new->d.mm=12;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="AGAINST POLLUTION OF DRINKING WATER";
            new->contact_no=8556736732;
            new->next=NULL;
            a2->next=new;
        }
        else{
            new->caseno=45673;
            new->name="SASIRAJ";
            new->r.dd=10;
            new->r.mm=9;
            new->r.yy=2020;
            new->d.dd=20;
            new->d.mm=11;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="AGAINST POOR QUALITY FOOD PRODUCT";
            new->contact_no=7367839013;
            new->next=a2->next;
            a2->next=new;
        }
    }

    //lawyer3
    l[2].name="JOSHEP";
    l[2].contact=45587;
    l[2].gender="Male";
    l[2].experience=6;
    l[2].qualification="B.sc(law),LLB.,";
    //values for handled cases
    l[2].ch[0].sno=1;
    l[2].ch[0].case_details="DEFENDED AGAINST CHILD KIDNAPPING";
    l[2].ch[0].status="WIN";
    l[2].ch[1].sno=2;
    l[2].ch[1].case_details="DRUNK AND DRIVE CASE";
    l[2].ch[1].status="WIN";
    cr=1;

    for(i=0;i<2;i++){
        new=(struct case_inhand*)malloc(sizeof(struct case_inhand));
        if(i==0){
            new->caseno=86785;
            new->name="SHAKTHI";
            new->r.dd=2;
            new->r.mm=11;
            new->r.yy=2020;
            new->d.dd=12;
            new->d.mm=12;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="AGAINST FAKE VOTE";
            new->contact_no=9735934332;
            new->next=NULL;
            a3->next=new;
        }
        else{
            new->caseno=47673;
            new->name="THIRU";
            new->r.dd=16;
            new->r.mm=11;
            new->r.yy=2020;
            new->d.dd=18;
            new->d.mm=11;
            new->d.yy=2020;
            new->fare=15000;
            new->case_details="MURDER CASE";
            new->contact_no=9371864813;
            new->next=a3->next;
            a3->next=new;
        }
    }

}
void disp_ih(ih_node x){
    printf("\n\nCASE NO   REG.DATE      DATE   \t\t  NAME  \t  CONTACT    \t ADV.FARE\t \t CASE DETAILS ");
    printf("\n__________________________________________________________________________________________________________________");
    temp=x->next;
    while(temp!=NULL){
        printf("\n\n%d \t%d/%d/%d\t%d/%d/%d  \t%s   \t%lld    \t%ld \t\t%s",temp->caseno,temp->r.dd,temp->r.mm,temp->r.yy,temp->d.dd,temp->d.mm,temp->d.yy,temp->name,temp->contact_no,temp->fare,temp->case_details);
        temp=temp->next;
    }
}

//display details of lawyer
void display(int x){
    printf("\n\t___________THE DETAILS OF LAWYER_____________");
    printf("\n\n\t\tName                : %s",l[x].name);
    printf("\n\t\tContact             : %d",l[x].contact);
    printf("\n\t\tGender              : %s",l[x].gender);
    printf("\n\t\tExperience          : %d",l[x].experience);
    printf("\n\t\tQualification       : %s",l[x].qualification);
    if(x==0){
        printf("\n\n\t\tTotal case handled  : %d",ci+1);
        printf("\n\n\n\t\t\t................ THE HANDLING CASES OF CIVIL ADVOCATE ................");
        disp_ih(a1);
    }
    else if(x==1){
        printf("\n\n\t\tTotal case handled  : %d",ga+1);
        printf("\n\n\n\t\t\t................ THE HANDLING CASES OF GENERAL ADVOCATE ................");
        disp_ih(a2);
    }
    else if(x==2){
        printf("\n\n\t\tTotal case handled  : %d",cr+1);
        printf("\n\n\n\t\t\t................ THE HANDLING CASES OF CRIMINAL ADVOCATE ................");
        disp_ih(a3);
    }
    else{
        printf("\n\n\tNO SUCH LAWYER");
    }
    printf("\n______________________________________________________________________________________________________________________________");
}

//function to insert values into cases in hand
ih_node insert_inhand(ih_node x)
{
    int yn2,day,mon,year,day1,mon1,year1,found=0;
    printf("\nEnter your case date(dd mm yyyy):");
    scanf("%d%d%d",&day,&mon,&year);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    year1=tm.tm_year + 1900;
    mon1=tm.tm_mon + 1;
    day1=tm.tm_mday;
    if(day1>day && mon1>=mon && year1>=year){
        printf("\nTHE DATE HAS BEEN PASSED.Are you wished to change your date: \n\t1.YES \n\t2.NO\nEnter your choice:");
        scanf("%d",&yn2);
        if(yn2==1)
            insert_inhand(x);
        else{
            printf("\n_/\\_THANK YOU_/\\_");
        }
    }
    else{
    temp=x;
    while(temp->next!=NULL){
        temp=temp->next;
        if(day==temp->d.dd && mon==temp->d.mm &&year==temp->d.yy)
            found++;
    }
    if(found==0){
         new=(struct case_inhand*)malloc(sizeof(struct case_inhand));
         new->name=(char *)malloc(sizeof(char)*25);
         new->case_details=(char *)malloc(sizeof(char)*25);
         if(new==NULL){
            printf("not allocated");
         } else{
         printf("\nEnter your case no:");
         scanf("%d",&new->caseno);
         printf("\nEnter your name:");
         scanf("%c",&temp); // temp statement to clear buffer
         scanf("%[^\n]",new->name);
         printf("\nEnter your contact no.:");
         scanf("%lld",&new->contact_no);
         printf("\nEnter your case details:");
         scanf("%c",&temp);
         scanf("%[^\n]",new->case_details);
         printf("\nEnter the advance:");
         scanf("%ld",&new->fare);
         while(new->fare<15000){
            printf("\n\nYOUR ADVANCE AMOUNT IS LOW!! PAY Rs.15000.\nEnter the advance:");
            scanf("%ld",&new->fare);
         }
         //to store current date as registration date
         time_t t = time(NULL);
         struct tm tm = *localtime(&t);
         new->r.yy=tm.tm_year + 1900;
         new->r.mm=tm.tm_mon + 1;
         new->r.dd=tm.tm_mday;
         new->d.dd=day;
         new->d.mm=mon;
         new->d.yy=year;
         new->next=x->next;
         x->next=new;
         printf("\nYOUR ADVOCATE IS BOOKED.WE RECEIVED YOUR ADVANCE PAYMENT_/\\_");
        }
    }
    else{
        int yn;
        printf("\nAdvocate is already booked on that date..Are you wished to change your date: \n\t1.YES \n\t2.NO\nEnter your choice:");
        scanf("%d",&yn);
        if(yn==1)
            insert_inhand(x);
        else
            printf("\nOOPS!! THE LAWYER IS PREBOOKED!");
    }
    }
    return x;
}
//function to get days or months
int date_month(){
        int refund,cash;
        int i,j,k,n,m,o,days,mon,year;
        cash=temp->fare;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        o=tm.tm_year + 1900;
        m=tm.tm_mon + 1;
        n=tm.tm_mday;
        i=temp->r.dd;
        j=temp->r.mm;
        k=temp->r.yy;
        if(o==k){
                for(days=0;i!=n || j!=m;++days){
                    if( i==31&&(temp->r.mm==1 || temp->r.mm==3 || temp->r.mm==5 || temp->r.mm== 7 || temp->r.mm== 8|| temp->r.mm==10||temp->r.mm==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(temp->r.mm==2){
                        if(temp->r.yy%4==0 && temp->r.yy%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else
                        if((temp->r.mm==4||temp->r.mm==6||temp->r.mm==9||temp->r.mm==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    i++;
                }
                if(days==0)
                    refund=cash;
                else if(days<=30){
                    refund = cash*90/100;
                }
                else{
                    refund =cash*40/100;
                }
        }
        else{
                for(days=0;i!=n || j!=m || k!=o;++days){
                    if( i==31&&(temp->r.mm==1 || temp->r.mm==3 || temp->r.mm==5 || temp->r.mm== 7 || temp->r.mm== 8|| temp->r.mm==10||temp->r.mm==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(temp->r.mm==2){
                        if(temp->r.yy%4==0 && temp->r.yy%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else if(j==12){
                        j=1;
                        k++;
                    }
                    else{
                        if((temp->r.mm==4||temp->r.mm==6||temp->r.mm==9||temp->r.mm==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    }
                    i++;
                }
                if(days<=30){
                    refund =cash*90/100;
                }
                else if(days<=365){
                    refund =cash*40/100;
                }
                else{
                    refund =0;
                }
        }
        return refund;
}
//function to withdraw a case
ih_node withdraw(ih_node x)
{
    int cno;
    printf("\nEnter your case no.:");
    scanf("%d",&cno);
    temp=x->next;
    prev=x;
    while(temp!=NULL && temp->caseno!=cno){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        int ch1;
        printf("\n\nYOUR CASE NUMBER IS INVALID!!\nDO YOU WANT TO CONTINUE:\n\t1.YES\n\t2.NO\nENTER YOUR CHOICE:");
        scanf("%d",&ch1);
        if(ch1==1)
            withdraw(x);
        else
            printf("\n_/\\_THANK YOU_/\\_");
    }
    else
    {
        int cash;
        cash=date_month();
        if(cash==0){
            printf("\n\nNO REFUND AMOUNT ..\n _/\\_THANK YOU _/\\_");
        }
        else
            printf("\n\nYour amount to be refunded is : Rs.%d",cash);
        prev->next=temp->next;
        free(temp);
        printf("\nYOUR CASE IS WITHDRAWN!!_/\\_THANK YOU _/\\_");
    }
    return x;
}
//function to update the case date
ih_node postpond_date(ih_node x){
    int case_no;
    printf("\nEnter your case no:");
    scanf("%d",&case_no);
    temp=x->next;
    while(temp!=NULL && temp->caseno!=case_no){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\n\nYOUR CASE NUMBER IS INVALID!!");
        int ch1;
        printf("\nDO YOU WANT TO CONTINUE:\n\t1.YES\n\t2.NO\nENTER YOUR CHOICE:");
        scanf("%d",&ch1);
        if(ch1==1)
            postpond_date(x);
        else
            printf("\n_/\\_THANK YOU_/\\_");
    }
    else{
        int day1,mon1,year1;
        printf("\nEnter your postponed date(dd mm yy):");
        scanf("%d %d %d",&day1,&mon1,&year1);
        if(mon1==temp->d.mm && year1==temp->d.yy){
            if(day1<temp->d.dd)
                printf("\nYou cannot preponed the case date.");
            else{
            temp->d.dd=day1;
            temp->d.mm=mon1;
            temp->d.yy=year1;
            printf("\n~~YOUR CASE DATE HAS BEEN MODIFIED~~");
            }
        }
        else if(year1==temp->d.yy){
            if(mon1<temp->d.mm)
                printf("\nYou cannot preponed the case date.");
            else{
            temp->d.dd=day1;
            temp->d.mm=mon1;
            temp->d.yy=year1;
            printf("\n~~YOUR CASE DATE HAS BEEN MODIFIED~~");
            }
        }
        else if(year1<temp->d.yy)
               printf("\nYou cannot preponed the case date.");
        else{
            temp->d.dd=day1;
            temp->d.mm=mon1;
            temp->d.yy=year1;
            printf("\n~~YOUR CASE DATE HAS BEEN MODIFIED~~");
        }
    }
    return x;
}
//function for receipt
void receipt(int caseno,char name[],long long int contact_no,int fare,int money,int cash){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\n\t ________________________________________________________");
    printf("\n\t|         *********      RECEIPT       *********         |");
    printf("\n\t|                  ********************                  |");
    printf("\n\t|                                                        |");
    printf("\n\t                                     DATE  : %d/%d/%d  ",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900);
    printf("\n\t|                                                        |");
    printf("\n\t|         CASE NO.    : %d                            |",caseno);
    printf("\n\t          NAME        : %s                    ",name);
    printf("\n\t|         CONTACT NO. : %lld                       |",contact_no);
    printf("\n\t|                                                        |");
    printf("\n\t                                    ADVANCE  : Rs.%d  ",fare);
    printf("\n\t|                                   CASH     : Rs.%d  |",cash);
    printf("\n\t|                                  _____________________ |");
    printf("\n\t                                    TOTAL    : Rs.%d  ",money);
    printf("\n\t|                                                        |");
    printf("\n\t|             HAVE A HAPPY AND JOYFUL LIFE               |");
    printf("\n\t|________________________________________________________|");

}
//function calculate days
int cal_days(int d1,int m1,int y1,int d2,int m2,int y2){
        int days=0;
        int i,j,k,m,n,o;
        i=d1;
        j=m1;
        k=y1;
        n=d2;
        m=m2;
        o=y2;
        if(o==k){
                for(days=0;i!=n || j!=m;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    i++;
                }
        }
        else{
        for(days=0;i!=n || j!=m || k!=o;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else if(j==12){
                        j=1;
                        k++;
                    }
                    else{
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    }
                    i++;
                }
        }
        return days;
}
//function for result of case
ih_node result_case(ih_node x,int i){
    int case_no;
    printf("\nEnter your case no.:");
    scanf("%d",&case_no);
    temp=x->next;
    prev=x;
    while(temp!=NULL && temp->caseno!=case_no){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\n\nYOUR CASE NUMBER IS INVALID!!");
        int ch1;
        printf("\nDO YOU WANT TO CONTINUE:\n\t1.YES\n\t2.NO\nENTER YOUR CHOICE:");
        scanf("%d",&ch1);
        if(ch1==1)
            result_case(x,i);
        else
            printf("\n_/\\_THANK YOU_/\\_");
    }
    else{
        int ok=0;
        int day,mon,year,noc;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year=tm.tm_year + 1900;
        mon=tm.tm_mon + 1;
        day=tm.tm_mday;
        if(mon==temp->d.mm && year==temp->d.yy){
            if(day<temp->d.dd)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
            else
                noc=0;
        }
        else if(year==temp->d.yy){
            if(mon<temp->d.mm)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
            else
                noc=0;
        }
        else if(year<temp->d.yy)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
        else
            noc=0;

        if(noc>0){
            char yn[5];
            char y1[]="YES";
            char y2[]="yes";
            printf("\n\nYour CASE not yet come to the court.\nYou could only able to withdraw the case !!\nDo you want really want to foot the bill?(YES/NO): ");
            scanf("%s",yn);
            if(strcmp(yn,y1)==0 || strcmp(yn,y2)==0 ){
                withdraw(x);
            }
            else{
               printf("\nOOPS!! You cannot delete your case before it come to court.");
            }
        }else{
        int un,money,cash;
        char wl[10],w[]="WIN";
        char w2[]="win";
        if(i==0){
            un=++ci;
        }
        else if(i==1){
            un=++ga;
        }
        else{
            un=++cr;
        }
        l[i].ch[un].status=(char *)malloc(sizeof(char)*25);//memory allocation of variable
        l[i].ch[un].case_details=(char *)malloc(sizeof(char)*25);//memory allocation of variable
        l[i].ch[un].sno=un+1;
        l[i].ch[un].case_details=temp->case_details;
        printf("\nWhat is your case status :::: ");
        scanf("%s",l[i].ch[un].status);
        strcpy(wl,l[i].ch[un].status);
        if(strcmp(wl,w)==0 || strcmp(wl,w2)==0 ){
            if(i==0){
                cash=20000;
                money=temp->fare+20000;
            }
            else if(i==1){
                cash=10000;
                money=temp->fare+10000;
            }
            else{
                cash=15000;
                money=temp->fare+15000;
            }
        }
        else{
            if(i==0){
                cash=9000;
                money=temp->fare+9000;
            }
            else if(i==1){
                cash=5000;
                money=temp->fare+5000;
            }
            else{
                cash=7500;
                money=temp->fare+7500;
            }
        }
        receipt(temp->caseno,temp->name,temp->contact_no,temp->fare,money,cash);
        prev->next=temp->next;
        free(temp);
        printf("\n\n\t\t_/\\_THANK YOU:-) YOUR CASE IS ENDED_/\\_");
        }
    }
    return x;
}
//function to display handled cases
void display_case_handled(int i){
    int j;
    int un;
    if(i==0){
            un=ci;
    }
    else if(i==1){
            un=ga;
    }
    else{
            un=cr;
    }
    printf("\n\n\t.....CASES HANDLED BY ADVOCATE %s.....",l[i].name);
    for(j=0;j<=un;j++){
        printf("\n\n\tSNo.         :%d",l[i].ch[j].sno);
        printf("\n\tCase Details :%s",l[i].ch[j].case_details);
        printf("\n\tStatus       :%s",l[i].ch[j].status);
    }
}
//display specific case
void disp_spec_case(ih_node h){
    int cno;
    printf("\n\nEnter your case no.:");
    scanf("%d",&cno);
    temp=h->next;
    while(temp!=NULL && temp->caseno!=cno)
        temp=temp->next;
    if(temp==NULL)
        printf("\nOOPS (: YOUR CASE IS NOT FOUND!");
    else{
        printf("\nYour case details:");
        int day,mon,year,nob,noc;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year=tm.tm_year + 1900;
        mon=tm.tm_mon + 1;
        day=tm.tm_mday;
        nob=cal_days(temp->r.dd,temp->r.mm,temp->r.yy,day,mon,year);
        if(mon==temp->d.mm && year==temp->d.yy){
            if(day<temp->d.dd)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
            else
                noc=0;
        }
        else if(year==temp->d.yy){
            if(mon<temp->d.mm)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
            else
                noc=0;
        }
        else if(year<temp->d.yy)
                noc=cal_days(day,mon,year,temp->d.dd,temp->d.mm,temp->d.yy);
        else
            noc=0;
        printf("\n\n\tCASE NO     : %d",temp->caseno);
        printf("\n\tNAME        : %s",temp->name);
        printf("\n\tCONTACT NO  : %lld",temp->contact_no);
        printf("\n\tCASE DETAILS: %s",temp->case_details);
        printf("\n\tCASE DATE   : %d/%d/%d",temp->d.dd,temp->d.mm,temp->d.yy);
        printf("\n\tNo.Of Days passed from registration : %d",nob);
        printf("\n\tDays more for your case : %d",noc);
        printf("\n\tADVANCE FARE: %ld",temp->fare);
        printf("\n\n_____________________________________________________________________");
    }
}
//display at last
int disp_last(){
    int a;
    while(1){
        printf("\n\nPRESS 1 TO CONTINUE / 0 TO EXIT:::");
        scanf("%d",&a);
        if(a==1||a==0)
            break;
    }
    return a;
}
//welcome function
void welcome(){
    printf("\n\n\t\t\t\t\t\t\t**********************************************************");
    printf("\n\t\t\t\t\t\t\t*                   _/\\_ WELCOME _/\\_                    *");
    printf("\n\t\t\t\t\t\t\t**********************************************************");
    printf("\n\n\n\t\t\t\tGENERAL INSTRUCTIONS\n\t\t\t\t____________________\n\n\t\t-->Available advocates in the field :\n\t\t\t<> civil\n\t\t\t<> general\n\t\t\t<> criminal.\n\t\t-->Approach them anytime. You are always welcome.\n\t\t-->Book your Advocate, when he/she is AVAILABLE.\n\t\t-->To confirm lawyer, make advance payment. \n\t\t-->when your case is postponed, you need to update your date. ");
    printf("\n\t\t-->You can withdraw your case at any time.");
    printf("\n\t\t-->when your case is concluded,you need to specify the result and based on the result make payments.");
    printf("\n\t\t-->Please enter valid case date");
    printf("\n\n\n\t\t\t\t*** PAYMENT DETAILS ***\n\t\t\t\t ______________________\n");
    printf("\n\t\t\t\t ___________________________ ");
    printf("\n\t\t\t\t|                           |");
    printf("\n\t\t\t\t| ADVANCE AMOUNT : Rs.15000 |");
    printf("\n\t\t\t\t|___________________________|");
    printf("\n\n\t\t~~>For WITHDRAWING :(refund)\n\t\t\t  i.Within a month: 90 per REFUND\n\t\t\t ii.Within a year : 40 per REFUND\n\t\t\tiii.After a year  : NO REFUND!\n\t\t\t iv.On the same day : FULL REFUND!");
    printf("\n\n\t\t~~>For COMPLETION  :\n\t\t\t1.SUCCESS\n\t\t\t\t  i.civil   : Rs.20000\n\t\t\t\t ii.general : Rs.10000\n\t\t\t\tiii.criminal: Rs.15000\n\t\t\t2.LOSS\n\t\t\t\t  i.civil   : Rs.9000\n\t\t\t\t ii.general : Rs.5000\n\t\t\t\tiii.criminal: Rs.7500");
    printf("\n________________________________________________________________________________");
}
//main function
void main(){
    create_linfo();
    int ch,x,choice;
    do{
    welcome();
    int x;
    printf("\n\n\t0.Civil lawyer\n\t1.General advocate\n\t2.Criminal Lawyer\n\nSelect your advocate:");
    scanf("%d",&x);
    display(x);
    if(x==0){
            do{
                printf("\n\n\n\t1.To register case\n\t2.To revise your case date \n\t3.To withdraw your case \n\t4.To foot the bill\n\t5.To display your case\n\t6.To display lawyer's handled cases\n\t7.To display the handling cases\n\t0.To EXIT\n\nENTER YOUR CHOICE :");
                scanf("%d",&choice);
                switch(choice){
                    case 1: insert_inhand(a1);
                            break;
                    case 2: postpond_date(a1);
                            break;
                    case 3: withdraw(a1);
                            break;
                    case 4: result_case(a1,x);
                            break;
                    case 5: disp_spec_case(a1);
                            break;
                    case 6: display_case_handled(x);
                            break;
                    case 7: disp_ih(a1);
                            break;
                }
            }while(choice!=0);
    }
    else if(x==1){
        do{
                printf("\n\n\n\t1.To register case\n\t2.To revise your case date \n\t3.To withdraw your case \n\t4.To foot the bill\n\t5.To display your case\n\t6.To display lawyer's handled cases\n\t7.To display the handling cases\n\t0.To EXIT\n\nENTER YOUR CHOICE :");
                scanf("%d",&choice);
                switch(choice){
                    case 1: insert_inhand(a2);
                            break;
                    case 2: postpond_date(a2);
                            break;
                    case 3: withdraw(a2);
                            break;
                    case 4: result_case(a2,x);
                            break;
                    case 5: disp_spec_case(a2);
                            break;
                    case 6: display_case_handled(x);
                            break;
                    case 7: disp_ih(a2);
                            break;
                }
        }while(choice!=0);
    }
    else if(x==2){
         do{
                printf("\n\n\n\t1.To register case\n\t2.To revise your case date \n\t3.To withdraw your case \n\t4.To foot the bill\n\t5.To display your case\n\t6.To display lawyer's handled cases\n\t7.To display the handling cases\n\t0.To EXIT\n\nENTER YOUR CHOICE :");
                scanf("%d",&choice);
                switch(choice){
                    case 1: insert_inhand(a3);
                            break;
                    case 2: postpond_date(a3);
                            break;
                    case 3: withdraw(a3);
                            break;
                    case 4: result_case(a3,x);
                            break;
                    case 5: disp_spec_case(a3);
                            break;
                    case 6: display_case_handled(x);
                            break;
                    case 7: disp_ih(a3);
                            break;
                }
        }while(choice!=0);
    }
    else{
        printf("\n\n\tNO SUCH LAWYER");
    }
    printf("\n\n\t\t_/\\_THANK YOU _/\\_");

    ch=disp_last();
    }while(ch==1);
}
