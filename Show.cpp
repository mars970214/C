/*
顯示位置設定
和
執行顯示

version 1
*/

#ifndef Show
#define Show

#include <stdio.h>

#include "item.cpp"
#define Item

#include "Frame.h"
Frame frame;

#include <queue>
std::queue<item> items; // 儲存所有方塊

void load(){    // 顯示畫面
    frame.Clear();  // 清空畫面

    // 獲取玩家位置
    int player_locat[2];
    for (int i = 0; i < items.size(); i++){
        if (items.front().GetType() == 120){    // 如果是玩家type
            player_locat[0] = items.front().GetLocat()[0];
            player_locat[1] = items.front().GetLocat()[1];

            break;
        }

        items.push(items.front());  // 下面一位
        items.pop();
    }

    // 偵測方塊位置上方是否為玩家 (需優化-優化:紀錄方塊位置 直接玩家偵測下方是否有方塊)
    bool fly = true;    
    for (int i = 0; i < items.size(); i++){
        if (items.front().GetLocat()[0] == player_locat[0]  // x軸相同
            && items.front().GetLocat()[1] == player_locat[1] +1    // 玩家下方是方塊
            && items.front().GetType()%10 == 0){    // 方塊不可穿越
            fly = false;    // 否定飛行

            break;
        }

        items.push(items.front());
        items.pop();
    }
    if(fly) // 如果飛行 下墜
        items.front().SetLocat(items.front().GetLocat()[0], items.front().GetLocat()[1] +1);


    // 顯示畫面 (優化:frame Clear抓過來)
    for (int i = 0; i < items.size(); i++){
        frame.SetLocat(items.front().GetLocat()[0], items.front().GetLocat()[1]);   // 設定位置
        frame.SetColor_Text(items.front().GetColor());  // 著色
        printf("%s", items.front().GetShow());  // 顯示

        items.push(items.front());
        items.pop();
    }
}


// type 1 組別 可否穿越
void FStart(){
    // 設定"邊框"
    #define frame_size 20    // 設置邊框大小
    int type = 100; // 設置邊框type
    for (int i = 0; i < frame_size; i++) {
        items.push(item(i*2, 0, type)); // 上邊框
        items.push(item(i*2, frame_size-1, type));  // 下邊框

        items.push(item(0, i, type));   // 左邊框
        items.push(item(frame_size*2, i, type));    // 右邊框
    }

    // 設定"分數:"
    items.push(item(2, 1, 111));
    items.back().SetShow("分數:");
    items.back().SetColor(15);  // 黑底白字

    // 設定"玩家"
    items.push(item(frame_size, frame_size -7, 120));
    items.back().SetColor(174); // 綠底黃字
}


#endif