//--------------------------
///*菜单显示程序*/
///*类似链表*/
///*18_1_4-18_1_5*/
///*杜祥汶*/
//--------------------------
#include "headfile.h"
#include "stdarg.h"                         //在void AddUp_Down(struct ShowMenu *pointer,...);函数中使用
#include "MENU_1.h"
#define LEN 4                                   //菜单栏目数

struct ShowMenu MainMenu_1,MainMenu_2,MainMenu_3,MainMenu_4,*FunShowMenu;//一级菜单//
//次级菜单
struct ShowMenu SecondaryMenu_1_1,SecondaryMenu_1_2,SecondaryMenu_1_3,SecondaryMenu_1_4;
struct ShowMenu SecondaryMenu_2_1,SecondaryMenu_2_2,SecondaryMenu_2_3,SecondaryMenu_2_4;
struct ShowMenu SecondaryMenu_3_1,SecondaryMenu_3_2,SecondaryMenu_3_3,SecondaryMenu_3_4;
struct ShowMenu SecondaryMenu_4_1,SecondaryMenu_4_2,SecondaryMenu_4_3,SecondaryMenu_4_4;




void StructInit ( void ) { //初始化菜单的结构体
//主菜单
    MainMenu_1.FunNow=&FunMainMenu_1;
    MainMenu_2.FunNow=&FunMainMenu_2;
    MainMenu_3.FunNow=&FunMainMenu_3;
    MainMenu_4.FunNow=&FunMainMenu_4;
    MainMenu_1.Right=&SecondaryMenu_1_1;
    MainMenu_2.Right=&SecondaryMenu_2_1;
    MainMenu_3.Right=&SecondaryMenu_3_1;
    MainMenu_4.Right=&SecondaryMenu_4_1;
    MainMenu_1.Left=NULL;
    MainMenu_2.Left=NULL;
    MainMenu_3.Left=NULL;
    MainMenu_4.Left=NULL;
    AddUp_Down ( &MainMenu_1,&MainMenu_2,&MainMenu_3,&MainMenu_4 );
//次级菜单一项
    SecondaryMenu_1_1.FunNow=&FunSecondaryMenu_1_1;
    SecondaryMenu_1_2.FunNow=&FunSecondaryMenu_1_2;
    SecondaryMenu_1_3.FunNow=&FunSecondaryMenu_1_3;
    SecondaryMenu_1_4.FunNow=&FunSecondaryMenu_1_4;
    SecondaryMenu_1_1.Left=&MainMenu_1;
    SecondaryMenu_1_2.Left=&MainMenu_1;
    SecondaryMenu_1_3.Left=&MainMenu_1;
    SecondaryMenu_1_4.Left=&MainMenu_1;
    SecondaryMenu_1_1.Right=NULL;
    SecondaryMenu_1_2.Right=NULL;
    SecondaryMenu_1_3.Right=NULL;
    SecondaryMenu_1_4.Right=NULL;
    AddUp_Down ( &SecondaryMenu_1_1,&SecondaryMenu_1_2,&SecondaryMenu_1_3,&SecondaryMenu_1_4 );
//次级菜单二项
    SecondaryMenu_2_1.FunNow=&FunSecondaryMenu_2_1;
    SecondaryMenu_2_2.FunNow=&FunSecondaryMenu_2_2;
    SecondaryMenu_2_3.FunNow=&FunSecondaryMenu_2_3;
    SecondaryMenu_2_4.FunNow=&FunSecondaryMenu_2_4;
    SecondaryMenu_2_1.Left=&MainMenu_2;
    SecondaryMenu_2_2.Left=&MainMenu_2;
    SecondaryMenu_2_3.Left=&MainMenu_2;
    SecondaryMenu_2_4.Left=&MainMenu_2;
    SecondaryMenu_2_1.Right=NULL;
    SecondaryMenu_2_2.Right=NULL;
    SecondaryMenu_2_3.Right=NULL;
    SecondaryMenu_2_4.Right=NULL;
    AddUp_Down ( &SecondaryMenu_2_1,&SecondaryMenu_2_2,&SecondaryMenu_2_3,&SecondaryMenu_2_4 );
//次级菜单三项
    SecondaryMenu_3_1.FunNow=&FunSecondaryMenu_3_1;
    SecondaryMenu_3_2.FunNow=&FunSecondaryMenu_3_2;
    SecondaryMenu_3_3.FunNow=&FunSecondaryMenu_3_3;
    SecondaryMenu_3_4.FunNow=&FunSecondaryMenu_3_4;
    SecondaryMenu_3_1.Left=&MainMenu_3;
    SecondaryMenu_3_2.Left=&MainMenu_3;
    SecondaryMenu_3_3.Left=&MainMenu_3;
    SecondaryMenu_3_4.Left=&MainMenu_3;
    SecondaryMenu_3_1.Right=NULL;
    SecondaryMenu_3_2.Right=NULL;
    SecondaryMenu_3_3.Right=NULL;
    SecondaryMenu_3_4.Right=NULL;
    AddUp_Down ( &SecondaryMenu_3_1,&SecondaryMenu_3_2,&SecondaryMenu_3_3,&SecondaryMenu_3_4 );
//次级菜单四项
    SecondaryMenu_4_1.FunNow=&FunSecondaryMenu_4_1;
    SecondaryMenu_4_2.FunNow=&FunSecondaryMenu_4_2;
    SecondaryMenu_4_3.FunNow=&FunSecondaryMenu_4_3;
    SecondaryMenu_4_4.FunNow=&FunSecondaryMenu_4_4;
    SecondaryMenu_4_1.Left=&MainMenu_4;
    SecondaryMenu_4_2.Left=&MainMenu_4;
    SecondaryMenu_4_3.Left=&MainMenu_4;
    SecondaryMenu_4_4.Left=&MainMenu_4;
    SecondaryMenu_4_1.Right=NULL;
    SecondaryMenu_4_2.Right=NULL;
    SecondaryMenu_4_3.Right=NULL;
    SecondaryMenu_4_4.Right=NULL;
    AddUp_Down ( &SecondaryMenu_4_1,&SecondaryMenu_4_2,&SecondaryMenu_4_3,&SecondaryMenu_4_4 );

//	FunShowMenu->Down=NULL;     ///*
//	FunShowMenu->Up=NULL;				//此处代码错误会导致  HardFault_Handler 错误(野指针)  在stdio.h中有NULL宏定义为0
//	FunShowMenu->Right=NULL; 		//此处指针未指空
//	FunShowMenu->Left=NULL;		  //*/

    FunShowMenu=&MainMenu_1;

    ( *FunShowMenu->FunNow ) ();
}




