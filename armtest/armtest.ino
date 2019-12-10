#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMServo wmServo_2(4,2); //将2号口设置为二次开发接口  // RX, TX

void setup(){
    delay(500); //开启时延时500毫秒后开始工作
    // wmServo_2.runActionGroup(21,1);
             wmServo_2.runActionGroup(0,1);

}

void loop(){    
 wmServo_2.runActionGroup(0,1);

delay(5000);
}
