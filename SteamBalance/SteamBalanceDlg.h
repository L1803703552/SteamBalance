
// SteamBalanceDlg.h : 头文件
//

#pragma once

#include <list>
#include "afxwin.h"
#include "afxcmn.h"

using namespace std;

struct Info {
	string name;//饰品名称
	int num;//数量
	double ptprice;//平台价格
	double sqprice;//社区价格
	double discount;//折扣
	double dqpay;//倒出余额
	double hfpay;//总花费
};
// CSteamBalanceDlg 对话框
class CSteamBalanceDlg : public CDialogEx
{
// 构造
public:
	CSteamBalanceDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STEAMBALANCE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// Steam市场价格
	double m_steamprice;
	// 平台价格
	double m_price;
	// 手续费百分比
	double m_chargeper;
	// 除去手续费单价
	double mc_oneprice;
	// 除去手续费总价
	double mc_allprice;
	// 单个手续费
	double mc_onecharge;
	// 单个差价
	double mc_onediffprice;
	// 总购买需要
	int mc_num;
	// 倒出金额
	double m_getprice;
	// 共花费
	double mc_allpay;
	// 总手续费
	double mc_allcharge;
	// 总差价
	double mc_alldiffprice;
	// 倒余额折扣
	double mc_discount;
	CToolTipCtrl m_ctrlTT;
	list<Info> inf;

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	// 饰品名称
	CString m_name;
	CListCtrl m_list;
};