void AddUp_Down ( struct ShowMenu *pointer,... ) { //结构体链接成环函数
    uint8 Num;
    va_list FormalParameter;                                             ///*类似pintf函数实现方式*///  //int printf ( const char * format, ... );
    struct ShowMenu *ExchangePointer=pointer;
    struct ShowMenu *ExchangePointer_a=pointer;
    struct ShowMenu *ExchangePointer_b=pointer;
    va_start ( FormalParameter,pointer );
    for ( Num=0; Num<LEN-1; Num++ ) {
        ExchangePointer_b=va_arg ( FormalParameter,struct ShowMenu * );
        ExchangePointer_a->Down=ExchangePointer_b;
        ExchangePointer_b->Up=ExchangePointer_a;
        ExchangePointer_a=ExchangePointer_b;
    }
    ExchangePointer->Up=ExchangePointer_b;
    ExchangePointer_b->Down=ExchangePointer;
    va_end ( FormalParameter );
}
//菜单栏目显示函数

/*keil中报错(error：no matching function for call to ...),但编译能通过,不影响功能实现*/  //  /*IAR中能无错通过编译*/
void FunMainMenu_1 ( void ) {
    OLED_ShowChar ( 0,0,"0-4",1 );
    OLED_ShowChar ( 0,2,"0-1<-",1 );
    OLED_ShowChar ( 0,4,"0-2",1 );
//	printf("0_1\r\n");
}
void FunMainMenu_2 ( void ) {
    OLED_ShowChar ( 0,0,"0-1",1 );
    OLED_ShowChar ( 0,2,"0-2<-",1 );
    OLED_ShowChar ( 0,4,"0-3",1 );
//	printf("0_2\r\n");
}
void FunMainMenu_3 ( void ) {
    OLED_ShowChar ( 0,0,"0-2",1 );
    OLED_ShowChar ( 0,2,"0-3<-",1 );
    OLED_ShowChar ( 0,4,"0-4",1 );
//	printf("0_3\r\n");
}
void FunMainMenu_4 ( void ) {
    OLED_ShowChar ( 0,0,"0-3",1 );
    OLED_ShowChar ( 0,2,"0-4<-",1 );
    OLED_ShowChar ( 0,4,"0-1",1 );
//	printf("0_4\r\n");
}

