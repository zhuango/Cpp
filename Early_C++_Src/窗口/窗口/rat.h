void DrawP(HDC hdc, int dir, int shape, int color, int x, int y);
void Draw(HDC, int, int, int);
void DrawWindow(HDC hdc);
void Init(void);
BOOL Check(int dir,int shape, int Px,int Py);
int  SaveRectangle(HDC hdc, HWND hwnd, int dir, int shape, int x, int y);
void LoadRectangle(HDC hdc);
BOOL GameOver(void);

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

const POINT Rect[7][4][4]=
{
	{ 1,1,2,1,2,0,3,0, // ＿|ˉ形
	  1,0,1,1,2,1,2,2, // Ν形
	  1,1,2,1,2,0,3,0, 
	  1,0,1,1,2,1,2,2, },              	
	
	{ 1,0,2,0,2,1,3,1, // Ζ形
	  1,1,2,1,2,0,1,2, //
	  1,0,2,0,2,1,3,1,                  
	  1,1,2,1,2,0,1,2, },
	
	{ 1,0,2,0,3,0,4,0, // ━形
	  2,2,2,0,2,1,2,3, // ┃形
	  1,0,2,0,3,0,4,0,
	  2,2,2,0,2,1,2,3, },
	
	{ 1,0,1,1,2,0,2,1, //田形
	  1,0,1,1,2,0,2,1,
	  1,0,1,1,2,0,2,1,
	  1,0,1,1,2,0,2,1 },
	
	{ 1,0,2,0,3,0,3,1,  //┑
	  2,0,2,1,2,2,1,2, //┚
	  1,0,1,1,2,1,3,1, //┕
	  1,0,2,0,1,1,1,2 },//┎
	
	{ 1,0,1,1,2,0,3,0, //┍
	  1,0,2,0,2,1,2,2, //┒
	  1,1,2,1,3,0,3,1, // ┙
	  1,0,1,1,1,2,2,2}, //┖
	
	{ 1,0,2,0,2,1,3,0, // ┰
	  1,1,2,0,2,1,2,2, //┨
	  1,1,2,0,2,1,3,1, // ┸
	  1,0,1,1,1,2,2,1, }//┠
};