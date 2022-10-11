//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;
#define MAX 90
int sum = 8*8  ;	//总请求次数**********************************************************************
int value;	//有效点名次数
int flag1, flag2, flag3, flag4, flag5;
string cur;
struct stuMessage {//一门课中的学生信息
	string na = "";    //姓名
	int sno = 0;     //学号
	string sex = "";       //性别
	double GPA = 0;     //绩点
	int attend[20] = { 0 }; //考勤情况：0代表缺勤，1代表出勤
	double rate = 0;	//当前出勤率
	// int onTime;     //总的出勤次数--用于计算当前出勤率
	// int flag;       //当前是第几次课（迭代次数）
};
struct stuMessage curse1[MAX];	//定义为全局变量
struct stuMessage curse2[MAX];
struct stuMessage curse3[MAX];
struct stuMessage curse4[MAX];
struct stuMessage curse5[MAX];

/*目标：E=五门课程有效点名次数/总请求次数----最大化
	通过定义三个排序：1.上次考勤情况 2.当前出勤率 3.绩点
*/
//终端交互
void star(string cur);//开始
void openFile(string cur, struct stuMessage* curse, int flag);//读入考勤信息表
//排序1——绩点
void judge1(struct stuMessage* curse);
//排序2——出勤率
void judge2(struct stuMessage* curse, int flag);
//排序3——上次考勤
void judge3(struct stuMessage* curse, int flag);

string Utf8ToGbk(const char* src_str)		//UTF-8编码转为GBK编码，解决读取csv文件时出现乱码的问题
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}

void Stringsplit(string str, const const char split, vector<string>& res)		//split分割字符串函数
{
	istringstream iss(str);	// 输入流
	string token;			// 接收缓冲区
	while (getline(iss, token, split))	// 以split为分隔符
	{
		res.push_back(token);
	}
}

int main() {
	//读取要点名的课程名——选择文件的依据
	star(cur);
	/*double e = value * 1.0 / sum;
	printf("E = %.8f\n", e);*/
	return 0;
}

void star(string cur) {
	while (1) {
		printf("请输出要点名的课程(按q退出)：\n");
		cin >> cur;
		if (cur == "q") {    // 退出
			break;
		}
		if (cur == "1") openFile(cur, curse1, flag1);
		else if(cur == "2") openFile(cur, curse2, flag2);
		else if(cur == "3") openFile(cur, curse3, flag3);
		else if(cur == "4")openFile(cur, curse4, flag4);
		else if(cur == "5")openFile(cur, curse5, flag5);
	}
	return;
}

void openFile(string cur, struct stuMessage* curse, int flag) {
	//读取
	int i = 0, j = 0;
	if (cur == "1") {
		ifstream fin("d:\Class1.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "2") {
		ifstream fin("d:\Class2.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "3") {
		ifstream fin("d:\Class3.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "4") {
		ifstream fin("d:\Class4.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "5") {
		ifstream fin("d:\Class5.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	
	
	//计算**********************************************************************************
	for (flag; flag < 8; flag++) {
		if(flag==0)judge1(curse);
		if (flag != 0) {
			judge2(curse, flag);
			judge3(curse, flag);
		}
		/*for (i = 0; i < MAX; i++) {
			for (j = 0; j < 20; j++) {
				cout << curse[i].attend[j] << " ";
			}
			cout << endl;
		}
		cout << flag << "____________" << endl;*/
		for (i = 0; i < 8; i++) {
			if (curse[i].attend[flag] == 0)
				value++;
		}
	}
	/*for (i = 0; i < 8; i++) {
		if (curse[i].attend[19] == 0)
			value++;
	}*/
	double e = value * 1.0 / sum;
	printf("E = %.8f\n", e);
	cout << value << " " << sum << endl;
	value = 0;

	return;
}
//排序
void judge1(struct stuMessage* curse) {
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].GPA > curse[j + 1].GPA) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}
void judge2(struct stuMessage* curse, int flag) {
	if (flag == 0) {
		exit(0);
	}
	int va = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < flag; j++) {
			if (curse[i].attend[j] == 1) {
				va++;
			}
		}
		curse[i].rate = va * 1.0 / flag;
	}
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].rate > curse[j + 1].rate) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}
void judge3(struct stuMessage* curse, int flag) {
	if (flag == 0) {
		exit(0);
	}
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].attend[flag - 1] > curse[j + 1].attend[flag - 1]) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}