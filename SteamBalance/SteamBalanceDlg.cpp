
// SteamBalanceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SteamBalance.h"
#include "SteamBalanceDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSteamBalanceDlg �Ի���



CSteamBalanceDlg::CSteamBalanceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STEAMBALANCE_DIALOG, pParent)
	, m_steamprice(0)
	, m_price(0)
	, m_chargeper(0)
	, mc_oneprice(0)
	, mc_allprice(0)
	, mc_onecharge(0)
	, mc_onediffprice(0)
	, mc_num(0)
	, m_getprice(0)
	, mc_allpay(0)
	, mc_allcharge(0)
	, mc_alldiffprice(0)
	, mc_discount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSteamBalanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_steamprice);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_chargeper);
	DDX_Text(pDX, IDC_EDIT4, mc_oneprice);
	DDX_Text(pDX, IDC_EDIT5, mc_allprice);
	DDX_Text(pDX, IDC_EDIT11, mc_onecharge);
	DDX_Text(pDX, IDC_EDIT6, mc_onediffprice);
	DDX_Text(pDX, IDC_EDIT8, mc_num);
	DDX_Text(pDX, IDC_EDIT13, m_getprice);
	DDX_Text(pDX, IDC_EDIT9, mc_allpay);
	DDX_Text(pDX, IDC_EDIT12, mc_allcharge);
	DDX_Text(pDX, IDC_EDIT7, mc_alldiffprice);
	DDX_Text(pDX, IDC_EDIT10, mc_discount);
}

BEGIN_MESSAGE_MAP(CSteamBalanceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSteamBalanceDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSteamBalanceDlg ��Ϣ�������

BOOL CSteamBalanceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_chargeper = 0.13043478 * 100;
	UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSteamBalanceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSteamBalanceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSteamBalanceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSteamBalanceDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_steamprice == 0 || m_price == 0 || m_getprice == 0)
	{
		MessageBox(_T("��������Ч���ݣ�"), _T("����"), MB_ICONWARNING);
		return;
	}
	
	mc_oneprice = m_steamprice*(1 - m_chargeper / 100);
	mc_onecharge = m_steamprice*m_chargeper / 100;
	mc_onediffprice = mc_oneprice - m_price;
	mc_num = (int)(m_getprice / mc_oneprice) + 1;
	mc_allprice = mc_num*mc_oneprice;
	mc_allcharge = mc_onecharge*mc_num;
	mc_alldiffprice = mc_onediffprice*mc_num;
	mc_allpay = m_price*mc_num;
	mc_discount = mc_allpay / mc_allprice;
	mc_discount *= 100;
	UpdateData(FALSE);
}
