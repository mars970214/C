/*
建立物件的模板

version 1
*/
#ifndef Item
#define Item

#include <iostream>

class item {
private:
    bool now;   // 方便刪除該物件
    int locat[2];   // 顯示位置
    int color = 255;    // 顯示顏色 顏色參照"顏色代號表.png"    // 白底白字
    std::string show = "  ";    // 預設顯示為方格
    int type = -1;  // 儲存物件資訊 ex:是否可以穿越
public:
    item(int x, int y, int type);
    void SetLocat(int x, int y);
    void SetColor(int color);
    void SetShow(const char show[]);
    void Delete();

    int* GetLocat();
    int GetColor();
    int GetType();
    const char* GetShow();
    bool Alive();
};

item::item(int x, int y, int type){
    now = true;
    locat[0] = x;
    locat[1] = y;
    if (type > 0)
        item::type = type;
}

void item::SetLocat(int x, int y){
    locat[0] = x;
    locat[1] = y;
}

void item::SetColor(int color){
    item::color = color;
}

void item::SetShow(const char *show){
    item::show = show;
}

void item::Delete(){
    now = false;
}

int* item::GetLocat(){
    return locat;
}

int item::GetColor(){
    return color;
}

int item::GetType(){
    return type;
}

const char* item::GetShow(){
    return show.c_str();
}

bool item::Alive(){
    return now;
}

#endif