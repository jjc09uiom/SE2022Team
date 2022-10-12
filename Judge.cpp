#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;
#define MAX 90
int sum = 8*20*5 ;	//���������**********************************************************************
int value;			//��Ч��������
int flag;			//��������
string cur;			//�γ������
struct stuMessage {//һ�ſ��е�ѧ����Ϣ
	string na = "";    //����
	int sno = 0;		//ѧ��
	string sex = "";    //�Ա�
	double GPA = 0;     //����
	int attend[20] = { 0 }; //���������0����ȱ�ڣ�1�������
	double rate = 0;	//��ǰ������
	double factor=0;		//�������ӣ�ԽС����Խ����ȱ�ڣ�
	/*factor = 0.8*GPA + rate + attend[flag-1] */
	// int onTime;     //�ܵĳ��ڴ���--���ڼ��㵱ǰ������
	// int flag;       //��ǰ�ǵڼ��οΣ�����������
};
struct stuMessage curse1[MAX];
struct stuMessage curse2[MAX];
struct stuMessage curse3[MAX];
struct stuMessage curse4[MAX];
struct stuMessage curse5[MAX];

/*Ŀ�꣺E=���ſγ���Ч��������/���������----���
	ͨ��������������1.�ϴο������ 2.��ǰ������ 3.����
*/
//�ն˽���
void star(string cur);//��ʼ
//���뿼����Ϣ��
void openFile(string cur, struct stuMessage* curse);
//����1��������
void judge1(struct stuMessage* curse);
//����2����������
void judge2(struct stuMessage* curse, int flag);
//����3�����ϴο���
void judge3(struct stuMessage* curse, int flag);
//����4������������
void judge4(struct stuMessage* curse, int flag);
//UTF-8����תΪGBK���룬�����ȡcsv�ļ�ʱ�������������
string Utf8ToGbk(const char* src_str);
//GBK����תΪUTF-8���룬��������㷽��ʱ����
string GbkToUtf8(const char* src_str);
//split�ָ��ַ�������
void Stringsplit(string str, const const char split, vector<string>& res);
//���Eֵ
void outE();
//�����㷽��
void outPlan(struct stuMessage curse,ofstream ofs);
int main() {
	//��ȡҪ�����Ŀγ�������ѡ���ļ�������
	star(cur);
	outE();
	return 0;
}

void star(string cur) {
	while (1) {
		printf("�����Ҫ�����Ŀγ�(��q�˳�)��\n");
		cin >> cur;
		if (cur == "q")     // �˳�
			break;
		else if(cur == "1") openFile(cur, curse1);
		else if(cur == "2") openFile(cur, curse2);
		else if(cur == "3") openFile(cur, curse3);
		else if(cur == "4") openFile(cur, curse4);
		else if(cur == "5") openFile(cur, curse5);
	}
	return;
}

void openFile(string cur, struct stuMessage* curse) {
	//��ȡ
	int i = 0, j = 0,value1=0;
	if (cur == "1") {
		ifstream fin("d:\Class1.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);		//����ַ���
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) 
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			i++;
		}
		fin.close();
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
		fin.close();
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
		fin.close();
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
		fin.close();
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
		fin.close();
	}
	
	//����**********************************************************************************
	for (flag = 0; flag < 20; flag++) {
		judge4(curse, flag);
	//���
		ofstream ofs;
		ofs.open("d:\Plan.txt", ios::app);
		ofs << "�γ̣�"<<cur<<"\t\t\t�ڴΣ�" << flag+1 << endl;

		for (i = 0; i < 8; i++) {		
			ofs << curse[i].na << " " << curse[i].sno << endl;
			if (curse[i].attend[flag] == 0)
				value++,value1++;
		}
		ofs << "����������������������������" << endl;
		ofs.close();
	}
	double e = value1 * 1.0 /sum*5;
	printf("E = %.8f\n", e);
	value1 = 0;
	return;
}
//����
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
void judge4(struct stuMessage *curse, int flag) { /*factor = 0.8*GPA + rate + attend[flag-1] */
	
	if (flag == 0) {
		for (int i = 0; i < MAX; i++) 
			curse[i].factor = curse[i].GPA;
		
	}
	//���������rate
	else {
		int va = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < flag; j++) {
				if (curse[i].attend[j] == 1) {
					va++;
				}
			}
			curse[i].rate = va * 1.0 / flag;
		}
	//����factor
		for (int i = 0; i < MAX; i++) {//2/0.45/0.2-0.58875   3/0.45/0.2-0.59
			curse[i].factor = 3 * curse[i].GPA +6 * curse[i].rate + 1 * curse[i].attend[flag - 1];
		}

	}
	
	struct stuMessage x;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 0; j < MAX - i - 1; j++) {
			if (curse[j].factor > curse[j + 1].factor) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}
void outE() {
	double e = value * 1.0 / sum;
	printf("E = %.8f\n", e);
	cout << value << " " << sum << endl;
	return;
}
void outPlan(struct stuMessage curse,ofstream ofs) {
	
}
string Utf8ToGbk(const char* src_str)
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
string GbkToUtf8(const char* src_str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}
void Stringsplit(string str, const const char split, vector<string>& res)
{
	istringstream iss(str);	// ������
	string token;			// ���ջ�����
	while (getline(iss, token, split))	// ��splitΪ�ָ���
	{
		res.push_back(token);
	}
}