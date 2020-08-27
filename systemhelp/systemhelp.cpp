#include "systemhelp.h"
#include <QFile>
#include   "windows.h " 
#include <shellapi.h>
#include<stdlib.h>

struct initunorder {
	int m;
	int n;
	int f;
};
systemhelp::systemhelp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(ui.btn1, SIGNAL(clicked()), this, SLOT(OnBtn1Clicked()));
	connect(ui.btn2, SIGNAL(clicked()), this, SLOT(OnBtn2Clicked()));
	connect(ui.btn3, SIGNAL(clicked()), this, SLOT(OnBtn3Clicked()));
	connect(ui.btn4, SIGNAL(clicked()), this, SLOT(OnBtn4Clicked()));
	connect(ui.btn5, SIGNAL(clicked()), this, SLOT(OnBtn5Clicked()));
	connect(ui.btn6, SIGNAL(clicked()), this, SLOT(OnBtn6Clicked()));
	connect(ui.btn7, SIGNAL(clicked()), this, SLOT(OnBtn7Clicked()));
	connect(ui.btn8, SIGNAL(clicked()), this, SLOT(OnBtn8Clicked()));
	connect(ui.btn9, SIGNAL(clicked()), this, SLOT(OnBtn9Clicked()));
	connect(ui.btn10, SIGNAL(clicked()), this, SLOT(OnBtn10Clicked()));
	connect(ui.btn11, SIGNAL(clicked()), this, SLOT(OnBtn11Clicked()));
	connect(ui.btn12, SIGNAL(clicked()), this, SLOT(OnBtn12Clicked()));
	connect(ui.btn13, SIGNAL(clicked()), this, SLOT(OnBtn13Clicked()));
	connect(ui.btn14, SIGNAL(clicked()), this, SLOT(OnBtn14Clicked()));
	connect(ui.btn15, SIGNAL(clicked()), this, SLOT(OnBtn15Clicked()));
	connect(ui.btn16, SIGNAL(clicked()), this, SLOT(OnBtn16Clicked()));
	connect(ui.btn17, SIGNAL(clicked()), this, SLOT(OnBtn17Clicked()));
	connect(ui.btn18, SIGNAL(clicked()), this, SLOT(OnBtn18Clicked()));
	connect(ui.btn19, SIGNAL(clicked()), this, SLOT(OnBtn19Clicked()));
	connect(ui.btn20, SIGNAL(clicked()), this, SLOT(OnBtn20Clicked()));
	connect(ui.btn21, SIGNAL(clicked()), this, SLOT(OnBtn21Clicked()));
	ui.btn19->hide();
	ui.btn20->hide();
	ui.btn21->hide();
}


void systemhelp::OnBtn1Clicked() {
	WinExec("cmd.exe /c wscui.cpl", SW_HIDE);
	//system("wscui.cpl");//安全和维护
}
void systemhelp::OnBtn2Clicked() {
	WinExec("cmd.exe /c sysdm.cpl", SW_HIDE);
	//system("sysdm.cpl"); //系统属性
}
void systemhelp::OnBtn3Clicked() {
	WinExec("cmd.exe /c intl.cpl", SW_HIDE);
	//system("intl.cpl");// - 区域
}
void systemhelp::OnBtn4Clicked() {
	WinExec("cmd.exe /c main.cpl", SW_HIDE);
	//system("main.cpl");// - 鼠标 属性
}
void systemhelp::OnBtn5Clicked() {
	WinExec("cmd.exe /c desk.cpl", SW_HIDE);
	//system("desk.cpl");// - 显示 设置
}
void systemhelp::OnBtn6Clicked() {
	WinExec("cmd.exe /c bthprops.cpl", SW_HIDE);
	//system("bthprops.cpl"); //（Bluetooth Control Panel Applet.蓝牙控制面板程序，本机没有安装蓝牙，不能打开）
}
void systemhelp::OnBtn7Clicked() {
	WinExec("cmd.exe /c mmsys.cpl", SW_HIDE);
	//system("mmsys.cpl");// - 声音
}
void systemhelp::OnBtn8Clicked() {
	WinExec("cmd.exe /c powercfg.cpl", SW_HIDE);
	//system("powercfg.cpl");// - 电源选项
}
void systemhelp::OnBtn9Clicked() {
	WinExec("cmd.exe /c sapi.cpl", SW_HIDE);
	//system("sapi.cpl");// - 语音属性
}
void systemhelp::OnBtn10Clicked() {
	WinExec("cmd.exe /c hdwwiz.cpl", SW_HIDE);
	//system("hdwwiz.cpl");// - 设备管理器
}
void systemhelp::OnBtn11Clicked() {
	WinExec("cmd.exe /c irprops.cpl", SW_HIDE);
	//system("irprops.cpl");// - 红外线
}
void systemhelp::OnBtn12Clicked() {
	WinExec("cmd.exe /c ncpa.cpl", SW_HIDE);
	//system("ncpa.cpl");// - 网络连接
}
void systemhelp::OnBtn13Clicked() {
	WinExec("cmd.exe /c joy.cpl", SW_HIDE);
	//system("joy.cpl");// - 游戏控制器
}
void systemhelp::OnBtn14Clicked() {
	WinExec("cmd.exe /c TabletPC.cpl", SW_HIDE);
	//system("TabletPC.cpl");// - 笔和触摸（台式机不可用）
}
void systemhelp::OnBtn15Clicked() {
	WinExec("cmd.exe /c appwiz.cpl", SW_HIDE);
	//system("appwiz.cpl");// - 程序和功能
	
}
void systemhelp::OnBtn16Clicked() {
	WinExec("cmd.exe /c timedate.cpl", SW_HIDE);
	//system("timedate.cpl");//日期和时间
}
void systemhelp::OnBtn17Clicked() {
	WinExec("cmd.exe /c inetcpl.cpl", SW_HIDE);
	//system("inetcpl.cpl");//Internet选项
}
void systemhelp::OnBtn18Clicked() {
	WinExec("cmd.exe /c telephon.cpl", SW_HIDE);
	//system("telephon.cpl");// - 区域位置信息
}
void systemhelp::OnBtn19Clicked() {
	WinExec("cmd.exe /c Firewall.cpl", SW_HIDE);
	//system("Firewall.cpl");// - Windows防火墙
}
void systemhelp::OnBtn20Clicked() {
	WinExec("cmd.exe /c  igfxCPL.cpl", SW_HIDE);
	//system("igfxCPL.cpl");// - 英特尔核芯显卡控制面板
}
void systemhelp::OnBtn21Clicked() {
	WinExec("cmd.exe /c RTSnMg64.cpl", SW_HIDE);
	
	//system("RTSnMg64.cpl");// - Realtek高清晰音频管理器
}