void FunSecondaryMenu_1_1 ( void ) {
    OLED_ShowChar ( 0,0,"1-4",1 );
    OLED_ShowChar ( 0,2,"1-1<-",1 );
    OLED_ShowChar ( 0,4,"1-2",1 );
//	printf("1_1\r\n");
}
void FunSecondaryMenu_1_2 ( void ) {
    OLED_ShowChar ( 0,0,"1-1",1 );
    OLED_ShowChar ( 0,2,"1-2<-",1 );
    OLED_ShowChar ( 0,4,"1-3",1 );
//	printf("1_2\r\n");
}
void FunSecondaryMenu_1_3 ( void ) {
    OLED_ShowChar ( 0,0,"1-2",1 );
    OLED_ShowChar ( 0,2,"1-3<-",1 );
    OLED_ShowChar ( 0,4,"1-4",1 );
//	printf("1_3\r\n");
}
void FunSecondaryMenu_1_4 ( void ) {
    OLED_ShowChar ( 0,0,"1-3",1 );
    OLED_ShowChar ( 0,2,"1-4<-",1 );
    OLED_ShowChar ( 0,4,"1-1",1 );
//	printf("1_4\r\n");
}


void FunSecondaryMenu_2_1 ( void ) {
    OLED_ShowChar ( 0,0,"2-4",1 );
    OLED_ShowChar ( 0,2,"2-1<-",1 );
    OLED_ShowChar ( 0,4,"2-2",1 );
//	printf("2_1\r\n");
}
void FunSecondaryMenu_2_2 ( void ) {
    OLED_ShowChar ( 0,0,"2-1",1 );
    OLED_ShowChar ( 0,2,"2-2<-",1 );
    OLED_ShowChar ( 0,4,"2-3",1 );
//	printf("2_2\r\n");
}
void FunSecondaryMenu_2_3 ( void ) {
    OLED_ShowChar ( 0,0,"2-2",1 );
    OLED_ShowChar ( 0,2,"2-3<-",1 );
    OLED_ShowChar ( 0,4,"2-4",1 );
//	printf("2_3\r\n");
}
void FunSecondaryMenu_2_4 ( void ) {
    OLED_ShowChar ( 0,0,"2-3",1 );
    OLED_ShowChar ( 0,2,"2-4<-",1 );
    OLED_ShowChar ( 0,4,"2-1",1 );
//	printf("2_4\r\n");
}


void FunSecondaryMenu_3_1 ( void ) {
    OLED_ShowChar ( 0,0,"3-4",1 );
    OLED_ShowChar ( 0,2,"3-1<-",1 );
    OLED_ShowChar ( 0,4,"3-2",1 );
//	printf("3_1\r\n");
}
void FunSecondaryMenu_3_2 ( void ) {
    OLED_ShowChar ( 0,0,"3-1",1 );
    OLED_ShowChar ( 0,2,"3-2<-",1 );
    OLED_ShowChar ( 0,4,"3-3",1 );
//	printf("3_2\r\n");
}
void FunSecondaryMenu_3_3 ( void ) {
    OLED_ShowChar ( 0,0,"3-2",1 );
    OLED_ShowChar ( 0,2,"3-3<-",1 );
    OLED_ShowChar ( 0,4,"3-4",1 );
//	printf("3_3\r\n");
}
void FunSecondaryMenu_3_4 ( void ) {
    OLED_ShowChar ( 0,0,"3-3",1 );
    OLED_ShowChar ( 0,2,"3-4<-",1 );
    OLED_ShowChar ( 0,4,"3-1",1 );
//	printf("3_4\r\n");
}

void FunSecondaryMenu_4_1 ( void ) {
    OLED_ShowChar ( 0,0,"4-4",1 );
    OLED_ShowChar ( 0,2,"4-1<-",1 );
    OLED_ShowChar ( 0,4,"4-2",1 );
//	printf("4_1\r\n");
}
void FunSecondaryMenu_4_2 ( void ) {
    OLED_ShowChar ( 0,0,"4-1",1 );
    OLED_ShowChar ( 0,2,"4-2<-",1 );
    OLED_ShowChar ( 0,4,"4-3",1 );
//	printf("4_2\r\n");
}
void FunSecondaryMenu_4_3 ( void ) {
    OLED_ShowChar ( 0,0,"4-2",1 );
    OLED_ShowChar ( 0,2,"4-3<-",1 );
    OLED_ShowChar ( 0,4,"4-4",1 );
//	printf("4_3\r\n");
}
void FunSecondaryMenu_4_4 ( void ) {
    OLED_ShowChar ( 0,0,"4-3",1 );
    OLED_ShowChar ( 0,2,"4-4<-",1 );
    OLED_ShowChar ( 0,4,"4-1",1 );
//	printf("4_4\r\n");
}


///*其他的在中断服务函数中*/ //KEA芯片可用










