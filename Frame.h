/*
設定輸出(printf)

version 3
*/
#include <windows.h>

class Frame {
    private:
    
    public:
        //#include <windows.h>
        void SetTitle(const char *title){
            SetConsoleTitle(title); // (title)依編意器顯示錯誤 但可正常執行
        }

        void SetLocat(int x, int y){
            // COORD point = {x, y}; // COORD point; point.X = x, point.Y = y;
            COORD point;
            point.X = x, point.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
        }

        /*
        #include <windows.h>

        顏色請參照顏色對照表
        */
        void SetColor_Text(int color) {
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole,color);
        }

        /*
        #include <windows.h>

        注意:
        會覆蓋所有已設定的顏色
        無法配合SetColor_Text使用

        顏色表
        0 = 黑色        8 = 灰色
        1 = 藍色        9 = 淡藍色
        2 = 綠色        A = 淡綠色
        3 = 藍綠色      B = 淡藍綠色
        4 = 紅色        C = 淡紅色
        5 = 紫色        D = 淡紫色
        6 = 黃色        E = 淡黃色
        7 = 白色        F = 亮白色
        */
        void SetColor_background(char background, char text) {
            char c[] = {'c', 'o', 'l', 'o', 'r', ' ', background, text, '\0'};
            system(c);
        }

        //#include <windows.h>
        void Clear(){
            system("cls");
        }
};