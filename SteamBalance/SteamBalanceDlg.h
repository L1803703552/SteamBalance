
// SteamBalanceDlg.h : ͷ�ļ�
//

#pragma once

#include <list>
#include "afxwin.h"
#include "afxcmn.h"

using namespace std;

struct Info {
	string name;//��Ʒ����
	int num;//����
	double ptprice;//ƽ̨�۸�
	double sqprice;//�����۸�
	double discount;//�ۿ�
	double dqpay;//�������
	double hfpay;//�ܻ���
};
// CSteamBalanceDlg �Ի���
class CSteamBalanceDlg : public CDialogEx
{
// ����
public:
	CSteamBalanceDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STEAMBALANCE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// Steam�г��۸�
	double m_steamprice;
	// ƽ̨�۸�
	double m_price;
	// �����Ѱٷֱ�
	double m_chargeper;
	// ��ȥ�����ѵ���
	double mc_oneprice;
	// ��ȥ�������ܼ�
	double mc_allprice;
	// ����������
	double mc_onecharge;
	// �������
	double mc_onediffprice;
	// �ܹ�����Ҫ
	int mc_num;
	// �������
	double m_getprice;
	// ������
	double mc_allpay;
	// ��������
	double mc_allcharge;
	// �ܲ��
	double mc_alldiffprice;
	// ������ۿ�
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
	// ��Ʒ����
	CString m_name;
	CListCtrl m_list;
};
