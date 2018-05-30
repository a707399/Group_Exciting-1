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

//�����ʼ��
int servoPin1 = 9; //���1��������
int servoPin2 = 10;
int servoPin3 = 11;

int spd = 3; //���ת���ٶȣ���Ҫ�Ǹ�������ģ���delay��ʱ����ƣ���СΪ1
int pos = 0;      //����Ƕ�

void gofirst(int servoPin) {
	int maxt = 2500; //������淽��ʱ����
	int mint = 500;  //������㷽��ʱ����

	for (int i = 180; i >= 0; --i) {
		digitalWrite(servoPin, HIGH);//��������������ߵ�λ��
		delayMicroseconds(mint);//ͣ��dltime��ʱ�䣬���췽��-͹�����֣�
		digitalWrite(servoPin, LOW);//��������תΪ�͵�λ�����췽��-���²��֣�
		delayMicroseconds(maxt - mint);//��ɷ�����
	}
}
//���������ģ�飨��Ҫ����2����������Ҫת���ĽǶȣ���������λ�ã�
void go(int ang, int servoPin) {
	int maxt = 2500; //������淽��ʱ����
	int mint = 500;  //������㷽��ʱ����

	if (ang >= 0 & ang <= 180) {
		//�ж�����ĽǶȱ�����0-180�ȵ����䣬�������㣻
		ang = ang;
	}
	else {
		ang = 0;
	}

	if (ang >= pos) {
		for (int i = pos; i <= ang; ++i) {
			int dltime = map(ang, 0, 180, mint, maxt);//���Ƕȹ���Ϊ���ת���ķ���ʱ����
			digitalWrite(servoPin, HIGH);//��������������ߵ�λ��
			delayMicroseconds(dltime);//ͣ��dltime��ʱ�䣬���췽��-͹�����֣�
			digitalWrite(servoPin, LOW);//��������תΪ�͵�λ�����췽��-���²��֣�
			delayMicroseconds(maxt - dltime);//����������ǹؼ�����ɷ�����
			delay(spd);
			pos = ang;
		}
	}
	else if (ang <= pos) {
		for (int i = pos; i >= ang; --i) {
			int dltime = map(ang, 0, 180, mint, maxt);//���Ƕȹ���Ϊ���ת���ķ���ʱ����
			digitalWrite(servoPin, HIGH);//��������������ߵ�λ��
			delayMicroseconds(dltime);//ͣ��dltime��ʱ�䣬���췽��-͹�����֣�
			digitalWrite(servoPin, LOW);//��������תΪ�͵�λ�����췽��-���²��֣�
			delayMicroseconds(maxt - dltime);//����������ǹؼ�����ɷ�����
			delay(spd);
			pos = ang;
		}
	}
}


// The setup() function runs once each time the micro-controller starts
void setup()
{
	//�������ڣ����ò�����
	Serial.begin(9600);
	Serial.setTimeout(1000); //���ڳ�ʱ 1000 ����
	//����arduino�˿ڣ���������
	pinMode(servoPin1, OUTPUT);  //��������˿�
	pinMode(servoPin2, OUTPUT);
	pinMode(servoPin3, OUTPUT);
	gofirst(servoPin1);//��ʼ�������������0λ
	gofirst(servoPin2);
	gofirst(servoPin3);
}

// Add the main program code into the continuous loop() function
void loop()
{
	char var = '/';
	//����python����ָ�������arduino���ڣ����ƶ��
	var = Serial.read(); 
	//�ж�
	
}
