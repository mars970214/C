#include <time.h>

#include "Show.cpp"
#define Show

int main(){
    FStart();
    // 獲取現在時間 方便設置遊戲更新時間
    time_t now = time(0);
    // 遊戲更新
    while(true){
        if (time(0) - now > 1){
            load(); // 更新

            now = time(0);
        }
    }
    return 0;
}