// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       mc_project.ino
    Created:	2018/5/30 18:11:23
    Author:     LAPTOP-AL5LKVV4\lenovo
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files

//舵机初始化
int servoPin1 = 9; //舵机1连接引脚
int servoPin2 = 10;
int servoPin3 = 11;

int spd = 3; //舵机转动速度；主要是根据运行模块后delay的时间控制，最小为1
int pos = 0;      //定义角度

void gofirst(int servoPin) {
	int maxt = 2500; //舵机满舵方波时长；
	int mint = 500;  //舵机归零方波时长；

	for (int i = 180; i >= 0; --i) {
		digitalWrite(servoPin, HIGH);//向数据引脚输入高电位；
		delayMicroseconds(mint);//停留dltime的时间，制造方波-凸出部分；
		digitalWrite(servoPin, LOW);//数据引脚转为低电位，制造方波-凹下部分；
		delayMicroseconds(maxt - mint);//完成方波；
	}
}
//舵机的运行模块（需要输入2个参数：需要转动的角度；数据引脚位置）
void go(int ang, int servoPin) {
	int maxt = 2500; //舵机满舵方波时长；
	int mint = 500;  //舵机归零方波时长；

	if (ang >= 0 & ang <= 180) {
		//判断输入的角度必须在0-180度的区间，否则置零；
		ang = ang;
	}
	else {
		ang = 0;
	}

	if (ang >= pos) {
		for (int i = pos; i <= ang; ++i) {
			int dltime = map(ang, 0, 180, mint, maxt);//将角度规则化为舵机转动的方波时长；
			digitalWrite(servoPin, HIGH);//向数据引脚输入高电位；
			delayMicroseconds(dltime);//停留dltime的时间，制造方波-凸出部分；
			digitalWrite(servoPin, LOW);//数据引脚转为低电位，制造方波-凹下部分；
			delayMicroseconds(maxt - dltime);//！！！这个是关键，完成方波；
			delay(spd);
			pos = ang;
		}
	}
	else if (ang <= pos) {
		for (int i = pos; i >= ang; --i) {
			int dltime = map(ang, 0, 180, mint, maxt);//将角度规则化为舵机转动的方波时长；
			digitalWrite(servoPin, HIGH);//向数据引脚输入高电位；
			delayMicroseconds(dltime);//停留dltime的时间，制造方波-凸出部分；
			digitalWrite(servoPin, LOW);//数据引脚转为低电位，制造方波-凹下部分；
			delayMicroseconds(maxt - dltime);//！！！这个是关键，完成方波；
			delay(spd);
			pos = ang;
		}
	}
}


// The setup() function runs once each time the micro-controller starts
void setup()
{
	//开启串口，设置波特率
	Serial.begin(9600);
	Serial.setTimeout(1000); //串口超时 1000 毫秒
	//开启arduino端口，与舵机连接
	pinMode(servoPin1, OUTPUT);  //开启舵机端口
	pinMode(servoPin2, OUTPUT);
	pinMode(servoPin3, OUTPUT);
	gofirst(servoPin1);//初始化，将舵机调至0位
	gofirst(servoPin2);
	gofirst(servoPin3);
}

// Add the main program code into the continuous loop() function
void loop()
{
	char var = '/';
	//接受python串口指令，发送至arduino串口，控制舵机
	var = Serial.read(); 
	//判断
	
}
