#ifndef _MENU_1_h
#define _MENU_1_h

struct ShowMenu{
	
  void (*FunNow)(void);//函数指针
	
  struct ShowMenu *Left;//结构体指针
	struct ShowMenu *Up;
	struct ShowMenu *Right;
	struct ShowMenu *Down;
	
};


extern struct ShowMenu MainMenu_1,MainMenu_2,MainMenu_3,MainMenu_4,*FunShowMenu;
extern struct ShowMenu SecondaryMenu_1_1,SecondaryMenu_1_2,SecondaryMenu_1_3,SecondaryMenu_1_4;
extern struct ShowMenu SecondaryMenu_2_1,SecondaryMenu_2_2,SecondaryMenu_2_3,SecondaryMenu_2_4;
extern struct ShowMenu SecondaryMenu_3_1,SecondaryMenu_3_2,SecondaryMenu_3_3,SecondaryMenu_3_4;
extern struct ShowMenu SecondaryMenu_4_1,SecondaryMenu_4_2,SecondaryMenu_4_3,SecondaryMenu_4_4;


void StructInit(void);
void AddUp_Down(struct ShowMenu *pointer,...);


void FunMainMenu_1(void);
void FunMainMenu_2(void);
void FunMainMenu_3(void);
void FunMainMenu_4(void);

void FunSecondaryMenu_1_1(void);
void FunSecondaryMenu_1_2(void);
void FunSecondaryMenu_1_3(void);
void FunSecondaryMenu_1_4(void);

void FunSecondaryMenu_2_1(void);
void FunSecondaryMenu_2_2(void);
void FunSecondaryMenu_2_3(void);
void FunSecondaryMenu_2_4(void);

void FunSecondaryMenu_3_1(void);
void FunSecondaryMenu_3_2(void);
void FunSecondaryMenu_3_3(void);
void FunSecondaryMenu_3_4(void);

void FunSecondaryMenu_4_1(void);
void FunSecondaryMenu_4_2(void);
void FunSecondaryMenu_4_3(void);
void FunSecondaryMenu_4_4(void);







#endif




